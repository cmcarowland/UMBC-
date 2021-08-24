/*
* Author:  Anne Boehm
* Date:    March 27, 2018
* Purpose: This program uses the console to get the
*          height and width of a rectangle from the
*	       user. Then, it calculates the area of the
*	       rectangle and displays the result.
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

