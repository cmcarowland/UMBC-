/*
 * Raymond Rowland
 * 31AUG21
 * Ex 12-2
 * Modifty the word jumble program so it uses C strings and an array of C strings instead of a string object
 * - Define two constants that can be used as the size declarators for a two-dimensional array.
 *   - Assigne these values so they can accomidate the values in the vector words
 * - Replace words vector with a two-dimensional array of C strings
 * - Modify the code that gets a random word from the array so the word is stored in a C string.
 * - Modify the code that jumbles the word so the jumbled word is stored in a C string.
 * - Modify the coed that getsd the user guesses so the suess is stored in a C string and the strcmp function is used to compare the guess to the other strings.
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int word_length = 3;
const int max_word_len = 9;

int main() {
    cout << "Let's Play Word Jumble!\n"
        << "\n"
        << "Enter 'hint' for a hint.\n"
        << "Enter 'exit' to exit.\n\n";

    // define a vector of possible words
    char words[word_length][max_word_len] { "guitar" , "violin", "tapestry"};

    // get random word from vector
    srand(time(nullptr));
    int index = rand() % word_length;

    int selectedWordLength = strlen(words[index]);
    char word[selectedWordLength];
    strncpy(word, words[index], selectedWordLength);

    // jumble the word
    char jumbled_word[selectedWordLength] = { "\0" };
    strncpy(jumbled_word, word, selectedWordLength);
    
    for (int index1 = 0; index1 < selectedWordLength; ++index1) {
        int index2 = rand() % selectedWordLength;
        char temp = jumbled_word[index1];
        jumbled_word[index1] = jumbled_word[index2];
        jumbled_word[index2] = temp;
    }
    
    // display the jumbled word in upper case
    cout << "The jumble is...";
    for (char c : jumbled_word) {
        cout << (char)toupper(c);
    }
    cout << "\n\n";

    // loop until the user guesses the jumble or enters 'exit'
    int hint_count = 1;
    char guess[max_word_len] = {"\0"};
    while (strncmp(guess, "exit", 4) != 0) {
        cout << "Your guess: ";
        cin >> guess;
        cin.ignore(1000, '\n');

        if (strncmp(guess, word, selectedWordLength) == 0) {
            cout << "Congratulations! You guessed it.\n\n";
            break;
        }
        else if (strncmp(guess, "hint", 4) == 0) {
            cout << "Hint: ";
            for (int i = 0; i < word_length; ++i) {
                if (i < hint_count) {
                    cout << static_cast<char>(toupper(word[i])) << ' ';
                }
                else {
                    cout << '_' << ' ';
                }
            }
            cout << "\n\n";
            ++hint_count;
        }
        else if (strncmp(guess, "exit", 4) == 0) {
            cout << "Bye! Let's play again soon.\n\n";
        }
        else {
            cout << "Nope. Try again!\n\n";
        }
    }
}
