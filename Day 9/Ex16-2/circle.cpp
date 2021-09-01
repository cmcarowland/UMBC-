#include <iostream>
#include <cmath>
#include "circle.h"

using std::pow;
using std::ostream;
using std::endl;

// function definitions
double Circle::get_diameter() const {
	return 2 * radius;
}

double Circle::get_circumference() const {
	return get_diameter() * pi;
}

double Circle::get_area() const {
	return pi * pow(radius, 2.0);
}

Circle Circle::operator+ (const Circle &cir)
{
	Circle c;
	c.radius = radius + cir.radius;
	return c;
}

Circle Circle::operator- (const Circle &cir)
{
	Circle c;
	c.radius = radius - cir.radius;
	return c;
}

Circle& Circle::operator++ ()
{
	radius ++;
	return *this;
}

std::ostream& operator<< (std::ostream &out, const Circle &cir)
{
	out << "radius=" << cir.get_radius()
		<< "|diameter=" << cir.get_diameter()
		<< "|circumference=" << cir.get_circumference()
		<< "|area=" << cir.get_area() << endl;
}
