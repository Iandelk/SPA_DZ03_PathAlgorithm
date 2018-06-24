#pragma once
#include <iostream>
#include<vector>
#include "PrikazLabirinta.h"
#include <SFML/Graphics.hpp>

using namespace std;

	typedef pair<int, int> Pair;

	typedef pair<int, pair<int, int>> pPair;

	static const int VELICINA = 35;

class PathAlgoritam
{
public:
	struct koord
	{
		int x;
		int y;

	};
	PathAlgoritam(sf::Clock clock, sf::RenderWindow& window, int grid[][VELICINA], int src_x, int src_y, int dest_x, int dest_y);
private:
	
	struct cell
	{
	
		char parent_i;
		char parent_j;
		// f = g + h
		int f, g, h;
	};
	
	bool isValid(int row, int col);
	bool isUnBlocked(int grid[][VELICINA], int row, int col);
	bool isDestination(int row, int col, Pair dest);
	int calculateHValue(int row, int col, Pair dest);
	void tracePath(sf::Clock clock,sf::RenderWindow& window, int grid[][VELICINA],cell cellDetails[][VELICINA], Pair dest);
	void aStarSearch(sf::Clock clock, sf::RenderWindow& window,int grid[][VELICINA], Pair src, Pair dest);

};

