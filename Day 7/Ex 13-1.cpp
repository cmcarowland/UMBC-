/*
 * Raymond Rowland
 * 31AUG21
 * Ex 13-1
 * Add exception handling to the convert temperatures program.
 * - Modify the to_celsius function so an invalid argument is thrown if the temperature is less than 32 or greater than 212
 * - Modify the to_fahrenheit function so an invalid argument is thrown if the temperature is less than 0 or greater than 100
 * - Modify the convert_temp function so it catches the exception thrown by the to_celsius and to_fahrenheit function.  
 */
#include <iostream>
#include <cmath>

using namespace std;

// declare functions
void display_menu();
void convert_temp();
double to_celsius(double fahrenheit);
double to_fahrenheit(double celsius);

int main() {

	cout << "Convert Temperatures\n\n";

    display_menu();
    char again = 'y';
    while (again == 'y') {
        convert_temp();

        cout << "Convert another temperature? (y/n): ";
        cin >> again;
        cout << endl;
    }
    cout << "Bye!\n";
}

// define functions
void display_menu() {
    cout << "MENU\n"
        << "1. Fahrenheit to Celsius\n"
        << "2. Celsius to Fahrenheit\n\n";
}

void convert_temp() {
    int option;
    cout << "Enter a menu option: ";
    cin >> option;

    double f = 0.0;
    double c = 0.0;
    switch (option) {
    case 1:
        cout << "Enter degrees Fahrenheit: ";
        cin >> f;
		try
		{
			c = to_celsius(f);
		}
		catch(const invalid_argument& e)
		{
			cout << e.what() << endl << endl;
			return;
		}
		
        c = round(c * 10) / 10;

        cout << "Degrees Celsius: " << c << endl << endl;
        break;
    case 2:
        cout << "Enter degrees Celsius: ";
        cin >> c;
		try
		{
			f = to_fahrenheit(c);
		}
		catch(const invalid_argument& e)
		{
			cout << e.what() << endl << endl;
			return;
		}
		
		f = round(f * 10) / 10;

        cout << "Degrees Fahrenheit: " << f << endl << endl;
        break;
    default:
        cout << "You must enter a valid menu number.\n";
        break;
    }
}

double to_celsius(double fahrenheit) 
{
	if(fahrenheit < 32 || fahrenheit > 212)
	{
		throw invalid_argument("Error! Temperature must be from 32 to 212");
    }
    
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

double to_fahrenheit(double celsius) 
{
	if(celsius < 0 || celsius > 100)
	{
		throw invalid_argument("Error! Temperature must be from 0 to 100");
	}
	
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    return fahrenheit;
}
