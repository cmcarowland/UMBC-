/*
 * Raymond Rowland
 * 25AUG21
 * Create a program that reads the sales for 12 months from a file and calculates the total yearly sales as well as the average monthly sales.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

void PrintMonthly()
{
	const int col_width = 11;
	stringstream ss;
	string line = "";
	string month = "";
	double average = 0;

	cout << "MONTHLY SALES" << endl;

	cout << fixed << setprecision(2);
	ifstream iFile("monthly_sales.txt");
	if(iFile)
	{
		while(getline(iFile, line))
		{
			ss.str(line);
			ss.clear();
			if(ss >> month >> average)
			{
				cout << left << setw(col_width) << month << right << setw(col_width) << average << endl;
			}
		}
	}

	iFile.close();
	cout << endl;
}

void PrintYearly()
{
	const int col_width = 16;
	stringstream ss;
	string line = "";
	string month = "";
	double average = 0;
	double total = 0;
	int months = 0;
	

	cout << "YEARLY SUMMARY" << endl;

	cout << fixed << setprecision(2);
	ifstream iFile("monthly_sales.txt");
	if(iFile)
	{
		while(getline(iFile, line))
		{
			ss.str(line);
			ss.clear();
			if(ss >> month >> average)
			{
				months ++;
				total += average;
			}
		}
	}

	iFile.close();
	average = total / months;
	
	cout << left << setw(col_width) << "Yearly total:" << right << setw(col_width) << total << endl;
	cout << left << setw(col_width) << "Monthly Average:" << right << setw(col_width) << average << endl << endl;
}

void PrintMenu()
{
	cout << "COMMAND MENU" << endl;
	cout << "m - View monthly sales" << endl;
	cout << "y - View yearly summary" << endl;
	cout << "x - Exit Program" << endl << endl; 
	cout << "Command: ";
}

void ClearInputStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
	char userInput = ' ';
	
	while(userInput != 'x')
	{
		PrintMenu();
		cin >> userInput;
		ClearInputStream();
		cout << endl;
		
		switch(userInput)
		{
			case 'm':
				PrintMonthly();
				break;
			case 'y':
				PrintYearly();
				break;
			default:
				cout << "Invalid menu option selected. Please try again." << endl;
		}
	}
	
	
}
