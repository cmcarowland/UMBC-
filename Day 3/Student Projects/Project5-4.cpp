/*
 * Raymond Rowland
 * 25AUG21
 * Create a program that reads data from an unformatted, tab-delimited file, performs some
 * calculations on that data, and writes the resulting data to another file that’s formatted and
 * uses spaces to align the columns.
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

void PrintRowHeader(ofstream &oFile)
{
	const int col_width = 10;
	oFile << "CURRENT PRODUCT LIST" << endl;
	oFile << "==================================================" << endl;
	oFile << left << setw(col_width) << "" << right << setw(col_width) << "" << setw(col_width) << "discount" << setw(col_width) << "discount" << setw(col_width) << "your" << endl; 
	oFile << left << setw(col_width) << "code" << right << setw(col_width) << "price" << setw(col_width) << "percent" << setw(col_width) << "amount" << setw(col_width) << "price" << endl; 
	oFile << "==================================================" << endl;
}

void PrintRow(ofstream &oFile, string code, double price, double discount)
{
	const int col_width = 10;
	oFile << left << setw(col_width) << code 
	<< fixed << setprecision(2)
	<< right << setw(col_width) << price
	<< fixed << setprecision(0) 
	<< setw(col_width) << discount * 100
	<< fixed << setprecision(2) 
	<< setw(col_width) << price * discount
	<< setw(col_width) << price - price * discount << endl; 
}

int main()
{
	stringstream ss;
	ifstream iFile("products.txt");
	ofstream oFile("product_list.txt");
	string line = "";
	string code = "";
	double price = 0;
	double discPrice = 0;
	
	if(iFile)
	{
		PrintRowHeader(oFile);
		while(getline(iFile, line))
		{
			ss.str(line);
			ss.clear();
			
			if(ss >> code >> price >> discPrice)
			{
				PrintRow(oFile, code, price, discPrice);
			}
		}
	}
	iFile.close();
	oFile.close();
}
