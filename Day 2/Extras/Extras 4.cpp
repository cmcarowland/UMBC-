/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that Determines the time when Cleos investment surpasses Daphnes value
 * Daphne 100 @ 10%
 * Cleo 100 @ 5% 
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

#define COL_WIDTH 20

using namespace std;

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

int main()
{
    const int daphneInterest = 10;
    double daphneBalance = 100;
    
    const double cleoInterest = 0.05;
    double cleoBalance = 100;
    int year = 1;
    
    do
    {    
        daphneBalance += daphneInterest;
        cleoBalance += cleoBalance * cleoInterest;
        year++;
    }while(cleoBalance <= daphneBalance);
    
    cout << endl << "Years to overcome " << year << endl;
    cout << "Cleo Balance   " << cleoBalance << endl;
    cout << "Daphne Balance " << daphneBalance << endl;
}
