
#include "Truck.h"

// declare a truck body
Truck::Truck(void)
{
	// designing truck cabin
	Truck::truckCabin.setPointCount(5);
	Truck::truckCabin.setFillColor(sf::Color::Yellow);

	// truck cabin vertices
	Truck::truckCabin.setPoint(0, sf::Vector2f(5., 0.));
	Truck::truckCabin.setPoint(1, sf::Vector2f(25., 0.));
	Truck::truckCabin.setPoint(2, sf::Vector2f(25., 30.));
	Truck::truckCabin.setPoint(3, sf::Vector2f(0., 30.));
	Truck::truckCabin.setPoint(4, sf::Vector2f(0., 15.));

	// designing truck flatbed
	Truck::truckBed.setSize(sf::Vector2f(100., 25.));
	// set color
	Truck::truckBed.setFillColor(sf::Color::Green);

	// designing the main boom
	Truck::mainBoom.setSize(sf::Vector2f(-130, -20));
	Truck::mainBoom.setFillColor(sf::Color::Yellow);
	
	// designing extension arm 1
	Truck::extArm1.setSize(sf::Vector2f(-130, -15));
	Truck::extArm1.setFillColor(sf::Color::Red);
}

// set origin of the truck
void Truck::setOrigin(int x, int y)
{
	// set truck cabin position
	Truck::truckCabin.setPosition(x, y);
	// truck bed position set relative to
	// truck cabin
	Truck::truckBed.setPosition(Truck::truckCabin.getPosition().x
		+ 25., Truck::truckCabin.getPosition().y + 5.);
	// main boom position set relative to
	// truck bed
	Truck::mainBoom.setPosition(Truck::truckBed.getPosition().x
		+ 100., Truck::truckBed.getPosition().y);
	// extension boom 1 position set relative to
	// main boom
	Truck::extArm1.setPosition(Truck::mainBoom.getPosition().x, 
		Truck::mainBoom.getPosition().y - 3.);
}

// move a truck by X and Y pixels
void Truck::moveTruck(int x, int y)
{
	// set truck cabin position
	Truck::truckCabin.setPosition(Truck::truckCabin.getPosition().x + x,
		Truck::truckCabin.getPosition().y + y);
	// position of truck bed set relative to truck cabin
	Truck::truckBed.setPosition(Truck::truckCabin.getPosition().x
		+ 25., Truck::truckCabin.getPosition().y + 5.);
	// position of main boom set with truck flatbed
	Truck::mainBoom.setPosition(Truck::truckBed.getPosition().x
		+ 100, Truck::truckBed.getPosition().y);
	// position of extension boom set relatice to main boom
	Truck::extArm1.setPosition(Truck::mainBoom.getPosition().x, 
		Truck::mainBoom.getPosition().y - 3.);
}

// raise main boom
void Truck::raiseMainBoom(bool up_down)
{
	if(up_down == true)
	{ 
		Truck::mainBoom.rotate(1);
		Truck::extArm1.rotate(1);
	}
	else 
	{ 
		Truck::mainBoom.rotate(-1); 
		Truck::extArm1.rotate(-1);
	}

	Truck::moveTruck(0, 0);
}

// extend boom
void Truck::extendBoom(bool in_out)
{
	if (in_out == true)
	{
		Truck::extArm1.setSize(sf::Vector2f(Truck::extArm1.
			getSize().x - 1., Truck::extArm1.getSize().y));
	}
	else
	{
		Truck::extArm1.setSize(sf::Vector2f(Truck::extArm1.
			getSize().x + 1., Truck::extArm1.getSize().y));
	}
}

// get truck cabin graphics
sf::ConvexShape Truck::getTruckCabin(void)
{
	return this->truckCabin;
}

// get truck bed graphics
sf::RectangleShape Truck::getTruckBed(void)
{
	return this->truckBed;
}

// get main boom graphics
sf::RectangleShape Truck::getMainBoom(void)
{
	return this->mainBoom;
}

// get extension boom graphics
sf::RectangleShape Truck::getExtBoom(void)
{
	return this->extArm1;
}