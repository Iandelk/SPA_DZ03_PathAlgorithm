#pragma once
class generatorLabirinta
{
public:
	static const int VELICINA = 35;
	generatorLabirinta();
	int rX;
	int rY;
	int rXE;
	int rYE;
	int polje[VELICINA][VELICINA];


private:
	struct Cell
	{
		bool visited;
		bool top_wall;
		bool bot_wall;
		bool left_wall;
		bool right_wall;
		int display;
	};
	
	void Initialize(Cell Level[][VELICINA]);
	void GenerateMaze(Cell Level[][VELICINA], int &posX, int &posY, int &goalX, int &goalY);
	
};

