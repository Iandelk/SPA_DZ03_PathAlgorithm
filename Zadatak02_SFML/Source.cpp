#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "generatorLabirinta.h"
#include "PathAlgoritam.h"
#include "PrikazLabirinta.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(880, 975), "Hello, SFML world!");
	window.setFramerateLimit(10);

	sf::Music pjesma;
	pjesma.openFromFile("main_theme.ogg");
	pjesma.setVolume(50);
	pjesma.play();
	pjesma.setLoop(true);




	sf::Clock clock;

	sf::Font font_title;
	sf::Font font;
	font.loadFromFile("Minnie.ttf");
	font_title.loadFromFile("Naslov.ttf");
	sf::Text restart;
	sf::Text press_space;
	sf::Text press_esc;
	sf::Text end_line;
	end_line.setFont(font);
	end_line.setCharacterSize(45);
	end_line.setPosition(120, 150);
	end_line.setFillColor(sf::Color::Green);
	end_line.setString("The mouse has been fed!");
	restart.setFont(font_title);
	restart.setCharacterSize(45);
	restart.setPosition(35, 400);
	restart.setFillColor(sf::Color::Yellow);
	restart.setString("-THE MAZE CHEESE CHASE-");
	press_space.setFont(font);
	press_space.setCharacterSize(30);
	press_space.setPosition(120, 500);
	press_space.setFillColor(sf::Color::Yellow);
	press_space.setString("Press SPACE to generate a new maze");
	press_esc.setFont(font);
	press_esc.setCharacterSize(30);
	press_esc.setPosition(340, 600);
	press_esc.setFillColor(sf::Color::Yellow);
	press_esc.setString("ESC - exit");

	

	generatorLabirinta generator;
	PathAlgoritam(clock, window, generator.polje, generator.rX, generator.rY, generator.rXE, generator.rYE);

	while (window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{ 

			switch (event.type) {

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) {
					generatorLabirinta generator;
					PathAlgoritam(clock, window, generator.polje, generator.rX, generator.rY, generator.rXE, generator.rYE);
				}
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}

	
		window.clear();
		window.draw(end_line);
		window.draw(restart);
		window.draw(press_esc);
		window.draw(press_space);
		window.display();
	}

	return 0;
}