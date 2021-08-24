/*
 * Raymond Rowland
 * 23AUG21
 * Calculate the Area of a rectangle 
 */
#include <iostream>

using namespace std;

class Rectangle
{
	public:
		double width;
		double height;
		Rectangle(double w, double h)
		{
			width = w;
			height = h;
		}
		
		double CalcArea()
		{
			return width * height;
		}
};

int main()
{
	cout << "Rectangle Calculator\n\n";
	
	double width = 0;
	double height = 0;
	
	cout << "Enter Width and Height : ";
	cin >> width >> height;
	
	if(width > 0 && height > 0)
	{	
		Rectangle r = Rectangle(width, height);
		cout << "Area                   : " << r.CalcArea() << endl << endl;
	}
	
	cout << "Bye!\n";
	return 0;
}
