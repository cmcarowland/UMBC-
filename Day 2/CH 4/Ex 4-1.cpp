/*
 * Raymond Rowland
 * 24AUG21
 * 
 */
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::round;
using std::string;
using std::tolower;

bool running = true;

bool ShouldRunAgain()
{
    char response = 'y';
    
    cout << "Enter another radius? (y/n) : ";
    cin.get(response);
    cin.ignore(100, '\n');
    
    if(tolower(response) == 'y')
        return true;
        
    return false;
}


int main()
{
     // print name of program
    cout << "Circle Calculator" << endl << endl;
    
    do
    {
        // get radius from user
        double radius;
        cout << "Enter radius:  ";
        cin >> radius;
        cin.ignore(100, '\n');
        
        if(radius <= 0)
        {
            cout << "Radius must be a positive number.\n\n";
            continue;
        }

        // make calculations
        double pi = 3.14159;
        double diameter = 2 * radius;
        double circumference = diameter * pi;
        double area = pi * pow(radius, 2.0);

        // round to 1 decimal place
        circumference = round(circumference * 10) / 10;
        area = round(area * 10) / 10;

        // write output to console
        cout << "Diameter:      " << diameter << endl
            << "Circumference: " << circumference << endl
            << "Area:          " << area << endl << endl;
            
        running = ShouldRunAgain();
        cout << endl;
    }while(running);

    cout << "Bye!" << endl;
	// return value that indicates normal program exit
    return 0;
}
