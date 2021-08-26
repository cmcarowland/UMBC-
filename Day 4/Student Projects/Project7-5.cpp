/*
 * Raymond Rowland
 * 26AUG21
 * Create a program that converts feet to meters and vice versa.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

#include "console.h"
#include "Project7-5Conversions.h"

using namespace std;
using namespace console;

double Round(double num, int places)
{
	double outNum = num;
	if(places > 0)
	{
		int place = 0;
		
		for(int i = 0; i < places; i ++)
		{
			if(place == 0)
			{
				place = 10;
			}
			else
			{
				place *= 10;
			}
		}
		
		outNum = round(num * place) / place;
	}
	
	return outNum;
}

void DisplayMenu()
{
	cout << "Conversion Menu:\n";
	cout << "a. Feet to Meters\n";
	cout << "b. Meters to Feet\n";
}

int main()
{
	char userInput = 0;
	cout << "Feet and Meters Converter\n\n";
	
	do
	{
		DisplayMenu();
		userInput = get_char("Select a conversion (a/b): ");
		if(userInput == 'a')
		{
			cout << Round(Conversions::FeetToMeters(get_double("Enter Feet: ")), 2) << " Meters\n\n";
		}
		else if(userInput == 'b')
		{
			cout << Round(Conversions::MetersToFeet(get_double("Enter Meters: ")), 2) << " Feet\n\n";
		}
		else
		{
			cout << "Invalid Menu Option, Please Try Again.\n\n";
		}
	}while(tolower(get_char("Continue? (y/n): ")) == 'y'); 
	
	cout << "Thanks, bye!" << endl;
}
