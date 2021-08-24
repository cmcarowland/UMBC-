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

string months[] = {"Janurary", "February","March","April","May","June","July","August","September","October","November","December"};
int booksSold[12] = {0};

int main()
{
    srand(time(nullptr));
    
    int annualIncome = 0;
    
    cout << "Enter Number of books sold per month" << endl;

    for(int i = 0; i < 12; i++)
    {
        cout << setw(COL_WIDTH) << months[i] << ": ";
        cin >> booksSold[i];
        ClearInputStream();
    }
    
    for(int i = 0; i < 12; i++)
    {
        annualIncome += booksSold[i];
    }
    
    cout << endl << "Total Sales : " << annualIncome << endl;
}
