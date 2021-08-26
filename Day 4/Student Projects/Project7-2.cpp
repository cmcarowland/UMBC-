/*
 * Raymond Rowland
 * 26AUG21
 * Create a program that converts the number of miles that you walked on a hike to the number of feet that you walked.
 */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double MilesToFeet(const double &num)
{
	return num * 1520;
}

int main()
{
	cout << "Hike Calculator\n\n";
	
	double userInput = 0;
	cout << "How many miles did you walk?: ";
	cin >> userInput;
	
	cout << "You Walked " << MilesToFeet(userInput) << " feet." << endl;
	
}
