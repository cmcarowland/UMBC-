/*
 * Raymond Rowland
 * 27AUG21
 * NCWDG Graded Assessment 1
 */
#include <iostream>
#include <sstream>

using namespace std;

string GetPlural(int bottles)
{
	return bottles > 1 ? " bottles" : " bottle";
}

void PrintErrorMessage()
{
	cout << "Invalid Arguments!\nPlease Try ./bottles [Number Of Bottles (1-100). Default to 99 without argument.]\nSee man page for more details." << endl;
}

void SingSong(int &bottles)
{
	while(bottles > 0)
	{
		cout << bottles << (GetPlural(bottles) + " of beer on the wall!") << endl;
		cout << bottles << GetPlural(bottles) + " of beer!" << endl;
		cout << "Take one down" << endl;
		cout << "And pass it around" << endl;
		bottles --;
		
		if(bottles > 0)
		{
			cout << bottles << (GetPlural(bottles) + " of beer on the wall!") << endl << endl;
		}
		else
		{
			cout << "No more bottles of beer on the wall!" << endl << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	//Initialize bottles to 99. The default value
	int bottles = 99;
	
	//IF the user overfilled my command line tell them how to use the program
	if(argc > 2)
	{
		PrintErrorMessage();
		return -1;
	}
	else if(argc == 2)//The user specified a argument
	{
		//Use Stringstream to parse out the number
		stringstream ss(argv[1]);
		ss.clear();
		ss >> bottles;
		if(ss.fail())
		{
			cout << "Please enter a valid integer" << endl << endl;
			PrintErrorMessage();
			return -2;
		}
		else if(bottles < 1 || bottles > 100)
		{
			PrintErrorMessage();
			return -3;
		}
	}
	
	SingSong(bottles);
}
