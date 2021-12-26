#include <SFML/Graphics.hpp>
#include "Truck.h"

int main(void)
{
	// window canvas
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode()), "Crane Simulator", sf::Style::Fullscreen);
	window.setFramerateLimit(30);

	Truck truck;
	truck.setOrigin(window.getSize().x / 2.,
		window.getSize().y / 2.);

	while (window.isOpen()) {
		// event listener
		sf::Event event;

		while (window.pollEvent(event)) {
			
			switch (event.type)
			{
				// closed by X
			case sf::Event::Closed:
				window.close(); return 111;
				break;

				// closed by Escape
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{ window.close(); return 111; }
				// move left
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{ truck.moveTruck(-1, 0); }
				// move right
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{ truck.moveTruck(1, 0); }
				// main boom up
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				{ truck.raiseMainBoom(true); }
				// main boom down
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				{ truck.raiseMainBoom(false); }
				// extend boom
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				{ truck.extendBoom(true); }
				// retract boom
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				{ truck.extendBoom(false); }
				break;

			default:
				break;
			}
		}

		// clear window
		window.clear(sf::Color::White);

		// update components
		window.draw(truck.getTruckCabin());
		window.draw(truck.getTruckBed());
		window.draw(truck.getExtBoom());
		window.draw(truck.getMainBoom());

		// show window
		window.display();
	}

	return 101;
}