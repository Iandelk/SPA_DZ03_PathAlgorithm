#include "PathAlgoritam.h"
#include<stack>
#include<iostream>
#include<set>
#include <SFML/Graphics.hpp>
using namespace std;


typedef pair<int, int> Pair;

typedef pair<int, pair<int, int>> pPair;

// validna?
bool PathAlgoritam::isValid(int row, int col)
{
	
	return (row >= 0) && (row < VELICINA) &&
		(col >= 0) && (col < VELICINA);
}

// prazna?
bool PathAlgoritam::isUnBlocked(int grid[][VELICINA], int row, int col)
{
	if (grid[row][col] == 0 || grid[row][col] == 3 || grid[row][col] == 5 )
		return (true);
	else
		return (false);
}

// je li dest?
bool PathAlgoritam::isDestination(int row, int col, Pair dest)
{
	if (row == dest.first && col == dest.second)
		return (true);
	else
		return (false);
}

// izracun relativne putanje do odredista
int PathAlgoritam::calculateHValue(int row, int col, Pair dest)
{

	return (abs(row - dest.first) + abs(col - dest.second));
}

// put od src do dest
void PathAlgoritam::tracePath(sf::Clock clock, sf::RenderWindow& window,int grid[][VELICINA],cell cellDetails[][VELICINA], Pair dest)
{
	int row = dest.first;
	int col = dest.second;

	stack<Pair> Path;


	while (!(cellDetails[row][col].parent_i == row
		&& cellDetails[row][col].parent_j == col))
	{
		Path.push(make_pair(row, col));
		int temp_row = cellDetails[row][col].parent_i;
		int temp_col = cellDetails[row][col].parent_j;
		row = temp_row;
		col = temp_col;
	}
	Path.push(make_pair(row, col));
	
		while (!Path.empty())
		{
			pair<int, int> p = Path.top();
			PrikazLabirinta(Path.size(),clock, window, grid, p.first, p.second);
			Path.pop();
		
	}
	return;
}

// A* za najkraci put

void PathAlgoritam::aStarSearch(sf::Clock clock, sf::RenderWindow& window,int grid[][VELICINA], Pair src, Pair dest)
{
	if (isValid(src.first, src.second) == false)
	{
		return;
	}

	if (isValid(dest.first, dest.second) == false)
	{
		return;
	}

	if (isUnBlocked(grid, src.first, src.second) == false ||
		isUnBlocked(grid, dest.first, dest.second) == false)
	{
		return;
	}

	if (isDestination(src.first, src.second, dest) == true)
	{
		return;
	}

	//lista vec provjerenih
	bool closedList[VELICINA][VELICINA];
	memset(closedList, false, sizeof(closedList));

	cell cellDetails[VELICINA][VELICINA];

	int i, j;

	for (i = 0; i<VELICINA; i++)
	{
		for (j = 0; j<VELICINA; j++)
		{
			cellDetails[i][j].f = INT_MAX;
			cellDetails[i][j].g = INT_MAX;
			cellDetails[i][j].h = INT_MAX;
			cellDetails[i][j].parent_i = -1;
			cellDetails[i][j].parent_j = -1;
		}
	}

	i = src.first, j = src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent_i = i;
	cellDetails[i][j].parent_j = j;

// lista jos ne provjerenih
	set<pPair> openList;


	openList.insert(make_pair(0.0, make_pair(i, j)));

	bool foundDest = false;

	while (!openList.empty())
	{
		pPair p = *openList.begin();

		openList.erase(openList.begin());

		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;

		
		int gNew, hNew, fNew;


		if (isValid(i - 1, j) == true)
		{
			
			if (isDestination(i - 1, j, dest) == true)
			{
				
				cellDetails[i - 1][j].parent_i = i;
				cellDetails[i - 1][j].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(clock, window, grid,cellDetails, dest);
				foundDest = true;
				return;
			}
			
			else if (closedList[i - 1][j] == false &&
				isUnBlocked(grid, i - 1, j) == true)
			{
				gNew = cellDetails[i][j].g + 1;
				hNew = calculateHValue(i - 1, j, dest);
				fNew = gNew + hNew;


				if (cellDetails[i - 1][j].f == INT_MAX ||
					cellDetails[i - 1][j].f > fNew)
				{
					openList.insert(make_pair(fNew,
						make_pair(i - 1, j)));

					cellDetails[i - 1][j].f = fNew;
					cellDetails[i - 1][j].g = gNew;
					cellDetails[i - 1][j].h = hNew;
					cellDetails[i - 1][j].parent_i = i;
					cellDetails[i - 1][j].parent_j = j;
				}
			}
		}

		if (isValid(i + 1, j) == true)
		{
		
			if (isDestination(i + 1, j, dest) == true)
			{
				
				cellDetails[i + 1][j].parent_i = i;
				cellDetails[i + 1][j].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(clock,window, grid,cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (closedList[i + 1][j] == false &&
				isUnBlocked(grid, i + 1, j) == true)
			{
				gNew = cellDetails[i][j].g + 1;
				hNew = calculateHValue(i + 1, j, dest);
				fNew = gNew + hNew;

				
				if (cellDetails[i + 1][j].f == INT_MAX ||
					cellDetails[i + 1][j].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i + 1, j)));

					cellDetails[i + 1][j].f = fNew;
					cellDetails[i + 1][j].g = gNew;
					cellDetails[i + 1][j].h = hNew;
					cellDetails[i + 1][j].parent_i = i;
					cellDetails[i + 1][j].parent_j = j;
				}
			}
		}

		if (isValid(i, j + 1) == true)
		{
			if (isDestination(i, j + 1, dest) == true)
			{
				cellDetails[i][j + 1].parent_i = i;
				cellDetails[i][j + 1].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(clock,window, grid,cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (closedList[i][j + 1] == false &&
				isUnBlocked(grid, i, j + 1) == true)
			{
				gNew = cellDetails[i][j].g + 1;
				hNew = calculateHValue(i, j + 1, dest);
				fNew = gNew + hNew;

				if (cellDetails[i][j + 1].f == INT_MAX ||
					cellDetails[i][j + 1].f > fNew)
				{
					openList.insert(make_pair(fNew,
						make_pair(i, j + 1)));

					cellDetails[i][j + 1].f = fNew;
					cellDetails[i][j + 1].g = gNew;
					cellDetails[i][j + 1].h = hNew;
					cellDetails[i][j + 1].parent_i = i;
					cellDetails[i][j + 1].parent_j = j;
				}
			}
		}

		if (isValid(i, j - 1) == true)
		{
			if (isDestination(i, j - 1, dest) == true)
			{
				cellDetails[i][j - 1].parent_i = i;
				cellDetails[i][j - 1].parent_j = j;
				printf("The destination cell is found\n");
				tracePath(clock,window, grid,cellDetails, dest);
				foundDest = true;
				return;
			}

			else if (closedList[i][j - 1] == false &&
				isUnBlocked(grid, i, j - 1) == true)
			{
				gNew = cellDetails[i][j].g + 1;
				hNew = calculateHValue(i, j - 1, dest);
				fNew = gNew + hNew;

				if (cellDetails[i][j - 1].f == INT_MAX ||
					cellDetails[i][j - 1].f > fNew)
				{
					openList.insert(make_pair(fNew,
						make_pair(i, j - 1)));

					cellDetails[i][j - 1].f = fNew;
					cellDetails[i][j - 1].g = gNew;
					cellDetails[i][j - 1].h = hNew;
					cellDetails[i][j - 1].parent_i = i;
					cellDetails[i][j - 1].parent_j = j;
				}
			}
		}
	}
	if (foundDest == false)
		printf("Failed to find the Destination Cell\n");

	return;
}



PathAlgoritam::PathAlgoritam(sf::Clock clock, sf::RenderWindow& window,int labirint[][VELICINA], int src_x, int src_y, int dest_x, int dest_y)
{

	Pair src = make_pair(src_x, src_y);

	Pair dest = make_pair(dest_x, dest_y);

	aStarSearch(clock, window, labirint, src, dest);
}


