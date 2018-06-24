#include "generatorLabirinta.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <stack>
#include<vector>
#include <fstream>


using namespace std;


generatorLabirinta::generatorLabirinta()
{
	Cell Level[VELICINA][VELICINA];
	int posX = 0;
	int posY = 0;
	int goalX = 0;
	int goalY = 0;
	bool game_over = false;



	while (!game_over) {
		
		Initialize(Level);
		GenerateMaze(Level, posX, posY, goalX, goalY);

		int brojacVek = 0;
		for (int i = 0; i < VELICINA; i++) {
			for (int j = 0; j < VELICINA; j++) {

					polje[i][j] = Level[i][j].display;
					if (Level[i][j].display == 5) {

						rX = i;
						rY = j;

					}
					if (Level[i][j].display == 3) {

						rXE = i;
						rYE = j;

					}

			}
		}
		game_over = true;
	}

}

// inicijalizacija
void generatorLabirinta::Initialize(Cell Level[][VELICINA]) {
	for (int i = 0; i<VELICINA; i++) {
		for (int j = 0; j<VELICINA; j++) {

			Level[i][j].display = 1;
			Level[i][j].visited = false;
			Level[i][j].top_wall = true;
			Level[i][j].bot_wall = true;
			Level[i][j].left_wall = true;
			Level[i][j].right_wall = true;
		}
	}
	for (int i = 1; i<VELICINA - 1; i++) {
		for (int j = 1; j<VELICINA - 1; j++) {
			Level[1][j].top_wall = false;
			Level[VELICINA - 2][j].bot_wall = false;
			Level[i][1].left_wall = false;
			Level[i][VELICINA - 2].right_wall = false;
		}
	}
}


// ponovno crtanje


void generatorLabirinta::GenerateMaze(Cell Level[][VELICINA], int &posX, int &posY, int &goalX, int &goalY) {
	srand((unsigned)time(NULL));                                                                           
	int random = 0;
	int randomX = ((2 * rand()) + 1) % (VELICINA - 1);                                         
	int randomY = ((2 * rand()) + 1) % (VELICINA - 1);                                          

	posX = randomX;                                                                
	posY = randomY;                                                                 
	int visitedCells = 1;
	int totalCells = ((VELICINA - 1) / 2)*((VELICINA - 1) / 2);
	int percent = 0;
	stack<int> back_trackX, back_trackY;                                           
	rY = randomY;
	rX = randomX;

	Level[rY][rX].display = 5;                                        
	Level[randomY][randomX].visited = true;                                               

	while (visitedCells < totalCells)
	{
		if (((Level[randomY - 2][randomX].visited == false) && (Level[randomY][randomX].top_wall == true && Level[randomY - 2][randomX].bot_wall == true)) ||
			((Level[randomY + 2][randomX].visited == false) && (Level[randomY][randomX].bot_wall == true && Level[randomY + 2][randomX].top_wall == true)) ||
			((Level[randomY][randomX - 2].visited == false) && (Level[randomY][randomX].left_wall == true && Level[randomY][randomX - 2].right_wall == true)) ||
			((Level[randomY][randomX + 2].visited == false) && (Level[randomY][randomX].right_wall == true && Level[randomY][randomX + 2].left_wall == true)))
		{
			random = (rand() % 4) + 1;           

													
			if ((random == 1) && (randomY > 1)) {
				if (Level[randomY - 2][randomX].visited == false) {     
					Level[randomY - 1][randomX].display = 0;        
					Level[randomY - 1][randomX].visited = true;     
					Level[randomY][randomX].top_wall = false;       

					back_trackX.push(randomX);                      
					back_trackY.push(randomY);                      

					randomY -= 2;                                   
					Level[randomY][randomX].visited = true;         
					Level[randomY][randomX].display = 0;          
					Level[randomY][randomX].bot_wall = false;     
					visitedCells++;                               
				}
				else
					continue;
			}

		
			else if ((random == 2) && (randomY < VELICINA - 2)) {
				if (Level[randomY + 2][randomX].visited == false) {       
					Level[randomY + 1][randomX].display = 0;        
					Level[randomY + 1][randomX].visited = true;     
					Level[randomY][randomX].bot_wall = false;       
					back_trackX.push(randomX);                      
					back_trackY.push(randomY);                      

					randomY += 2;                                   
					Level[randomY][randomX].visited = true;        
					Level[randomY][randomX].display = 0;        
					Level[randomY][randomX].top_wall = false;    
					visitedCells++;                                 
				}
				else
					continue;
			}

		
			else if ((random == 3) && (randomX > 1)) {
				if (Level[randomY][randomX - 2].visited == false) {        
					Level[randomY][randomX - 1].display = 0;     
					Level[randomY][randomX - 1].visited = true;      
					Level[randomY][randomX].left_wall = false;     

					back_trackX.push(randomX);                     
					back_trackY.push(randomY);                      

					randomX -= 2;                                   
					Level[randomY][randomX].visited = true;         
					Level[randomY][randomX].display = 0;          
					Level[randomY][randomX].right_wall = false;     
					visitedCells++;                                 
				}
				else
					continue;
			}

		
			else if ((random == 4) && (randomX < VELICINA - 2)) {
				if (Level[randomY][randomX + 2].visited == false) {       
					Level[randomY][randomX + 1].display = 0;      
					Level[randomY][randomX + 1].visited = true;      
					Level[randomY][randomX].right_wall = false;    
					back_trackX.push(randomX);                      
					back_trackY.push(randomY);                      

					randomX += 2;                                   
					Level[randomY][randomX].visited = true;         
					Level[randomY][randomX].display = 0;        
					Level[randomY][randomX].left_wall = false;      
					visitedCells++;                                
				}
				else
					continue;
			}

		}
		else {
			randomX = back_trackX.top();
			back_trackX.pop();

			randomY = back_trackY.top();
			back_trackY.pop();
		}

	}


	goalX = randomX;
	goalY = randomY;
	
	
	Level[goalX][goalY].display = 3;


}
