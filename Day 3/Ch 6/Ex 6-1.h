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
