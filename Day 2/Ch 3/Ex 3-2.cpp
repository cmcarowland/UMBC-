/*
 * Raymond Rowland
 * 24AUG21
 * Validate user input is greater than 0 to calculate the area of a rectangle
 * Changed nested if's to single statement and changed error message
 */
#include <iostream>

using namespace std;

int main()
{
	// print name of program
	cout << "Rectangle Calculator" << endl << endl;

	// get height and width from user
	double height;
	double width;
	cout << "Enter height and width: ";
	cin >> height >> width;
    
    //if(height > 0)
        //if(width > 0)
        //{
            //// calculate area
            //double area = height * width;

            //// write output to console
            //cout << "Area:                   " << area << endl << endl
                 //<< "Bye!" << endl << endl;
        //}
        //else
            //cout << endl << "Width must be above 0\n\n";
    //else
        //cout << endl << "Height must be above 0\n\n";
        
        if(height > 0 && width > 0)
        {
            // calculate area
            double area = height * width;

            // write output to console
            cout << "Area:                   " << area << endl << endl
                 << "Bye!" << endl << endl;
        }
        else
            cout << endl << "Height and Width must be above 0\n\n";

    return 0;
}

