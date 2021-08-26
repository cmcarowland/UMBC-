/*
 * Raymond Rowland
 * 25AUG21
 * Create a program that reads an HTML file and converts it to plain text.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cmath>

using namespace std;

void ClearInputStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string CleanLine(string line)
{
	char openGator = '<';
	char closedGator = '>';
	int o = 0;
	int c = line.find(closedGator) + 1;
	int index = line.find("<li>");
	bool isListItem = index != -1;
	
	if(c != -1)
	{
		o = line.find(openGator, c);
	}
	
	return isListItem ? "* " + line.substr(c, o - c) : line.substr(c, o - c );
}

int main()
{
	ifstream iFile("groceries.html");
	string line = "";
	
	cout << "HTML Converter" << endl << endl;
	if(iFile)
	{
		while(getline(iFile, line, '\r'))
		{
			cout << CleanLine(line) << endl;
		}
	}
	
	iFile.close();
}
