#ifndef TEMP_H
#define TEMP_H

#include <string>
#include <iostream>
#include <cmath>

class Temp 
{
private:
    double celsius;
    double fahrenheit;
    
    double roundTo2(double value);

public:
	Temp();
	double to_celsius(double fahrenheit);
	double to_fahrenheit(double celsius);
	double get_celsius();
	double get_fahrenheit();
	void set_celsius(double value);
	void set_fahrenheit(double value);
};

#endif
