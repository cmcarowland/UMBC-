/*
Raymond Rowland
Ex 17-1
Use points with built-in arrays
- Define an array names weights that can store a value for each month, and initialize the values to 0.0
- Declare a function named get_monthly_weights that accepts a pointer to the weights array, 
a pointer to the months array, and the number of months and return a double
- Define a function called get_totals that takes the weights array and number of months and returns the total
- Replace the get_total function with the accumulate algorithm
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

double get_total(double *weights, int numOfMonths)
{
	if(weights == nullptr)
	{
		cout << "Initialize the arrays first" << endl;
		return 0;
	}

	double total = 0;
	for(int i = 0; i < numOfMonths; i++)
	{
		total += weights[i];
	}

	return total;
}

void get_monthly_weights(string *months, double *weights, int numOfMonths)
{
	if(months == nullptr || weights == nullptr)
	{
		cout << "Initialize the arrays first" << endl;
		return;
	}
	
	for(int i = 0; i < numOfMonths; i ++)
	{
		cout << "Enter weight in " + months[i] + ": ";
		cin >> weights[i];
	}
}

int main()
{
	const int num_months = 12;
	string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	double weights[num_months] = { 0.0 };

	cout << "Welcome to the Weight Tracker program!\n\n"
		 << "Please enter your weight at the beginning of each month:\n";

	get_monthly_weights(months, weights, num_months);
	double total = accumulate(weights, weights + num_months, 0.0);
	double average = total / num_months;

	cout << endl << setprecision(1) << fixed;
	cout << "Maximum weight: " << *max_element(weights, weights + num_months) << endl;
	cout << "Minimum weight: " << *min_element(weights, weights + num_months) << endl;
	cout << "Average weight: " <<  average << endl;
}
