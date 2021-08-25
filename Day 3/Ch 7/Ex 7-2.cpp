/*
 * Raymond Rowland
 * 25AUG21
 * Create Account program from Ex 6-2 so it uses two validation functions that are stored in a namespace
 * Create a header file
 * Create an implementation File
 * Update the Main to use the header file
 */
#include <iostream>
#include <string>
#include "validation.h"

using namespace std;
using namespace Validation;

int main()
{
    cout << "Create Account\n\n";

    // get full name and parse first name
    string full_name;
    string first_name;
    bool valid_name = false;
    while (!valid_name) {
        cout << "Enter full name: ";
        getline(cin, full_name);

        // strip whitespace from front
        int i = full_name.find_first_not_of(" \n\t");
        if (i > -1) {
            full_name = full_name.substr(i);
        }

        // get first name
        int space_index = full_name.find(' ');
        if (space_index == -1) {
            cout << "You must enter your full name. Please try again.\n";
        }
        else {
            first_name = full_name.substr(0, space_index);
            valid_name = true;
        }
    }
    cout << endl;

    // get the password
    string password = "";
    do
    {
		// get password
        cout << "Enter password: ";
        getline(cin, password);
    }while (!is_valid_password(password));
    cout << endl;

	// get the email address
	string email = "";
	do
    {
		// get email
		cout << "Enter email: ";
		getline(cin, email);
	}while (!is_valid_email(email));
	cout << endl;

    // make sure first name uses initial cap
    char letter = first_name[0];
    first_name[0] = toupper(letter);
    for (uint i = 1; i < first_name.length(); ++i) {
        letter = first_name[i];
        first_name[i] = tolower(letter);
    }

    // display welcome message
    cout << "Hi " << first_name << ",\n"
        << "Thanks for creating an account!\n\n";
}
