/*
 * Raymond Rowland
 * 23AUG21
 * Crate a Guest Book 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Guest{
    public:
        string firstName = "";
        char middleName = ' ';
        string lastName = "";
        string address = "";
        string city = "";
        string state = "";
        string postalCode = "";
        string country = "";
        
        Guest()
        {
            cout << "New Guest\n";
            GetFirstName();
            GetMI();
            GetLastName();
            GetAddress();
            GetCity();
            GetState();
            GetPostalCode();
            GetCountry();
            cout << endl << endl;
        }
        
        void PrintGuest()
        {
            cout << "\nENTRY\n" 
                << firstName + " " + middleName + ". " + lastName << endl
                << address << endl 
                << city + ", " + state + " " + postalCode << endl 
                << country + "\n";
        }
        
        
    private:
        void GetFirstName()
        {
            cout << "First Name \t: ";
            getline(cin, firstName);
        }
        
        void GetMI()
        {
            cout << "Middle Initial \t: ";
            middleName = cin.get();
            cin.ignore(100, '\n');
        }
        
        void GetLastName()
        {
            cout << "Last Name \t: ";
            getline(cin, lastName);
        }
        
        void GetCity()
        {
            cout << "City \t: ";
            getline(cin, city);
        }
        
        void GetCountry()
        {
            cout << "Country \t: ";
            getline(cin, country);
        }
        
        void GetState()
        {
            cout << "State \t: ";
            state = "";
            state += cin.get();
            state += cin.get();
            cin.ignore(100, '\n');
        }
        
        void GetPostalCode()
        {
            cout << "Postal Code \t: ";
            getline(cin, postalCode);
        }
        
        void GetAddress()
        {
            cout << "Address \t: ";
            getline(cin, address);
        }
};

int main()
{
	cout << "Guest Book\n\n";
    vector<Guest> guests; 
    
    Guest g = Guest();
    guests.push_back(g);
    
    //Use this to add a second Guest.
    //g = Guest();
    //guests.push_back(g);

    for(uint i = 0; i < guests.size(); i++)
    {
        guests[i].PrintGuest();
    }
}
