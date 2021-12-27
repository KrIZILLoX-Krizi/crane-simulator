#include <SFML/Graphics.hpp>
#include "Truck.h"

//-----------------------------------------------------------
// driver
//-----------------------------------------------------------
int main(void)
{
//-----------------------------------------------------------
	// window canvas
	sf::RenderWindow window(sf::VideoMode(500, 500), "Crane Simulator");
	window.setFramerateLimit(30);
//-----------------------------------------------------------
	// truck object
	Truck truck;
	truck.setOrigin(window.getSize().x / 2., window.getSize().y / 2.);
//-----------------------------------------------------------
	// GAME LOOP
//-----------------------------------------------------------
	while (window.isOpen()) {
		// event listener
		sf::Event event;

		while (window.pollEvent(event)) {
			
			switch (event.type)
			{
//-----------------------------------------------------------
				// closed by X
			case sf::Event::Closed:
				window.close(); return 111;
				break;
//-----------------------------------------------------------
// 				   // KEY PRESS EVENTS
//-----------------------------------------------------------
				// closed by Escape
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{ window.close(); return 111; }
//-----------------------------------------------------------
				// reset game
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{ truck.reset(window.getSize().x / 2., window.getSize().y / 2.); }
//-----------------------------------------------------------
				// move left
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{ 
					truck.moveTruck(-1, 0, window.getSize().x,
						window.getSize().y); 
				}
				// move right
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{ 
					truck.moveTruck(1, 0, window.getSize().x,
						window.getSize().y); 
				}
//-----------------------------------------------------------
				// main boom up
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				{ 
					truck.raiseMainBoom(true); 
					truck.moveTruck(0, 0, window.getSize().x/2,
						window.getSize().y/2);
				}
				// main boom down
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				{ truck.raiseMainBoom(false); }
//-----------------------------------------------------------
				// extend boom
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				{ truck.extendBoom(true); }
				// retract boom
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				{ truck.extendBoom(false); }
//-----------------------------------------------------------
				break;

			default:
				break;
			}
		}
//-----------------------------------------------------------
		// clear window
		window.clear(sf::Color::White);
//-----------------------------------------------------------
		// update components
//-----------------------------------------------------------
		window.draw(truck.getTruckCabin());
		window.draw(truck.getTruckBed());
		// render tyres
		for (auto it : truck.getTyres())
		{ window.draw(it); }
		window.draw(truck.getExtBoom());
		window.draw(truck.getMainBoom());
		//window.draw(truck.getBoomRam());
		window.draw(truck.getBoomRamCylinder());
//-----------------------------------------------------------
		// show window
		window.display();
//-----------------------------------------------------------
	}
//-----------------------------------------------------------
	// GAME LOOP ENDS HERE
//-----------------------------------------------------------

	return 101;
}