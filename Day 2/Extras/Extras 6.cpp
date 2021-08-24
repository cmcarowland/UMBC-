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

int GetRandomSales()
{
    int r = rand() % 10;
    return r;
}

string months[] = {"Janurary", "February","March","April","May","June","July","August","September","October","November","December"};
int booksSold[3][12] = {0};


int main()
{
    srand(time(nullptr));
    
    int annualIncome = 0;
    int yearSold[3] = {0};
    
    cout << "Enter Number of books sold per month" << endl;
    for(int y = 0; y < 3; y ++)
    {
        cout << endl << "Year " << y + 1 << endl;
        for(int i = 0; i < 12; i++)
        {
            cout << setw(COL_WIDTH) << months[i] << ": ";
            cin >> booksSold[y][i];
            ClearInputStream();
            
            yearSold[y] += booksSold[y][i];
        }
    }
    
    for(int y = 0; y < 3; y ++)
    {
        cout << endl << "Year " << y + 1 << " Sales : " << yearSold[y] << endl;
        annualIncome += yearSold[y];
    }
    
    cout << endl << "Total Sales : " << annualIncome << endl;
}
