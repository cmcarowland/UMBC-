/*
 * Raymond Rowland
 * 30AUG21
 * - Add code to diaplay_codes function so it displays the codes properly
 * - Add to displat_country so it gets an iterator for the element whose key is equal to the code
 *   - Display approperiate code if not found
 * - Add code to main that calls display codes when the program starts and any time the user chooses to cointinue
 */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

char get_choice() {
	char choice;
	cout << "Continue (y/n)?: ";
	cin >> choice;
	cout << endl;
	return choice;
}

void display_codes(const map<string, string>& countries) {
	cout << "Country codes: ";
	// display codes
	for_each(countries.begin(), countries.end(), [&](pair<string, string> country){cout << country.first << " ";}); 

	cout << endl << endl;
}

void display_country(const map<string, string>& countries) {
	string code;
	cout << "Enter a country code: ";
	cin >> code;
	string upper_code = "";
	for (char c : code) {
		upper_code += toupper(c);
	}

	// get iterator for map element with code
	auto country = countries.find(upper_code);

	// if the code isn't found, display a message
	if(country == countries.end())
	{
		cout << "Country Code Not Found\n\n";
	}
	// if the code is found, display the country name
	else
	{
		cout << "You Selected " << country->second << "!\n\n";
	}
}

int main()
{
	map<string, string> countries{ {"CA", "Canada"}, {"US", "United States"}, {"MX", "Mexico"} };

	cout << "The Country Codes Program\n\n";

	do
	{
		// display the country codes
		display_codes(countries);

		// while the user indicates they want to continue, display a country
		display_country(countries);
		
	}while(get_choice() == 'y');
}

