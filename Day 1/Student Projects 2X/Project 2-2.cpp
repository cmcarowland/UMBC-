#include <iostream>
#include <cmath>

using namespace std;

#define TAX_RATE 0.18

template
<typename T> T RoundToTwoPlaces(T inputAmount)
{
    return round(inputAmount * 100) / 100;
}

int main()
{
    double grossPay = 0;
    double hoursWorked = 0;
    double hourlyRate = 0;
    double taxAmount = 0;
    double takeHomePay = 0;
    
    cout << "Paycheck Calculator\n\n";
    
    cout << "Hours Worked   : ";
    cin >> hoursWorked;
    cout << "Hourly Pay Rate: ";
    cin >> hourlyRate;
    
    grossPay = hoursWorked * hourlyRate;
    taxAmount = grossPay * TAX_RATE;
    takeHomePay = grossPay - taxAmount;
    
    
    cout << endl << "Gross Pay    : " << RoundToTwoPlaces<double>(grossPay) << endl; 
    cout << "Tax Rate     : " << TAX_RATE * 100 << '%' << endl;
    cout << "Tax Amount   : " << RoundToTwoPlaces<double>(taxAmount) << endl;
    cout << "Take Home Pay: " << RoundToTwoPlaces<double>(takeHomePay) << endl;
}
