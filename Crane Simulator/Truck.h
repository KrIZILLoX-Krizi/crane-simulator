#include <SFML/Graphics.hpp>

class Truck
{
public:
	// declare public variables & methods here
//-----------------------------------------------------------
	
	// constructor
	Truck(void);
//-----------------------------------------------------------
// FUNCTIONS OF TRUCK
//-----------------------------------------------------------	
	// set origin of the truck
	void setOrigin(int, int);
	// reset truck
	void reset(int, int);
	// move a truck by X and Y pixels
	void moveTruck(int, int, int, int);
	// lift main boom
	void raiseMainBoom(bool);
	// extend boom
	void extendBoom(bool);
//-----------------------------------------------------------
// GRAPHICS GETTERS
//-----------------------------------------------------------	
	// get truck cabin graphics
	sf::ConvexShape getTruckCabin(void);
	// get truck bed graphics
	sf::RectangleShape getTruckBed(void);
	// get tyre graphics
	std::vector<sf::CircleShape> getTyres(void);
	// get main boom graphics
	sf::RectangleShape getMainBoom(void);
	// get extension boom graphics
	sf::RectangleShape getExtBoom(void);
	// get boom ram graphics
	sf::RectangleShape getBoomRam(void);
	// get boom ram cylinder graphics
	sf::ConvexShape getBoomRamCylinder(void);
//-----------------------------------------------------------
private:
	// declare private variables & methods here
//-----------------------------------------------------------
	// shapes
//-----------------------------------------------------------
	// truck cabin shape
	sf::ConvexShape truckCabin;
	// truck flatbed shape
	sf::RectangleShape truckBed;
	// truck tyres shape
	sf::CircleShape tyre;
	// vector for tyres
	std::vector<sf::CircleShape> tyresVector;
	// crane main boom shape
	sf::RectangleShape mainBoom;
	// crane main boom extension arm 1 shape
	sf::RectangleShape extArm1;
	// boom ram shape
	sf::RectangleShape boomRam;
	// boom ram cylinder shape
	sf::ConvexShape boomRamCylinder;
//-----------------------------------------------------------
};
