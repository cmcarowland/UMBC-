#include <iostream>

using namespace std;

int main()
{
    string firstName = "";
    string lastName = "";
    uint yearOfBirth = 0;
    string tempPW = "";
    
    cout << "Registration Form\n\n";
    
    cout << "First Name: ";
    cin >> firstName;
    
    cout << "Last Name: ";
    cin >> lastName;
    
    cout << "Birth Year: ";
    cin >> yearOfBirth;
    
    tempPW = firstName + "*" + to_string(yearOfBirth);
    
    cout << endl << "Welcome " + firstName + "!" << endl; 
    cout << "Your Registration Is Complete." << endl;
    cout << "Name : " << firstName + " " + lastName << endl;
    cout << "Temporary Password: " << tempPW << endl << endl;
}
