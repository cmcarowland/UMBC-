/*
 * Raymond Rowland
 * 25AUG21
 * Modify Future Value program so that it stores the values in a vector and displays a table at the end.
 * 
 */
#include "Ex 6-1.h"

int main() {
    vector<Investment> investments;
    
    cout << "The Future Value Calculator\n\n";

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        double monthly_investment;
        cout << left << setw(COL_WIDTH) << "Enter monthly investment:   ";
        cin >> monthly_investment;

        double yearly_rate;
        cout << left << setw(COL_WIDTH) << "Enter yearly interest rate: ";
        cin >> yearly_rate;

        int years;
        cout << left << setw(COL_WIDTH) << "Enter number of years:      ";
        cin >> years;
        
        Investment i = Investment(monthly_investment, yearly_rate, years);
        cout << left << setw(COL_WIDTH) << "Future Value:" << right << i.CalculateFutureValue() << endl << endl;
        investments.push_back(i);

        // see if the user wants to continue
        cout << "Continue? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    
    
    cout << setw(10) << "Monthly" << setw(8) << "Yearly" << endl;
    cout << setw(10) << "investment" 
         << setw(8) << "rate" 
         << setw(7) << "Years"
         << setw(14) << "Future Value" << endl;
         
    for(uint i = 0; i < investments.size(); i ++)
    {
        investments[i].Print();
    }
}
