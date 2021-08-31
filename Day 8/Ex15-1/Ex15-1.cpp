/*
 * Raymond Rowland
 * 01SEP21
 * Ex 15-1
 * Enhance the Product Viewer
 * - Improve the book and movie classes
 *   - Create new Class called media:Product
 *   - Media contains format member
 *   - Inherit Media by book and Movie
 *   - Modify so the book and movie constructor so they call Media constructor passing format
 * - Add an Album class
 *   - Inherit from Media
 *   - Have member string for artist
 *   - Override the constructor to take artist name and pass correct parameters to Media->Product 
 */
#include <iostream>
#include <string>
#include "Product.h"
#include "Book.h"
#include "Movie.h"
#include "Album.h"

using namespace std;

const Product p1("Stanley 13 Ounce Wood Hammer", 12.99, 62);
const Book p2("The Big Short", 15.95, 34, "Michael Lewis", "Hardcover");
const Movie p3("The Wizard of Oz", 14.99, 50, 1939, "Stream HD");
const Album p4("The Dark Side Of the Moon", 14.99, 100, "Pink Floyd", "CD");

void show_products() {
    cout << "PRODUCTS\n"
         << "1. " << p1.get_description() << endl
         << "2. " << p2.get_description() << endl
         << "3. " << p3.get_description() << endl
         << "4. " << p4.get_description() << endl << endl;
}

void show_product(const Product& p) {
    cout << "PRODUCT DATA\n"
        << "Name:             " << p.get_description() << endl
        << "Price:            " << p.get_price() << endl
        << "Discount percent: " << p.get_discount_percent() << endl
        << "Discount amount:  " << p.get_discount_amount() << endl
        << "Discount price:   " << p.get_discount_price() << "\n\n";
}

int main() {
    cout << "The Product Viewer program\n\n";

    show_products();

    char choice = 'y';
    while (choice == 'y') {
        int number;
        cout << "Enter product number: ";
        cin >> number;
        cout << endl;

        switch (number) {
        case 1:
            show_product(p1);
            break;
        case 2:
            show_product(p2);
            break;
        case 3:
            show_product(p3);
            break;
        case 4:
            show_product(p4);
            break;
        default:
            cout << "Invalid product number.\n\n";
            break;
        }

        cout << "View another product? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    cout << "Bye!\n\n";

    return 0;
}
