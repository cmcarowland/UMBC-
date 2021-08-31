/*
 * Raymond Rowland
 * 30AUG21
 * Ex 12-1
 * Modify the product sales program that uses an array to store sales data.
 * - Define a constant to be used as a size declarator for an array that can store up to 12 elements
 * - Replace the vector names sales with an array and initialize the elements of the array with the default value for a double type
 * - Define a variable named sales_count that can be used to count the number of sales entries snf initialize this variable to 0
 * - Modify while loop so it will not accept more entries than the array can store
 * - Modify the code that is executed for valid sales entries so the sales amount is stored in the next element in the array and the sales_count variable is increased by one
 * - Modify the code that checks if sales were entered so it works for the modified code
 * - Modify the code that calculates the average sales and displays the number of sales entries so it uses the sales_count variable
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int sales_array_size = 12;

int main()
{
	cout << "The Product Sales program\n\n";

	cout << "Enter product sales from 0 to 10,000.\n"
		<< "To end the program, enter -1.\n\n";

	double sales[sales_array_size] = {0};
	int sales_count = 0;
	
	double sale = 0.0;
	while (sale != -1 || sales_count == sales_array_size) {
		cout << "Enter sales amount: ";
		cin >> sale;

		if (cin.fail()) {
			cin.clear();             // clear error bits
			cin.ignore(1000, '\n');  // discard input up to end of line
			cout << "Invalid number. Try again.\n";
		}
		else if (sale > 10000) {
			cout << "Score must be from 0 to 10,000. Try again.\n";
		}
		else if (sale < -1) {
			cout << "Score can't be a negative number. Try again.\n";
		}
		else if (sale > -1) {        // valid sale amount – add to vector
			sales[sales_count++] = sale;
		}
	}

	if (sales_count == 0) {             // vector is empty
		cout << "\nNo sales entered.\n\n";
	}
	else {                           // vector contains sales
									 // calculate total of all sales
		double total = 0.0;
		for (double sale : sales) {
			total += sale;
		}

		// get the count and calculate the average
		double average = static_cast<double>(total) / sales_count;
		average = round(average * 100) / 100;

		// display the sales count, total, and average
		cout << '\n'
			<< "Sales count:   " << sales_count << endl
			<< "Sales total:   " << total << endl
			<< "Average sales: " << average << endl << endl;
	}
}

