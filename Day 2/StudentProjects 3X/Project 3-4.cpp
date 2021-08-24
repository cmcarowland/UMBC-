/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that allows you to perform simple calculations.
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

#define COL_WIDTH 10

using namespace std;

void ClearInputStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double CircleArea(double radius)
{
    return M_PI * pow(radius, 2);
}

double SquareArea(double height)
{
    return height * height;
}

double RectangleArea(double height, double width)
{
    return height * width;
}

void Circle()
{
    double radius = 0;
    
    cout << endl << "CIRCLE" << endl;
    cout << setw(COL_WIDTH) << "Radius:";
    cin >> radius;
    ClearInputStream();
    
    cout << setw(COL_WIDTH) << "Area:" << CircleArea(radius);
}

void Square()
{
    double height = 0;
    cout << endl << "SQUARE" << endl;
    cout << setw(COL_WIDTH) << "Height:";
    cin >> height;
    ClearInputStream();
    cout << setw(COL_WIDTH) << "Area:" << SquareArea(height);
}

void Rect()
{
    double height = 0;
    double width = 0;
    cout << endl << "RECTANGLE" << endl;
    cout << setw(COL_WIDTH) << "Height:";
    cin >> height;
    ClearInputStream();
     
    cout << setw(COL_WIDTH) << "Width:";
    cin >> width;
    ClearInputStream();
    
    cout << setw(COL_WIDTH) << "Area:" << RectangleArea(height, width);
}

int main()
{
    cout << "AREA CALCULATOR\n\n";
    cout << "1. Circle\n";
    cout << "2. Square\n";
    cout << "3. Rectangle\n\n";
    
    int menuSelection = 0;
    cin >> menuSelection;
    
    cout << left;
    switch(menuSelection)
    {
        case 1:
            Circle();
            break;
        case 2:
            Square();
            break;
        case 3:
            Rect();
            break;
        default:
            cout << "Invalid Menu Item!" << endl;
            break;
    }
    
}
