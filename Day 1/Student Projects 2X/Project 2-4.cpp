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
    double sixtyOuncesPrice = 0;
    double thirtyTwoOuncesPrice = 0;
    double pricePerOunce64 = 0;
    double pricePerOunce32 = 0;
    
    cout << "Price Comparison\n\n";
    
    cout << "Price of 64 Ounces : ";
    cin >> sixtyOuncesPrice;
    cout << "Price of 32 Ounces : ";
    cin >> thirtyTwoOuncesPrice;
    
    pricePerOunce64 = sixtyOuncesPrice / 64;
    pricePerOunce32 = thirtyTwoOuncesPrice / 32;
    
    
    cout << endl << "Price Per Ounce (64 oz): " << RoundToTwoPlaces<double>(pricePerOunce64) << endl; 
    cout << "Price Per Ounce (32 oz): " << RoundToTwoPlaces<double>(pricePerOunce32) << endl;

}
