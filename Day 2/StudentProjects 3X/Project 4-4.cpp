/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that displays a table of squares and cubes for the specified range of numbers.
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

#define COL_WIDTH 20

using namespace std;


void ClearInputStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    double start = 0;
    double stop = 0;
    
    cout << "Table of Powers\n\n";
    
    do
    {
        start = 0;
        stop = 0;
    
        cout << "Enter start number: ";
        cin >> start;
        ClearInputStream();
        
        cout << "Enter stop number: ";
        cin >> stop;
        ClearInputStream();

        if(start >= stop)
        {
            cout << "Start number must be less than stop number." << endl << "Please try again.\n" << endl;
        }
    }while(start >= stop);
    
    //Header 
    cout << endl << "Number\tSquared\tCubed" << endl;
    cout << "======\t======\t======" << endl;
    for(int i = start; i <= stop; i++)
    {
        cout << i << "\t" << i * i << "\t" << i * i * i << endl;
    }
}
