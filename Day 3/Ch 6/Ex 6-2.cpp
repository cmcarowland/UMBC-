/*
 * Raymond Rowland
 * 25AUG21
 * Create an account program so it accepts an email address from the user the checks to make sure it is valid.
 * 
 */
#include <iostream>
#include <string>

using namespace std;

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
    string password;
    bool valid_password = false;
    while (!valid_password) {

        // set valid flag
        valid_password = true;

		// get password
        cout << "Enter password: ";
        getline(cin, password);

        // make sure password has at least 8 characters
        if (password.length() < 8) {
            cout << "Password must be at least 8 characters.\n";
            valid_password = false;
        }

        // make sure password includes a number
        int index = password.find_first_of("0123456789");
        if (index == -1) {
            cout << "Password must include a number.\n";
            valid_password = false;
        }

        // make sure password includes a special character
        bool special_character = false;
        for (char c : password) {
            if (ispunct(c)) {
                special_character = true;
                break;                      // exit for loop
            }
        }
        if (!special_character) {
            cout << "Password must include a special character.\n";
            valid_password = false;
        }

        // display message if password is not valid
        if (!valid_password) {
            cout << "Please try again.\n";
        }
    }
    cout << endl;
    
    // get the email
    string email;
    bool valid_email = false;
    while (!valid_email) {

        // set valid flag
        valid_email = true;

		// get password
        cout << "Enter email: ";
        getline(cin, email);

        // make sure email has at least 7 characters
        if (email.length() < 7) {
            cout << "Email missing characters.\nPlease provide at least X@X.XX\n";
            valid_email = false;
        }

        // make sure password includes a number
        int atIndex = email.find_first_of("@");
        if (atIndex == -1) {
            cout << "Email must include a '@'.\n";
            valid_email = false;
        }
        else
        {
            if(atIndex < 1)
            {
                cout << "Email have character before the '@'.\n";
                valid_email = false;
            }
        }

        int dotIndex = email.find(".", atIndex);
        if (dotIndex == -1) {
            cout << "Email domain must include a '.'.\n";
            valid_email = false;
        }
        
        if((email.length - 1) - dotIndex < 2)
        {
            cout << "Email domain must be at least 2 characters.\n";
            valid_email = false;
        }

        // display message if password is not valid
        if (!valid_email) {
            cout << "Please try again.\n";
        }
    }
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
