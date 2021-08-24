/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that uses type array instead of built-in array and type long double instead of long long
 * Find the value of 100!
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
    
}
