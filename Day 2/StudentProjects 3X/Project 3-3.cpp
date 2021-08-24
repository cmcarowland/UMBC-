/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that allows you to perform simple calculations.
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define COL_WIDTH 18

bool IsLeapYear(int year)
{
    if(year % 4 == 0)  
    {
        if(year % 100 != 0)
        {
            return true;
        }
        else if(year % 400 == 0)
        {
            return true;
        }
    }   
        
    return false;
}

string GetMonthName(int month)
{
    switch(month)
    {
        case 1:
            return "Janurary";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
    }
    
    return "Invalid month number";
}

int GetDaysInMonth(int month, int year)
{
    switch(month)
    {
        case 1:
            return 31;
        case 2:
            if(IsLeapYear(year))
                return 29;
            else
                return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }    
    
    return 0;
}

int main()
{
    cout << "Month Selector\n\n";
    
    int year = 0;
    int month = 0;
    
    cout << setw(COL_WIDTH) << "Enter Year" << ": ";
    cin >> year;
    
    cout << setw(COL_WIDTH) << "Enter Month (1-12)" << ": ";
    cin >> month;

    cout << setw(COL_WIDTH) << "Month Name" << ": " << GetMonthName(month) << endl;
    cout << setw(COL_WIDTH) << "Days In Month" << ": " << GetDaysInMonth(month, year) << endl;
}
