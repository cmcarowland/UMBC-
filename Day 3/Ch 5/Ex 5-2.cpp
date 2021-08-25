/*
 * Raymond Rowland
 * 25AUG21
 * Modify a program that calculates MPG so it :
 *   - Starts by displaying the data in the trips.txt file
 *   - Shows all file data after a new addition
 *   - Shows total miles, gallons and Average MPG
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <fstream>

using namespace std;

#define COL_WIDTH 12
#define TOTAL_WIDTH 18

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

void PrintMPGDataFromFile()
{
    double miles = 0;
    double gallons = 0;
    double totalMiles = 0;
    double totalGallons = 0;
    
    cout << setw(COL_WIDTH) << "Miles" << setw(COL_WIDTH) << "Gallons" << setw(COL_WIDTH) << "MPG" << endl;
    
    ifstream iFile("trips.txt");
    if(iFile)
    {
        cout << fixed << setprecision(1);
        while(iFile >> miles >> gallons)
        {
            totalMiles += miles;
            totalGallons += gallons;
            cout << setw(COL_WIDTH) << setprecision(1) << miles << setw(COL_WIDTH) << gallons << setw(COL_WIDTH) << setprecision(2) << miles / gallons << endl;
        }
    }
    
    iFile.close();
    
    cout << setprecision(2) << endl;
    cout << setw(TOTAL_WIDTH) << left << "Total Miles:"  << right << totalMiles << endl;
    cout << setw(TOTAL_WIDTH) << left << "Total gallons:" << right << totalGallons << endl;
    cout << setw(TOTAL_WIDTH) << left << "Average MPG: " << right << totalMiles / totalGallons << endl << endl;
}

int main()
{
    double miles = 0;
    double gallons = 0;
	char another_entry = 'y';
	
    // print name of program
	cout << "Miles Per Gallon\n\n";
    PrintMPGDataFromFile();
    
    
	
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

        PrintMPGDataFromFile();
		// see if the user wants to enter more data
		cout << "Get entries for another trip? (y/n): ";
		cin >> another_entry;
        cout << endl;
	}

	cout << "Bye!\n\n";
}
