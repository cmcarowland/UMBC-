/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that sums the values of the users entries
 * Terminate when the user enters 0
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
    int input = 0;
    int result = 0;
    
    do
    {
        cout << "Enter number: ";
        cin >> input;
        ClearInputStream();
    
        result += input;
        cout << "Sum : " << result << endl << endl;
    }while(input != 0);
    
    cout << endl << "Total Sum is " << result << endl;
}
