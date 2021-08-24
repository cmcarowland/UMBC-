/*
 * Raymond Rowland
 * 23AUG21
 * Convert Gallons to different units 
 */
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

double RoundToTwoPlaces(double inputAmount)
{
    return round(inputAmount * 100) / 100;
}

int main()
{
    // print name of program
    cout << "Gallons Converter" << endl << endl;

    // get gallons from user
    double gallons;
    cout << "Enter gallons: ";
    cin >> gallons;

    // convert gallons to liters
    double liters = gallons * 3.7854;
    double quarts = gallons * 4;
    double ounces = gallons * 128;
    

    // write output to console
    cout << "Liters:        " << RoundToTwoPlaces(liters) << endl;

    cout << "Quarts:        " << RoundToTwoPlaces(quarts) << endl;
    
    cout << "Ounces:        " << RoundToTwoPlaces(ounces) << endl << endl;
    
    cout << "Bye!\n";
    // return value that indicates normal program exit
    return 0;
}
