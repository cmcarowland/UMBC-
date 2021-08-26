/*
 * Raymond Rowland
 * 26AUG21
 * Create a program that uses a separate module to calculate sales tax and total after tax.
 * - The program should only accept numbers that are greater than 0.
 * - Use the console.h and console.cpp files described in chapter 7 to validate user entries.
 * - That way, the user can’t crash the program by entering invalid data.
 * - The sales tax rate should be 6% of the total.
 * - Use a header file to declare two functions. One should accept the total of the items and return the tax amount. The other should accept the total of the items and return the total after tax has been added.
 * - Use the implementation file for this header file to store the sales tax rate and the definitions for these two functions. These functions should round the results to two decimal places.
 * - The output should display all monetary values with 2 decimal places.
 * - The output should right align the numbers in the second column. This makes it easier to check whether the calculations are correct.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>

#include "console.h"
#include "Taxes.h"

using namespace std;
using namespace console;

double TotalItems(vector<double> items)
{
	double x = 0;
	for(auto i: items)
	{
		x += i;
	}
	
	return x;
}

void DisplayResults(double total)
{
	const int col_width = 18;
	cout << fixed << setprecision(2) << endl;
	cout << setw(col_width) << left << "Total:" << setw(7) << right << total << endl;
	cout << setw(col_width) << left << "Sales Tax:" << setw(7) << right << Taxes::GetTaxAmount(total) << endl;
	cout << setw(col_width) << left << "Total after tax:" << setw(7) << right << Taxes::GetTotal(total) << endl << endl;
}

int main()
{
	vector<double> items;
	double userInput = 0;
	double itemTotal= 0;
	
	cout << "Sales Tax Calculator\n\n";
	
	do
	{
		items.empty();
		do
		{
			userInput = get_double("Cost of item: ", 0, 1000);
			if(userInput > 0)
			{
				items.push_back(userInput);
			}
		}while(userInput != 0);
		
		DisplayResults(TotalItems(items));
		
	}while(tolower(get_char("Again? (y/n): ")) == 'y'); 
	
	cout << "Thanks, bye!" << endl;
}
