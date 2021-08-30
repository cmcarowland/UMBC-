/*
 * Raymond Rowland
 * 30AUG21
 * Modify word counter program so it stores all the words in the text file in a multiset and all the unique words in a set.
 * - Modify display_and_load_words to use multiset
 * - Modify Main to display the count of words in the multiset 
 * - Add function get_unique_words that accepts a multiset and returns a set
 * - Modify main to user get_unique_words function
 * - Modify the main function to display the count of unique words and unique words
 * - Modify the main function to display all the unique words and the count that appears in the document.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

multiset<string> display_and_load_words(string filename);
map<string, int> get_word_count(const vector<string>& words);

set<string> get_unique_words(multiset<string> &words)
{
	set<string> s;
	for(auto w: words)
		s.insert(w);
	
	return s;
}

int main() {
    cout << "The Word Counter program\n\n";

    string filename = "dickens.txt";
    auto words = display_and_load_words(filename);

    cout << "WORD COUNT: " << words.size();
    cout << endl << endl;

	auto unique = get_unique_words(words);

    cout << unique.size() << " UNIQUE WORDS: ";
    for (auto pair : unique) {
        cout << pair << ' ';
    }
    cout << endl << endl;

    cout << "COUNT PER WORD: ";
    for (auto pair : unique)
    {
        cout << pair << '=' << count(words.begin(), words.end(), pair) << ' ';
    }
    cout << endl << endl;
}

multiset<string> display_and_load_words(string filename) {
    multiset<string> words;
    ifstream infile(filename);
	cout << "FILE TEXT: ";
	
    if (infile) {
        string word;
        while (infile >> word) {

            string new_word = "";
            for (char c : word) {
                if (c == '.' || c == ',') {
                    continue;               // remove punctuation
                }
                else if (isupper(c)) {
                    new_word += tolower(c); // convert to lowercase
                }
                else {
                    new_word += c;
                }
            }
			cout << new_word << ' ';
            words.insert(new_word);      // add word 
        }
        infile.close();
    }
    cout << endl << endl;
    return words;
}

map<string, int> get_word_count(const multiset<string>& words) {
    map<string, int> word_count{};

    for (string word : words) {
        auto search = word_count.find(word);
        if (search == word_count.end()) {
            word_count[word] = 1;   // not found - add word with count of 1
        }
        else {
            word_count[word] += 1;  // found - increment count for word
        }
    }
    return word_count;
}
