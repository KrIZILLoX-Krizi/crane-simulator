#include <iostream>
#include "Truck.h"

//-----------------------------------------------------------
// DECLARE A TRUCK BODY
//-----------------------------------------------------------
Truck::Truck(void)
{
//-----------------------------------------------------------
	// designing truck cabin
	Truck::truckCabin.setPointCount(cabin_points);
	Truck::truckCabin.setFillColor(sf::Color::Yellow);
//-----------------------------------------------------------
	// truck cabin vertices
	Truck::truckCabin.setPoint(0, sf::Vector2f(cabin_offset, origin));
	Truck::truckCabin.setPoint(1, sf::Vector2f(cabin_length, origin));
	Truck::truckCabin.setPoint(2, sf::Vector2f(cabin_length, cabin_height));
	Truck::truckCabin.setPoint(3, sf::Vector2f(origin, cabin_height));
	Truck::truckCabin.setPoint(4, sf::Vector2f(origin, cabin_hood_height));
//-----------------------------------------------------------
	// designing truck flatbed
	Truck::truckBed.setSize(sf::Vector2f(bed_length, bed_height));
	Truck::truckBed.setFillColor(sf::Color::Green);
//-----------------------------------------------------------
	// designing tyres
	Truck::tyre.setRadius(tyre_radius);
	Truck::tyre.setFillColor(sf::Color::Black);
//-----------------------------------------------------------
	// designing the main boom
	Truck::mainBoom.setSize(sf::Vector2f(main_boom_length, main_boom_height));
	Truck::mainBoom.setFillColor(sf::Color::Yellow);
//-----------------------------------------------------------
	// designing extension arm 1
	Truck::extArm1.setSize(sf::Vector2f(ext_arm_length, ext_arm_height));
	Truck::extArm1.setFillColor(sf::Color::Red);
//-----------------------------------------------------------
	// designing boom ram
	Truck::boomRam.setPointCount(boom_ram_points);
	Truck::boomRam.setFillColor(sf::Color::Red);
//-----------------------------------------------------------
	// designing boom ram cylinder
	Truck::boomRamCylinder.setPointCount(boom_ram_cylinder_points);
	Truck::boomRamCylinder.setFillColor(sf::Color::Black);
//-----------------------------------------------------------
	
//-----------------------------------------------------------
}
//-----------------------------------------------------------
	// END OF TRUCK BODY
//-----------------------------------------------------------

//-----------------------------------------------------------
// SET ORIGIN OF TRUCK
//-----------------------------------------------------------
void Truck::setOrigin(int x, int y)
{
//-----------------------------------------------------------
	// set truck cabin position
	Truck::truckCabin.setPosition(x, y);
//-----------------------------------------------------------
	// truck bed position set relative to
	// truck cabin
	Truck::truckBed.setPosition(Truck::truckCabin.getPosition().x
		+ cabin_length,
		Truck::truckCabin.getPosition().y + bed_height_offset_to_cabin
	);
//-----------------------------------------------------------
	// tyre position relative to cabin and flatbed
	Truck::tyresVector.push_back(Truck::tyre);
	Truck::tyresVector[0].setPosition(Truck::truckCabin.getPosition().x
		+ tyre_x_offset_to_cabin,
		Truck::truckCabin.getPosition().y + tyre_y_offset_to_cabin
	);
//-----------------------------------------------------------	
	// remaining tyres
	for (int i = 1; i <= Truck::no_of_tyres; ++i)
	{
		// adding remaining tyres
		Truck::tyresVector.push_back(Truck::tyre);
		// updating tyre positions
		Truck::tyresVector[i].setPosition(Truck::tyresVector[i-1].getPosition().x
			+ tyre_gap,
			Truck::tyresVector[i-1].getPosition().y
		);
	}
//-----------------------------------------------------------
	// main boom position set relative to
	// truck bed
	Truck::mainBoom.setPosition(Truck::truckBed.getPosition().x
		+ main_boom_offset_to_bed,
		Truck::truckBed.getPosition().y
	);
//-----------------------------------------------------------
	// extension boom 1 position set relative to
	// main boom
	Truck::extArm1.setPosition(Truck::mainBoom.getPosition().x,
		Truck::mainBoom.getPosition().y + ext_arm_offset_to_main_boom
	);
//-----------------------------------------------------------
	// boom ram position set relative to boom ram cylinders
	Truck::boomRam.setPosition(Truck::truckBed.getPosition().x
		+ boom_ram_x_offset_to_flatbed,
		Truck::truckBed.getPosition().y + boom_ram_y_offset_to_flatbed
	);
//-----------------------------------------------------------
	// position of boom ram cylinder vertices
	Truck::boomRamCylinder.setPoint(1, sf::Vector2f(Truck::
		truckBed.getPosition().x + boom_ram_cylinder_x_offset_to_flatbed,
		Truck::truckBed.getPosition().y + 
		boom_ram_cylinder_y_offset_to_flatbed_up
	));
	Truck::boomRamCylinder.setPoint(2, sf::Vector2f(Truck::
		truckBed.getPosition().x + boom_ram_cylinder_x_offset_to_flatbed,
		Truck::truckBed.getPosition().y +
		boom_ram_cylinder_y_offset_to_flatbed_down
	));
	
	// global points for the main boom
	sf::Vector2f pointRight = Truck::mainBoom.getTransform() *
		Truck::mainBoom.getPoint(0);
	sf::Vector2f pointLeft = Truck::mainBoom.getTransform() *
		Truck::mainBoom.getPoint(1);

	// attach cylinder top to main boom bottom half length
	Truck::boomRamCylinder.setPoint(3, sf::Vector2f(
		(pointRight.x + pointLeft.x) / 2,
		(pointRight.y + pointLeft.y) / 2
	));

	Truck::boomRamCylinder.setPoint(0, sf::Vector2f(
		(pointRight.x + pointLeft.x) / 2,
		(pointRight.y + pointLeft.y) / 2 - boom_ram_cylinder_y_offset_to_main_boom
	));
//-----------------------------------------------------------
}
//-----------------------------------------------------------
	// END OF SET ORIGIN
//-----------------------------------------------------------

// RESET
void Truck::reset(int x, int y)
{
	return;
}

//-----------------------------------------------------------
// MOVE A TRUCK by X and Y pixels
//-----------------------------------------------------------
void Truck::moveTruck(int x, int y)
{
//-----------------------------------------------------------
	// set truck cabin position
	Truck::truckCabin.setPosition(Truck::truckCabin.getPosition().x + x,
		Truck::truckCabin.getPosition().y + y
	);
//-----------------------------------------------------------
	// position of truck bed set relative to truck cabin
	Truck::truckBed.setPosition(Truck::truckCabin.getPosition().x
		+ cabin_length,
		Truck::truckCabin.getPosition().y + bed_height_offset_to_cabin
	);
//-----------------------------------------------------------
	// tyre position relative to cabin and flatbed
	Truck::tyresVector[0].setPosition(Truck::truckCabin.getPosition().x
		+ 10., 
		Truck::truckCabin.getPosition().y + 20.
	);
//-----------------------------------------------------------
	// remaining tyres
	for (int i = 1; i <= Truck::no_of_tyres; ++i)
	{
		// updating tyre positions
		Truck::tyresVector[i].setPosition(Truck::tyresVector[i - 1].getPosition().x
			+ tyre_gap, 
			Truck::tyresVector[i - 1].getPosition().y
		);
	}
//-----------------------------------------------------------	
	// position of main boom set with truck flatbed
	Truck::mainBoom.setPosition(Truck::truckBed.getPosition().x
		+ main_boom_offset_to_bed,
		Truck::truckBed.getPosition().y
	);
//-----------------------------------------------------------	
	// position of extension boom set relatice to main boom
	Truck::extArm1.setPosition(Truck::mainBoom.getPosition().x,
		Truck::mainBoom.getPosition().y + ext_arm_offset_to_main_boom
	);
//-----------------------------------------------------------
	// boom ram position set relative to truck flatbed
	Truck::boomRam.setPosition(Truck::truckBed.getPosition().x
		+ boom_ram_x_offset_to_flatbed,
		Truck::truckBed.getPosition().y + boom_ram_y_offset_to_flatbed
	);
//-----------------------------------------------------------
	// boom ram cylinder graphics adjustment factor
	int adjustmentFactor = 0;
	if (Truck::mainBoom.getRotation() > boom_ram_cylinder_adjust_angle_lower && 
		Truck::mainBoom.getRotation() < boom_ram_cylinder_adjust_angle_upper)
	{
		adjustmentFactor = 1;
	}
	else if (Truck::mainBoom.getRotation() >= boom_ram_cylinder_adjust_angle_upper)
	{
		adjustmentFactor = 2;
	}
	else
	{
		adjustmentFactor = 0;
	}

	// position of boom ram cylinder vertices
	Truck::boomRamCylinder.setPoint(1, sf::Vector2f(Truck::
		truckBed.getPosition().x + boom_ram_cylinder_x_offset_to_flatbed,
		Truck::truckBed.getPosition().y +
		boom_ram_cylinder_y_offset_to_flatbed_up
	));

	Truck::boomRamCylinder.setPoint(2, sf::Vector2f(Truck::
		truckBed.getPosition().x + boom_ram_cylinder_x_offset_to_flatbed
		 - adjustmentFactor,
		Truck::truckBed.getPosition().y +
		boom_ram_cylinder_y_offset_to_flatbed_down
	));

	// global points for the main boom
	sf::Vector2f pointRight = Truck::mainBoom.getTransform() *
		Truck::mainBoom.getPoint(0);
	sf::Vector2f pointLeft = Truck::mainBoom.getTransform() *
		Truck::mainBoom.getPoint(1);

	// attach cylinder top to main boom bottom half length
	Truck::boomRamCylinder.setPoint(3, sf::Vector2f(
		(pointRight.x + pointLeft.x) / 2,
		(pointRight.y + pointLeft.y) / 2
	));

	Truck::boomRamCylinder.setPoint(0, sf::Vector2f(
		(pointRight.x + pointLeft.x) / 2 + adjustmentFactor,
		(pointRight.y + pointLeft.y) / 2 - boom_ram_cylinder_y_offset_to_main_boom
	));

	Truck::boomRamCylinder.setPoint(3, sf::Vector2f(
		(pointRight.x + pointLeft.x) / 2,
		(pointRight.y + pointLeft.y) / 2
	));
//-----------------------------------------------------------
}
//-----------------------------------------------------------
	// END OF MOVE TRUCK
//-----------------------------------------------------------

//-----------------------------------------------------------
// RAISE MAIN BOOM
//-----------------------------------------------------------
void Truck::raiseMainBoom(bool up_down)
{
	if(up_down == true)
	{ 
		// edge condition for raise
		if(Truck::mainBoom.getRotation() > main_boom_rotate_upper_limit)
		{ 
			return; 
		}

		// else rotate
		Truck::mainBoom.rotate(1);
		Truck::extArm1.rotate(1);
	}
	else 
	{ 
		// edge condition for lower
		if(Truck::mainBoom.getRotation() <= main_boom_rotate_lower_limit)
		{ return; }

		// else rotate
		Truck::mainBoom.rotate(-1); 
		Truck::extArm1.rotate(-1);
	}
}
//-----------------------------------------------------------

//-----------------------------------------------------------
// EXTEND BOOM
//-----------------------------------------------------------
void Truck::extendBoom(bool in_out)
{
	if (in_out == true)
	{
		// edge condition for extend
		if(Truck::extArm1.getSize().x <= ext_arm_extend_limit)
		{ 
			return; 
		}

		// else extend
		Truck::extArm1.setSize(sf::Vector2f(Truck::extArm1.
			getSize().x - 1., 
			Truck::extArm1.getSize().y)
		);
	}
	else
	{
		// edge condition for retract
		if(Truck::extArm1.getSize().x >= ext_arm_retract_limit)
		{ 
			return; 
		}

		// else retract
		Truck::extArm1.setSize(sf::Vector2f(Truck::extArm1.
			getSize().x + 1., 
			Truck::extArm1.getSize().y)
		);
	}
}
//-----------------------------------------------------------

//-----------------------------------------------------------
// GETTERS FOR GRAPHICS
//-----------------------------------------------------------
// get truck cabin graphics
sf::ConvexShape Truck::getTruckCabin(void)
{
	return this->truckCabin;
}
//-----------------------------------------------------------
// get truck bed graphics
sf::RectangleShape Truck::getTruckBed(void)
{
	return this->truckBed;
}
//-----------------------------------------------------------
// get tyre graphics
std::vector<sf::CircleShape> Truck::getTyres(void)
{
	return this->tyresVector;
}
//-----------------------------------------------------------
// get main boom graphics
sf::RectangleShape Truck::getMainBoom(void)
{
	return this->mainBoom;
}
//-----------------------------------------------------------
// get extension boom graphics
sf::RectangleShape Truck::getExtBoom(void)
{
	return this->extArm1;
}
//-----------------------------------------------------------
// get boom ram graphics
sf::ConvexShape Truck::getBoomRam(void)
{
	return this->boomRam;
}
//-----------------------------------------------------------
// get boom ram cylinder graphics
sf::ConvexShape Truck::getBoomRamCylinder(void)
{
	return this->boomRamCylinder;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
	// END OF GETTERS
//-----------------------------------------------------------