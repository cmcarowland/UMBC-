#include "Circle.h"


double Circle::roundTo1(double value)
{
	return round(value * 10) / 10;
}

void Circle::set_radius(double value)
{
	radius = roundTo1(value);
}

double Circle::get_radius()
{
	return radius;
}

double Circle::get_area()
{
	return roundTo1(pi * pow(radius, 2.0));
}

double Circle::get_circumference()
{
	return roundTo1(get_diameter() * pi);
}

double Circle::get_diameter()
{
	return roundTo1(2 * radius);
}
