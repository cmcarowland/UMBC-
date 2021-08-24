#include <iostream>

using namespace std;

#define LY_TO_AU 63240

template
<typename T> T RoundToTwoPlaces(T inputAmount)
{
    return round(inputAmount * 1000) / 1000;
}

double ConvertToUnits(double lightYears)
{
    return lightYears * LY_TO_AU;
}

int main()
{
    double lightYears = 0;
    double astronomicalUnits = 0;
    
    cout << "Enter the number of light years: ";
    cin >> lightYears;
    
    astronomicalUnits = ConvertToUnits(lightYears);
    
    cout << RoundToTwoPlaces<double>(lightYears) << " light years = " << RoundToTwoPlaces<double>(astronomicalUnits) << " Astronomical Units." << endl;
}
