/*
 * Raymond Rowland
 * 01SEP21
 * Ex 16-1
 * Enhance the future value program
 * - Add the console class
 *   - Modify the code so it stores the function declarations in a class names Console instead of the console namespace
 *   - Declare all three functions static with public access
 *   - Change the implementation file for the console to utilize Console class
 * - Create an instance of Console names c and use it's static methods on that object
 * - Add finance class
 *   - Declare calculate_future_value as public static
 *   - Create the definition for calulate_future_value function in the Finance.cpp
 * - Modify the main() so it uses the static calculate_future_value() function that is stored in the finance class.
 */
 
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "console.h"
#include "Finance.h"

using namespace std;



int main() {
    cout << "The Future Value Calculator\n\n";
	Console c;
    char choice = 'y';
    while (tolower(choice) == 'y') {
        // get input
        cout << "INPUT\n";
        double monthly_investment =
            c.get_double("Monthly Investment:   ", 0, 10000);
        double yearly_rate =
            c.get_double("Yearly Interest Rate: ", 0, 30);
        int years =
            c.get_int("Years:                ", 0, 100);
        cout << endl;

        // calculate future value
        double future_value = Finance::calculate_future_value(monthly_investment, yearly_rate, years);

        // display the output to user
        cout << "OUTPUT\n"
            << fixed << setprecision(2)
            << "Monthly Investment:   " << monthly_investment << "\n"
            << fixed << setprecision(1)
            << "Yearly Interest Rate: " << yearly_rate << "\n"
            << "Years:                " << years << "\n"
            << fixed << setprecision(2)
            << "Future Value:         " << future_value << "\n\n";

        // see if the user wants to continue
        choice = c.get_char("Continue? (y/n): ");
    };
    cout << "Bye!\n\n";
}


