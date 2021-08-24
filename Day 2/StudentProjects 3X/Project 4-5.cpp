/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that calculates the factorial of the number entered by the user.
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

int Factorial(int numToFact)
{
    int result = 1;
    while(numToFact != 0)
    {
        result *= numToFact;
        numToFact--;
    }
    
    return result;
}

int main()
{
    int numToFact = 0;
    
    cout << "Factorial Calculator\n\n";
    
    do
    {
        cout << "Enter an integer(1-10): ";
        cin >> numToFact;
        ClearInputStream();
            
        cout << endl << "The factorial of " << numToFact << " is " << Factorial(numToFact) << endl;
    }while(ShouldRunAgain());
}

