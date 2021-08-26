/*
 * Raymond Rowland
 * 26AUG21
 * Create a program that uses a function to simulate the roll of a die.
 */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double RollDie()
{
	return (rand() % 6) + 1;
}

int main()
{
	char userChar = ' ';
	int die1 = 0;
	int die2 = 0;
	int total = 0;
	
	srand(time(nullptr));
	cout << "Dice Roller\n\n";
	

	while(true)
	{
		cout << "Roll the dice? (y/n) : ";
		cin >> userChar;
		cin.ignore(1000, '\n');
		
		if(tolower(userChar) != 'y')
		{
			break;
		}
		die1 = RollDie();
		die2 = RollDie();
		total = die1 + die2;
		
		cout << "Die 1: " << die1 << endl;
		cout << "Die 2: " << die2 << endl;
		cout << "Total: " << total << endl;
		
		if(total == 2)
		{
			cout << "Snake eyes!\n\n";
		}
		else if(total == 12)
		{
			cout << "Boxcars!\n\n";
		}
		else
		{
			cout << endl;
		}
 	}	
}
