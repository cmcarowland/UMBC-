/*
 * Raymond Rowland
 * 31AUG21
 * Ex 14-2
 * - Create an objected oriented Convert Temperatures program
 * - Create an object named Temp with:
 *   - two private doubles for C and F
 *   - Getters and setters for private members
 *   - Default constructor that creates the object with water freezing point 32 f 0 c
 *   - Round all conversions to 2 places
 */

#include <iostream>
#include <cmath>
#include "Temp.h"

using namespace std;

// declare functions
void display_menu();
void convert_temp();
double to_celsius(double fahrenheit);
double to_fahrenheit(double celsius);

int main() {

	cout << "Convert Temperatures\n\n";

    display_menu();
    char again = 'y';
    while (again == 'y') {
        convert_temp();

        cout << "Convert another temperature? (y/n): ";
        cin >> again;
        cout << endl;
    }
    cout << "Bye!\n";
}

/****************************************************
* Define functions
*****************************************************/

void display_menu() {
    cout << "MENU\n"
        << "1. Fahrenheit to Celsius\n"
        << "2. Celsius to Fahrenheit\n\n";
}

void convert_temp() {
    int option;
    cout << "Enter a menu option: ";
    cin >> option;

    double userInput = 0.0;
    Temp t;
    
    switch (option) {
    case 1:
        cout << "Enter degrees Fahrenheit: ";
        cin >> userInput;

		t.set_fahrenheit(userInput);

        cout << "Degrees Celsius: " << t.get_celsius() << endl;
        break;
    case 2:
        cout << "Enter degrees Celsius: ";
        cin >> userInput;

		t.set_celsius(userInput);

        cout << "Degrees Fahrenheit: " << t.get_fahrenheit() << endl;
        break;
    default:
        cout << "You must enter a valid menu number.\n";
        break;
    }
}

