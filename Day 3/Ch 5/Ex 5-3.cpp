/*
 * Raymond Rowland
 * 24AUG21
 * Write a program that uses stringstream to handle unexpected data from data in the file.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

#define COL_WIDTH 12

int main()
{
    string name = "";
    double hourlyWage = 0;
    double hours = 0;
    string line = "";
    int unprocessedLines = 0;
    
    cout << left << setw(COL_WIDTH) << "Name" << right << setw(COL_WIDTH) << "Hourly Wage" << setw(COL_WIDTH) << "Hours" << setw(COL_WIDTH) << "Total" << endl;
    cout << left << setw(COL_WIDTH) << "-----------"  << right << setw(COL_WIDTH) << "-----------" << setw(COL_WIDTH) << "-----------" << setw(COL_WIDTH) << "-----------" << endl;
    
	ifstream infile;
    stringstream ss;
	infile.open("wages.txt");
	if (infile) {
        cout << fixed << setprecision(2);
        while(getline(infile, line))
        {
            ss.str(line);
            ss.clear();
            if(ss >> name >> hourlyWage >> hours)
            {
                cout << left << setw(COL_WIDTH) << name << right << setw(COL_WIDTH) << hourlyWage << setw(COL_WIDTH) << hours << setw(COL_WIDTH) << hours * hourlyWage << endl;
            }
            else
            {
                unprocessedLines ++;
            }
        }
    }
        
    infile.close();
    
    cout << endl << unprocessedLines << " lines not processed." << endl;
}

