/*
 * Raymond Rowland
 * 26AUG21
 * Create a program that checks whether a number is even or odd.
 */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

bool IsEven(int num)
{
	return num % 2 == 0;
}

int main()
{
	int userInput = 0;
	cout << "Enter an integer: ";
	cin >> userInput;
	
	cout << userInput << (IsEven(userInput) ? " is even." : " is odd.") << endl;
	
}
