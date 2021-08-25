/*
 * Raymond Rowland
 * 25AUG21
 * Create a program that reads a list of rules from a file and displays them.
 */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void PrintDataFromFile()
{

	stringstream ss;
	string line = "";

	ifstream iFile("rules.txt");
	if(iFile)
	{
		while(getline(iFile, line))
		{
			ss.str(line);
			ss.clear();
			if(ss.good())
			{
				cout << ss.str() << endl;
			}
		}
	}

	iFile.close();
}

int main()
{
	PrintDataFromFile();
}
