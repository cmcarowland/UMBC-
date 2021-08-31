/*
 * Raymond Rowland
 * 31AUG21
 * Ex 14-1
 * Enhance the Dice roller program
 * - Add a member function to die class called get_image
 *   - Takes Int as Parameter and returns the string of the die face
 * - Modify the code so it uses the output from get_image to show the dice
 * - In the Die class add a member set_value(int) 1-6
 * - In Main modify code that displays 6 dice images so it uses a loop to create a die object for each valid number and display its image
 * 
 * - Improve the Dice Class
 *   - Add a function called get_total that gets the total value of all die objects
 *   - add code that displays the total each time.
 */
 
#include <iostream>
#include "Die.h"
#include "Dice.h"

using namespace std;

int main() {
    cout << "The Dice Roller program\n\n";
	Die die;
	
	for(int i = 1; i <= 6; i++)
	{
		cout << die.get_image(i);
	}

    cout << endl;

     // get number of dice from user
    int count;
    cout << "Enter the number of dice to roll: ";
    cin >> count;

    // create Dice object and add Die objects to it
    Dice dice;
    for (int i = 0; i < count; ++i) {
        Die die;
        dice.add_die(die);
    }

    char choice = 'y';
    while (choice == 'y') {
        // roll the dice
        dice.roll_all();
        cout << "YOUR ROLL:\n";
        for (Die die : dice.get_dice()) {
            cout << die.get_image(die.get_value());
        }
        cout << endl << "Total Roll: " << dice.get_total() << endl << endl;

        cout << "Roll again? (y/n): ";
        cin >> choice;
    }
    cout << "Bye!\n\n";
}
