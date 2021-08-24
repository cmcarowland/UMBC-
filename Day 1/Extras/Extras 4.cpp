#include <iostream>

using namespace std;


int main()
{
    int age = 0;
    int ageInMonths = 0;
    
    cout << "Enter Your Age: ";
    cin >> age;
    
    ageInMonths = age * 12;
    
    cout << "Your Age In Months is " << ageInMonths << endl;
}
