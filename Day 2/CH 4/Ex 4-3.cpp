/*
 * Raymond Rowland
 * 24AUG21
 * Modify the program so it doesn't use a break or continue statement
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int upper_limit = 10;
    cout << "Guess the number!\n";
    cout << "I'm thinking of a number from 1 to " << upper_limit << "\n\n";

    // get a random number between 1 and the upper limit
    srand(time(nullptr));              // seed the rand() function
    int number = rand() % upper_limit; // number is >= 0 and < upper_limit
    ++number;                          // number is >= 1 and <= upper_limit

    int count = 0;
    int guess = 0;
    
    while(guess != number)
    {
        cout << "Your guess: ";
        cin >> guess;
        ++count;

        if (guess < 1 || guess > upper_limit) 
        {
            cout << "Invalid guess. Try again.\n";
        }
        else if (guess < number) 
        {
            cout << "Too low.\n";
        }
        else if (guess > number) 
        {
            cout << "Too high.\n";
        }
    }

    cout << "You guessed it in " << count << " tries.\n\n";
    cout << "Bye!\n\n";
}
