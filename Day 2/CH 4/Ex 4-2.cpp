/*
 * Raymond Rowland
 * 24AUG21
 * Enhance the Future Value Program
 * Modify the program to loop and show the future value for each year
 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "The Future Value Calculator\n\n";

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        double monthly_investment;
        cout << "Enter monthly investment:   ";
        cin >> monthly_investment;

        double yearly_rate;
        cout << "Enter yearly interest rate: ";
        cin >> yearly_rate;

        int years;
        cout << "Enter number of years:      ";
        cin >> years;
        cin.ignore(100, '\n');
        cout << endl;

        // convert yearly values to monthly values
        double monthly_rate = yearly_rate / 12 / 100;
        int months = years * 12;

        // calculate future value
        double future_value = 0;
        for (int i = 1; i <= months; i++) {
            future_value = (future_value + monthly_investment) * (1 + monthly_rate);
            if(i % 12 == 0)
            {
                cout << "Year " << i / 12 << " Future Value = " << round(future_value * 100) / 100 << endl;
            }
        }

        // see if the user wants to continue
        cout << endl << "Continue? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    cout << "Bye! ";
}
