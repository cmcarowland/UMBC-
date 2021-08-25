/*
 * Raymond Rowland
 * 25AUG21
 * Modify a program that calculates MPG so it :
 *   - validates the data entered by the user
 *      -Discards any extra input
 *      -Validate numbers, print error message if invalid, clear the error bits, discard extra data
 *   - stores the data for each calculation in a tab-delimited file
 *      -Trim values to one decimal digit
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <fstream>

using namespace std;

void ClearInputStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

template <typename T> 
T GetInputData(string prompt, string dataTypeString)
{
    T outputData;
    do
    {
        cout << prompt;
        cin >> outputData;
        
        if(cin)
        {
            ClearInputStream();
            return outputData;
        }
        else if(cin.fail())
        {
            cout << "Invalid entry.  Please enter a " << dataTypeString << endl << endl;
            ClearInputStream();
        }
    }
    while(true);
}

void WriteToFile(double miles, double gallons)
{
    ofstream oFile("trips.txt", ios::app);
    
    oFile << fixed << setprecision(1);
    oFile << miles << '\t' << gallons << endl;
    oFile.close(); 
}

int main()
{
	// print name of program
	cout << "Miles Per Gallon\n\n";
    double miles = 0;
    double gallons = 0;
	char another_entry = 'y';
	
    while (tolower(another_entry) == 'y') {
        miles = 0;
        gallons = 0;

		// get miles driven
		while (true) {
			miles = GetInputData<double>("Enter miles driven: ", "double Ex. X.X");

			// check the range of the number
			if (miles <= 0) {
				cout << "Miles driven must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}

		// get gallons of gas used
		while (true) {
			gallons = GetInputData<double>("Enter gallons of gas used: ", "double Ex. X.X");

			// check the range of the number
			if (gallons <= 0) {
				cout << "Gallons used must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}
        
        WriteToFile(miles, gallons);

		// calculate miles per gallon
		double mpg = miles / gallons;
		mpg = round(mpg * 100) / 100;
		cout << "Miles per gallon:          " << mpg << endl << endl;

		// see if the user wants to enter more data
		cout << "Get entries for another trip? (y/n): ";
		cin >> another_entry;
        cout << endl;
	}

	cout << "Bye!\n\n";
}
