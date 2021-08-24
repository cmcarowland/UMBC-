#include <iostream>

using namespace std;


void PrintTime(int  _hours, int _minutes)
{
    cout << _hours << ":" << _minutes << endl;
}

int main()
{
    int hours = 0;
    int minutes = 0;
    
    cout << "Enter the number of hours: ";
    cin >> hours;
    
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    
    PrintTime(hours, minutes);
}
