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
	// set origin of the truck - middle of window (x, y)
	void setOrigin(int, int);
	// reset truck
	void reset(int, int);
	// move a truck by X and Y pixels
	void moveTruck(int, int);
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
	sf::ConvexShape getBoomRam(void);
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
	sf::ConvexShape boomRam;
	// boom ram cylinder shape
	sf::ConvexShape boomRamCylinder;

//-----------------------------------------------------------
	// hardcoded variables
//-----------------------------------------------------------
	// truck cabin
	const int cabin_points = 5;
	const float origin = 0.;
	const float cabin_offset = 5.;
	const float cabin_length = 25.;
	const float cabin_height = 30.;
	const float cabin_hood_height = 15.;
//-----------------------------------------------------------
	// truck flatbed
	const float bed_length = 100.;
	const float bed_height = 25.;
	const float bed_height_offset_to_cabin = 5.;
//-----------------------------------------------------------
	// truck tyres
	const float tyre_radius = 10.;
	const int no_of_tyres = 5;
	const float tyre_x_offset_to_cabin = 10.;
	const float tyre_y_offset_to_cabin = 20.;
	const float tyre_gap = 20.;
//-----------------------------------------------------------
	// main boom
	const float main_boom_length = -130.;
	const float main_boom_height = -20.;
	const float main_boom_offset_to_bed = 75.;
	const float main_boom_rotate_upper_limit = 80.;
	const float main_boom_rotate_lower_limit = 0.;
//-----------------------------------------------------------
	// extension arm 1
	const float ext_arm_length = -132.;
	const float ext_arm_height = -15.;
	const float ext_arm_offset_to_main_boom = -3.;
	const int ext_arm_extend_limit = -245;
	const int ext_arm_retract_limit = -132;
//-----------------------------------------------------------
	// boom ram
	const int boom_ram_points = 4;
	const float boom_ram_x_offset_to_flatbed = 70.;
	const float boom_ram_y_offset_to_flatbed = 5.;
//-----------------------------------------------------------
	// boom ram cylinder
	const int boom_ram_cylinder_points = 4;
	const float boom_ram_cylinder_x_offset_to_flatbed = 62.5;
	const float boom_ram_cylinder_y_offset_to_flatbed_up = 3.;
	const float boom_ram_cylinder_y_offset_to_flatbed_down = 6.;
	const float boom_ram_cylinder_adjust_angle_upper = 70.;
	const float boom_ram_cylinder_adjust_angle_lower = 30.;
	const float boom_ram_cylinder_y_offset_to_main_boom = 3.;
//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------------------------------------------------
//-----------------------------------------------------------
};
