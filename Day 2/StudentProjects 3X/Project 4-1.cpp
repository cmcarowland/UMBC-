/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that calculates the coins needed to make change for the specified number of cents.
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

bool ShouldRunAgain()
{
    char response = 'y';
    
    cout << "Continue? (y/n): ";
    cin.get(response);
    ClearInputStream();
    
    if(tolower(response) == 'y')
    {
        cout << endl;
        return true;
    }
        
    return false;
}

int GetNumberOfQuarters(int &change)
{
    int quart = change / 25;
    change -= quart * 25;
    return quart;
}

int GetNumberOfDimes(int &change)
{
    int dime = change / 10;
    change -= dime * 10;
    return dime;
}

int GetNumberOfNickels(int &change)
{
    int nick = change / 5;
    change -= nick * 5;
    return nick;
}

void PrintChange(int change)
{    
    cout << setw(COL_WIDTH) << "Quarters:" << GetNumberOfQuarters(change) << endl;
    cout << setw(COL_WIDTH) << "Dimes:" << GetNumberOfDimes(change) << endl;
    cout << setw(COL_WIDTH) << "Nickels:" << GetNumberOfNickels(change) << endl;
    cout << setw(COL_WIDTH) << "Pennies:" << change << endl << endl;
}

int main()
{
    double numOfCents = 0;
    
    cout << "Change Calculator\n\n";
    
    do
    {
        numOfCents = 0;
    
    cout << "Enter number of cents (0-99): ";
    cin >> numOfCents;
    ClearInputStream();

    
    PrintChange(numOfCents);
    }while(ShouldRunAgain());
    
    cout << endl << "Bye!\n";
}
