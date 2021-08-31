#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <iostream>
#include <cmath>

class Circle 
{
private:
    double radius;

public:
	const double pi = 3.14159;
	Circle()
	{
		radius = 0;
	}
	
	Circle(double radius)
	{
		this->radius = radius;
	}
	
	double roundTo1(double value);
	double get_radius();
	void set_radius(double);
	double get_area();
	double get_circumference();
	double get_diameter();
};

#endif
