/*
 * Raymond Rowland
 * 25AUG21
 * Modify Future Value program so that it stores the values in a vector and displays a table at the end.
 * 
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
#define COL_WIDTH 23
#define TABLE_WIDTH 11

class Investment
{
        public:
            double investment;
            double interestRate;
            int years;
            
            Investment(double _investment, double _interestRate, int _years)
            {
                investment = _investment;
                interestRate = _interestRate;
                years = _years;
            }
            
            double CalculateFutureValue()
            {
                double future_value = 0;
                int months = years * 12;
                double monthlyRate = interestRate / 12 / 100;
                
                for (int i = 1; i <= months; i++) {
                    future_value = (future_value + investment) * (1 + monthlyRate);
                }
                
                return future_value;
            }
            
            void Print()
            {
                cout << fixed << setprecision(2);
                cout << setw(10) << investment 
                     << setw(8) << interestRate;
                cout << setprecision(0)
                     << setw(7) << years;
                cout << setprecision(2)
                     << setw(14) << CalculateFutureValue() << endl;
            }
            
};

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
