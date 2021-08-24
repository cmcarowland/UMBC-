/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that calculates three options for an appropriate tip to leave after a meal at a restaurant.
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

#define COL_WIDTH 14

using namespace std;

double RoundToTwoPlaces(double val)
{
    return round(val * 100) / 100;
}

void ClearInputStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void PrintTip(int tipPercentage, double costOfMeal)
{
    double tipAmount = costOfMeal * ((double)tipPercentage / 100);
    
    cout << endl << tipPercentage << "%" << endl;
    cout << setw(COL_WIDTH) << "Tip Amount:" << RoundToTwoPlaces(tipAmount) << endl;
    cout << setw(COL_WIDTH) << "Total Amount:" << RoundToTwoPlaces(costOfMeal + tipAmount) << endl;
}

int main()
{
    double mealCost = 0;
    
    cout << "Tip Calculator\n\n";
    
    cout << "Cost of meal: ";
    cin >> mealCost;

    PrintTip(15, mealCost);
    PrintTip(20, mealCost);
    PrintTip(25, mealCost);
}
