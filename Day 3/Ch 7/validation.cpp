#include "validation.h"

namespace Validation
{
    bool is_valid_password(string password)
    {
        // make sure password has at least 8 characters
        if (password.length() < 8) {
            cout << "Password must be at least 8 characters.\n";
            return false;
        }

        // make sure password includes a number
        int index = password.find_first_of("0123456789");
        if (index == -1) {
            cout << "Password must include a number.\n";
            return false;
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
            return false;
        }
        
        return true;
    }

    bool is_valid_email(string email)
    {
        // make sure there is an at sign
        int at_index = email.find('@');
        if (at_index == -1) {
            cout << "The email must include an at character (@).\n";
            return false;
        }

        // make sure there is a dot operator by getting the last dot operator
        int dot_index = email.rfind('.');
        if (dot_index == -1) {
            cout << "The email must include a dot operator (.).\n";
            return false;
        }

        // make sure the remaining characters are alphanumeric
        bool valid_chars = true;
        for (char c : email) {
            if (c != '@' && c != '.' && c != '_' && c!= '-' ) {
                if (!isalnum(c)) {
                    valid_chars = false;
                    break;
                }
            }
        }
        if (!valid_chars) {
            cout << "The email contains invalid characters.\n";
            return false;
        }

        // make sure there is at least one character before the at sign
        if (at_index == 0) {
            cout << "The local part of the email must include at least one character.\n";
            return false;
        }
        
        // make sure there is at least one character before the dot operator
        if (dot_index - at_index == 1) {
            cout << "The server name of the email must include at least one character.\n";
            return false;
        }

        // make sure the domain name has two or three characters
        if (email.length() - dot_index - 1 != 3 && email.length() - dot_index - 1 != 2) {
            cout << "The domain name of the email must have two or three characters.\n";
            return false;
        }
        
        return true;
    }
}
