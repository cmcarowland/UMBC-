#include <iostream>
#include <cmath>
using namespace std;

template
<typename T> T RoundToTwoPlaces(T inputAmount)
{
    return round(inputAmount * 1000) / 1000;
}

double ConvertFahrenheit(double celsius)
{
    return 1.8 * celsius + 32.0;
}

int main()
{
    double celsius = 0;
    double fahrenheit = 0;
    
    cout << "Enter Temp in C: ";
    cin >> celsius;
    
    fahrenheit = ConvertFahrenheit(celsius);
    
    cout << celsius << " degrees Celsius is " << RoundToTwoPlaces<double>(fahrenheit) << " degrees Fahrenheit" << endl;
}
