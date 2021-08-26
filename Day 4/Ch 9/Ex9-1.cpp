/*
 * Raymond Rowland
 * 26AUG21
 * Use a structure to create account program
 *  - Define a structure names Account
 *    - 4 string members first, last, pw and email
 *  - Define function read_accounts_from_file()
 *    - Create account object for each account in tab-delimited accounts.txt
 *    - Uses a vector to hold all accounts
 * - Modify display accounts function to accept the vector of Accounts and modify code to display the data in the vector
 * - Define function name write_accounts_to_file that accepts the vecor of accounts and writes to the accounts.txt file.
 * - Define function get_account() that creates an Account object, gets the data for an account from the user and stores it in the account object, then returns that object to the return code.
 * - Add a member function named equals to the account structure
 *    - check to see if email addressed are equal
 * - Use this function to check to see if account already exists
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const string accounts_file = "accounts.txt";

struct Account
{
	string first = "";
	string last = "";
	string pw = "";
	string email = "";
	
	bool equals(Account&);
};

bool Account::equals(Account &toCompare)
{
	return email == toCompare.email;
}

void read_accounts_from_file(vector<Account> &accounts)
{
	accounts.empty();
	ifstream input_file(accounts_file);
	if (input_file) 
	{
		Account a;
		while (input_file >> a.first >> a.last >> a.pw >> a.email) 
		{
			accounts.push_back(a);
		}
		input_file.close();
	}
}

void display_accounts(vector<Account> &accounts) 
{
	int col_width = 10;
	cout << left
			<< setw(col_width * 3) << "Name"
			<< setw(col_width * 4) << "Email" << endl;
	for(auto a: accounts)
	{
		cout << setw(col_width * 3) << a.first + ' ' + a.last
			<< setw(col_width * 4) << a.email << endl;
	}
	
	cout << endl;
}

void write_account_to_file(const string first, const string last, const string password, const string email) {
	ofstream output_file(accounts_file, ios::app);
	if (output_file) {
		output_file << first << '\t'
			<< last << '\t'
			<< password << '\t'
			<< email << '\n';
		output_file.close();
	}
}

void write_accounts_to_file(vector<Account> accounts) {
	ofstream output_file(accounts_file);
	if (output_file) {
		for(auto a: accounts)
			{
			output_file << a.first << '\t'
				<< a.last << '\t'
				<< a.pw << '\t'
				<< a.email << '\n';
		}
		output_file.close();
	}
}

Account get_account()
{
	Account a;
	
	cout << "First name: ";
	getline(cin, a.first);
	cout << "Last name: ";
	getline(cin, a.last);
	cout << "Password: ";
	getline(cin, a.pw);
	cout << "Email: ";
	getline(cin, a.email);
	
	return a;
}

int main()
{
    cout << "Create Account List\n\n";
	vector<Account> accounts;
	
	read_accounts_from_file(accounts);
	display_accounts(accounts);
	
	char another = 'y';
	bool isNewAccount = true;
	while (tolower(another) == 'y') {
		Account a = get_account();
		
		for(auto acc: accounts)
		{
			if(a.equals(acc))
			{
				isNewAccount = false;
				break;
			}
		}
		
		if(isNewAccount)
		{
			accounts.push_back(a);

			write_accounts_to_file(accounts);
		
			cout << endl << a.email << " was added for " 
			<< a.first + ' ' + a.last << endl << endl;
		}
		else
		{
			cout << "Account already exists.  Please enter unique email address." << endl << endl;
		}
		
		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
		isNewAccount = true;
	}

	display_accounts(accounts);
}
