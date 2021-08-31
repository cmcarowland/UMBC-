/*
 * Raymond Rowland
 * 31AUG21
 * Ex 14-3
 * Create an OOP Circle Calculator
 * - Create Const for pi
 * - Default constructor sets radius to 0
 * - Define getters and setter for radius
 * - Define getters that:
 *   - Return circumference, diameter and area
 * - Modify Main to use a circle object
 * - Use getters for different measurements to get and display values
 * --Refactor main code
 * 
 * -Bonus
 *   - Overload the default constructor with a constructor that accepts a radius
 */
#include <iostream>
#include <cmath>
#include "Circle.h"

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::round;

int main()
{
	// print name of program
	cout << "Circle Calculator" << endl << endl;

	// get radius from user
	double radius;
	cout << "Enter radius:  ";
	cin >> radius;
	
	Circle c = Circle(radius);
	//c.set_radius(radius);

	// write output to console
	cout << "Diameter:      " << c.get_diameter() << endl
		<< "Circumference: " << c.get_circumference() << endl
		<< "Area:          " << c.get_area() << endl << endl
		<< "Bye!" << endl << endl;

	// return value that indicates normal program exit
    return 0;
}
