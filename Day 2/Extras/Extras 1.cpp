/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that calculates the sum of all integers between and including the two entered integers.
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
    int start = 0;
    int stop = 0;
    int result = 0;

    cout << "Enter start number: ";
    cin >> start;
    ClearInputStream();
    
    cout << "Enter stop number: ";
    cin >> stop;
    ClearInputStream();
    
    for(int i = start; i <= stop; i++)
    {
        result += i;
    }
    
    cout << "Sum : " << result << endl;
}
