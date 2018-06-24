#include "PrikazLabirinta.h"
#include<Windows.h>
#include <SFML/Graphics.hpp>
#include "generatorLabirinta.h"

int prevX=0;
int prevY=0;


PrikazLabirinta::PrikazLabirinta(int size, sf::Clock clock, sf::RenderWindow& window,int grid[][VELICINA],int s, int d)
{

	sf::Event event;

	while (window.pollEvent(event))
	{

		switch (event.type) {

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space) {
				generatorLabirinta generator;
				PathAlgoritam(clock, window, generator.polje, generator.rX, generator.rY, generator.rXE, generator.rYE);
			}
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
				exit(0);
			}
		}
	}

	int x = 0;
	int y = 25;
	
	sf::RectangleShape rect1;
	rect1.setSize(sf::Vector2f(25, 25));
	sf::Font font;
	sf::Font font_title;
	font.loadFromFile("Minnie.ttf");
	font_title.loadFromFile("Naslov.ttf");
	sf::Text restart;
	sf::Text press_space;
	sf::Text press_esc;
	restart.setFont(font_title);
	restart.setCharacterSize(40);
	restart.setPosition(55, 2);
	restart.setFillColor(sf::Color::Yellow);
	restart.setString("- THE MAZE CHEESE CHASE -");
	press_space.setFont(font);
	press_space.setCharacterSize(28);
	press_space.setPosition(27, 930);
	press_space.setFillColor(sf::Color::Yellow);
	press_space.setString("Press SPACE to generate a new maze");
	press_esc.setFont(font);
	press_esc.setCharacterSize(28);
	press_esc.setPosition(650, 930);
	press_esc.setFillColor(sf::Color::Yellow);
	press_esc.setString("I ESC - exit");

	window.draw(restart);
	window.draw(press_esc);
	window.draw(press_space);

	sf::Texture misTekstura_lijevo;
	misTekstura_lijevo.loadFromFile("mis_lijevo.png");
	sf::RectangleShape mis_lijevo;
	sf::Texture misTekstura_desno;
	misTekstura_desno.loadFromFile("mis_desno.png");
	sf::RectangleShape mis_desno;
	sf::Texture misTekstura_gore;
	misTekstura_gore.loadFromFile("mis_gore.png");
	sf::RectangleShape mis_gore;
	sf::Texture misTekstura_dolje;
	misTekstura_dolje.loadFromFile("mis_dolje.png");
	sf::RectangleShape mis_dolje;

	sf::Texture zidTekstura;
	zidTekstura.loadFromFile("zid.png");
	sf::RectangleShape zid; 
	sf::Texture podTekstura;
	podTekstura.loadFromFile("pod.png");
	sf::RectangleShape pod;
	sf::Texture sirTekstura;
	sirTekstura.loadFromFile("sir.png");
	sf::RectangleShape sir;

	zid.setTexture(&zidTekstura);
	sir.setTexture(&sirTekstura);
	mis_lijevo.setTexture(&misTekstura_lijevo);
	mis_desno.setTexture(&misTekstura_desno);
	mis_gore.setTexture(&misTekstura_gore);
	mis_dolje.setTexture(&misTekstura_dolje);
	pod.setTexture(&podTekstura);
	zid.setSize(sf::Vector2f(25, 25));
	sir.setSize(sf::Vector2f(25, 25));
	pod.setSize(sf::Vector2f(25, 25));
	mis_lijevo.setSize(sf::Vector2f(28, 28));
	mis_desno.setSize(sf::Vector2f(28, 28));
	mis_gore.setSize(sf::Vector2f(28, 28));
	mis_dolje.setSize(sf::Vector2f(28, 28));
	rect1.setFillColor(sf::Color::Green);
	
	grid[s][d] = 2;
	

		for (int i = 0; i < VELICINA; i++) {
			cout << endl;
			y = y + 25;
			x = 0;
			rect1.setFillColor(sf::Color::Green);
			for (int j = 0; j < VELICINA; j++) {
				rect1.setPosition(x, y);
				zid.setPosition(x, y);
				mis_lijevo.setPosition(x, y);
				mis_desno.setPosition(x, y);
				mis_gore.setPosition(x, y);
				mis_dolje.setPosition(x, y);
				pod.setPosition(x, y);
				sir.setPosition(x, y);
				x = x + 25;

				if (grid[i][j] == 0) {
				
					rect1.setFillColor(sf::Color::Black);
					window.draw(pod);
				}
				if (grid[i][j] == 1) {
			
					
					window.draw(zid);
				}
				if (grid[i][j] == 2) {
					if ((i == prevX && j > prevY) && (prevX != 0 || prevY!=0)) {
						window.draw(mis_desno);
					}
					if ((i == prevX && j < prevY) && (prevX != 0 || prevY != 0)) {
						window.draw(mis_lijevo);
					}
					if ((i > prevX && j == prevY) && (prevX != 0 || prevY != 0)) {
						window.draw(mis_dolje);
					}
					if ((i < prevX && j == prevY) && (prevX != 0 || prevY != 0)){
						window.draw(mis_gore);
					}
					
					
				}
				if (grid[i][j] == 3) {
				
					rect1.setFillColor(sf::Color::Red);
					window.draw(pod);
					window.draw(sir);
				}
				if (grid[i][j] == 5) {
					//cout << "S";
				}


			}
		}


		prevX = s;
		prevY = d;
		grid[prevX][prevY] = 0;

		
		window.display();
		if (size == 1) {
			sf::sleep(sf::seconds(2));
		}

				}

