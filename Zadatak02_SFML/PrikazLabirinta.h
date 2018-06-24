#pragma once
#include "PathAlgoritam.h"
#include <SFML/Graphics.hpp>
class PrikazLabirinta
{
public: 

	struct field
	{
		int x;
		int y;

	};
	static const int VELICINA = 35;
private:
	int labirint[VELICINA][VELICINA];

public:

	PrikazLabirinta(int size, sf::Clock clock, sf::RenderWindow& window, int grid[][VELICINA], int x, int y);

};

