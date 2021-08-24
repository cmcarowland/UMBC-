#include <iostream>
#include <cmath>

using namespace std;

const double FURLONGS_TO_YARDS = 220.0;

template
<typename T> T RoundToTwoPlaces(T inputAmount)
{
    return round(inputAmount * 100) / 100;
}

int main()
{
    double furlongs = 0;
    double yards = 0;
    
    cout << "Enter Distance In Furlongs: ";
    cin >> furlongs;
    
    yards = furlongs * FURLONGS_TO_YARDS;
    
    
    cout << "Yards: " << yards << endl;
}
