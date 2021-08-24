#include <iostream>
#include <cmath>

using namespace std;

template
<typename T> T RoundToTwoPlaces(T inputAmount)
{
    return round(inputAmount * 100) / 100;
}

int main()
{
    double costOfMeal = 0;
    double tipPercent = 0;
    double tipAmount = 0;
    double totalAmount = 0;
    
    cout << "Paycheck Calculator\n\n";
    
    cout << "Cost Of Meal : ";
    cin >> costOfMeal;
    cout << "Tip Percent  : ";
    cin >> tipPercent;
    
    tipAmount = costOfMeal * (tipPercent / 100);
    totalAmount = costOfMeal + tipAmount;
    
    
    cout << endl << "Tip Amount       : " << RoundToTwoPlaces<double>(tipAmount) << endl; 
    cout << "Total Amount     : " << RoundToTwoPlaces<double>(totalAmount) << endl;

}
