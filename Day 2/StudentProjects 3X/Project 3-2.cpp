/*
 * Raymond Rowland
 * 24AUG21
 * Create a program that calculates the total cost of an order including shipping.
 */
#include <iostream>
#include <cmath>

using namespace std;

double GetShippingCost(double costOfItems)
{
    if(costOfItems <= 29.99)
    {
        return 5.95;
    }
    else if(costOfItems <= 49.99)
    {
        return 7.95;
    }
    else if(costOfItems <= 74.99)
    {
        return 9.95;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cout << "===============================================================" << endl;
    cout << "Shipping Calculator\n";
    cout << "===============================================================" << endl;
    
    double costOfItems = 0;
    double shippingCost = 0;
    
    cout << "Cost Of Items Ordered: ";
    cin >> costOfItems;
    
    if(costOfItems < 0)
    {
        cout << "You must enter a positive number." << endl;
    }
    else
    {
        shippingCost = GetShippingCost(costOfItems);
        cout << "Shipping Cost: " << shippingCost << endl;
        cout << "Total Cost: " << costOfItems + shippingCost << endl;
    }
}
