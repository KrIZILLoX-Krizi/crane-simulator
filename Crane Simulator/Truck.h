#include <SFML/Graphics.hpp>

class Truck
{
public:
	// declare public variables & methods here
	
	// constructor
	Truck(void);
	
	// set origin of the truck
	void setOrigin(int, int);
	// move a truck by X and Y pixels
	void moveTruck(int, int);
	// lift main boom
	void raiseMainBoom(bool);
	// extend boom
	void extendBoom(bool);
	
	// get truck cabin graphics
	sf::ConvexShape getTruckCabin(void);
	// get truck bed graphics
	sf::RectangleShape getTruckBed(void);
	// get main boom graphics
	sf::RectangleShape getMainBoom(void);
	// get extension boom graphics
	sf::RectangleShape getExtBoom(void);

private:
	// declare private variables & methods here
	// shapes

	// truck cabin shape
	sf::ConvexShape truckCabin;
	// truck flatbed shape
	sf::RectangleShape truckBed;
	// crane main boom
	sf::RectangleShape mainBoom;
	// crane main boom extension arm 1
	sf::RectangleShape extArm1;
};
