/*
 * Raymond Rowland
 * 30AUG21
 * Ex 11-2
 * Modify the word counter program so it uses algorithms with the pairs of values in the map that contains the words and count of each word
 */
#include <iostream>
#include <fstream>
/*
 * Raymond Rowland
 * 30AUG21
 * Ex 11-2
 * Create prototype for a function named display that accepts a pair of string/int values and returns void
 *  - To be use in for_each to display "key=value"
 * Create prototype for a function named over_1 that accepts a pair of string/int values and returns bool
 *  - If count is > 1 return true
 */
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> load_words(string filename);
map<string, int> get_word_count(const vector<string>& words);
void display(pair<string, int> p);
bool over_1(pair<string, int> p);

int main() {
	cout << "The Word Counter program\n\n";

	string filename = "dickens.txt";
	auto words = load_words(filename);

	cout << words.size() << " WORDS: ";
	for (string word : words) {
		cout << word << ' ';
	}
	cout << endl << endl;

	auto word_count = get_word_count(words);

	cout << word_count.size() << " UNIQUE WORDS: ";
	for (auto pair : word_count) {
		cout << pair.first << ' ';
	}
	cout << endl << endl;

	cout << "COUNT PER WORD: ";
	for_each(word_count.begin(), word_count.end(), display);
	
	cout << endl << endl;
	
	cout << count_if(word_count.begin(), word_count.end(), over_1) << " DUPLICATE WORDS" << endl;
}

void display(pair<string, int> p)
{
	cout << p.first << "=" << p.second << " ";
}

bool over_1(pair<string, int> p)
{
	return p.second > 1;
}

vector<string> load_words(string filename) {
	vector<string> words;
	ifstream infile(filename);

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
			words.push_back(new_word);      // add word 
		}
		infile.close();
	}
	return words;
}

map<string, int> get_word_count(const vector<string>& words) {
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
