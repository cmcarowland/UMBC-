#include <iostream>
#include <cmath>

using namespace std;

template
<typename T> T RoundToThreePlaces(T inputAmount)
{
    return round(inputAmount * 1000) / 1000;
}

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    
    cout << "Hypotenuse Calculator\n\n";
    
    cout << "Enter Side A : ";
    cin >> a;
    cout << "Enter Side B : ";
    cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));
    
    cout << "Side C: " << RoundToThreePlaces<double>(c) << endl;

}
