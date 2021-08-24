#include <iostream>
#include <cmath>

using namespace std;

template
<typename T> T RoundToTwoPlaces(T inputAmount)
{
    return round(inputAmount * 100) / 100;
}

int main()
{
    int milesToTravel = 0;
    int milesPerHour = 0;
    int hours = 0;
    int minutes = 0;

    
    cout << "Travel Time Calculator\n\n";
    
    cout << "Enter Miles to Travel : ";
    cin >> milesToTravel;
    cout << "Enter Miles Per Hour : ";
    cin >> milesPerHour;

    hours = milesToTravel / milesPerHour;
    minutes = milesToTravel % milesPerHour;
    
    cout << endl << "Estimated travel time\n";
    cout << "Hours  : " << hours << endl; 
    cout << "Minutes: " << minutes << endl;

}
