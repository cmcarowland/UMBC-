#include "Temp.h"

Temp::Temp()
{
	celsius = 0;
	fahrenheit = 32;
}

double Temp::roundTo2(double value)
{
	return round(value * 10) / 10;
}

double Temp::to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return roundTo2(celsius);
}

double Temp::to_fahrenheit(double celsius) {
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    return roundTo2(fahrenheit);
}

double Temp::get_celsius()
{
	return celsius;
}

double Temp::get_fahrenheit()
{
	return fahrenheit;
}

void Temp::set_celsius(double value)
{
	celsius = roundTo2(value);
	fahrenheit = to_fahrenheit(value);
}

void Temp::set_fahrenheit(double value)
{
	fahrenheit = roundTo2(value);
	celsius = to_celsius(value);
}
