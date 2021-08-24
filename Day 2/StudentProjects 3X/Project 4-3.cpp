/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that calculates the amount of time and fuel for a 1980 Cessna 172N to fly a specified distance.
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

#define COL_WIDTH 20
#define FLIGHT_SPEED 120
#define GAL_PER_HOUR 8.4

using namespace std;

double RoundToTwoPlaces(double val)
{
    return round(val * 100) / 100;
}

double RoundToOnePlaces(double val)
{
    return round(val * 10) / 10;
}

void ClearInputStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool ShouldRunAgain()
{
    char response = 'y';
    
    cout << "Continue? (y/n): ";
    cin.get(response);
    ClearInputStream();
    
    if(tolower(response) == 'y')
    {
        cout << endl;
        return true;
    }
        
    return false;
}

string FlightTimeString(double hours)
{
    string flightTime = "";
    
    int hourFloor = floor(hours);
    int minutes = (hours - hourFloor) * 60;
    
    flightTime += to_string(hourFloor);
    flightTime += " hour(s) and ";
    flightTime += to_string(minutes);
    flightTime += " minute(s)";
    
    return flightTime;
}

double FlightTime(double distance)
{
    return distance / FLIGHT_SPEED;
}

double GalRequired(double distance)
{
    double fuelRequired = (FlightTime(distance) + 0.5) * GAL_PER_HOUR;
    return fuelRequired;
}

void PrintAircraft(double distance)
{    
    cout << setw(COL_WIDTH) << "Flight time: " << FlightTimeString(FlightTime(distance)) << endl;
    cout << setw(COL_WIDTH) << "Required fuel: " << RoundToOnePlaces(GalRequired(distance)) << " gallons" << endl << endl;
}

int main()
{
    double distance = 0;
    
    cout << "Aircraft Fuel Calculator\n\n";
    
    do
    {
        distance = 0;
    
        cout << "Distance in nautical miles: ";
        cin >> distance;
        ClearInputStream();

        
        PrintAircraft(distance);
    }while(ShouldRunAgain());
    
    cout << endl << "Bye!\n";
}
