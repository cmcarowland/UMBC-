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
    cout << "Name: George Rowland" << endl;
    cout << "Address: 123 Somewhere Lane" << endl;
}
