/*
 * Raymond Rowland
 * 25AUG21
 * Create a program that displays a table of monthly payments on a loan at varying interest rates and number of years.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cmath>

using namespace std;

const double interest_rates[] = {3, 3.5, 4.0, 4.5, 5, 5.5};
const int years[] = {15, 20, 25, 30};

void ClearInputStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void PrintHeaderRow()
{
	cout << setw(8) << left << "Year" 
	<< fixed << setprecision(1)
	<< right << setw(8) << interest_rates[0] << "%"
	<< right << setw(8) << interest_rates[1] << "%"
	<< right << setw(8) << interest_rates[2] << "%"
	<< right << setw(8) << interest_rates[3] << "%"
	<< right << setw(8) << interest_rates[4] << "%"
	<< right << setw(8) << interest_rates[5] << "%" << endl;
}

double CalculateMonthlyPayment(double loanAmount, double rate, int year)
{
	double monthlyRate = rate / 100 / 12;
	int months = year * 12;
	return loanAmount * monthlyRate / (1 - 1 / pow((1 + monthlyRate), months));
}

void PrintRow(double loanAmount, int year)
{
	cout << setw(9) << left << year 
	<< fixed << setprecision(2)
	<< right << setw(8) << CalculateMonthlyPayment(loanAmount, interest_rates[0], year)
	<< right << setw(9) << CalculateMonthlyPayment(loanAmount, interest_rates[1], year)
	<< right << setw(9) << CalculateMonthlyPayment(loanAmount, interest_rates[2], year)
	<< right << setw(9) << CalculateMonthlyPayment(loanAmount, interest_rates[3], year)
	<< right << setw(9) << CalculateMonthlyPayment(loanAmount, interest_rates[4], year)
	<< right << setw(9) << CalculateMonthlyPayment(loanAmount, interest_rates[5], year) << endl;
}

int main()
{
	double loanAmount = 0;
	
	cout << "Monthly Payment Calculator" << endl << endl;
	cout << "Loan Amount: ";
	
	cin >> loanAmount;
	ClearInputStream();
	
	PrintHeaderRow();
	for(auto y: years)
	{
		PrintRow(loanAmount, y);
	}
}
