/*
 * Raymond Rowland
 * 26AUG21
 * Create a Tip Calculator program that validates data.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "console.h"
#include <cmath>

using namespace std;
using namespace console;

double Round(double num, int places)
{
	int outNum = num;
	
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

int main()
{
	cout << "Tip Calculator\n\nINPUT\n";
	double costOfMeal = get_double("Cost of meal: ", 0, 1000);
	int tipPercent = get_int("Tip Percent: ", 10, 30);
	double tipAmount = costOfMeal * (tipPercent / 100.0);
	double totalCost = tipAmount + costOfMeal;
	
	cout << "\nOUTPUT\n";
	const int col_width = 18;
	cout << left << setw(col_width) << "Cost of meal: " << right << Round(costOfMeal, 2) << endl;
	cout << left << setw(col_width) << "Tip Percent: " << right << tipPercent << "%" << endl;
	cout << left << setw(col_width) << "Tip: " << right << Round(tipAmount, 2) << endl;
	cout << left << setw(col_width) << "Total: " << right << Round(totalCost, 2) << endl;
}
