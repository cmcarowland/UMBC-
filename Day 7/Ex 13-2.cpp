/*
 * Raymond Rowland
 * 31AUG21
 * Ex 13-1
 * Add a custom exception handler to a new version of the word document
 * - Define a structure names FileNotFound
 *   - Members message and filename
 * - Modify the load_words function so the vector is only returned if the file is found.
 * - Add code to load_words thats executed if the file isn't found
 *   - Creates a file not found object, assign the values and throw the object.
 * - Add a try catch statement to the main function so the try clause conatins the statement that calls the load_words function.
 * - Add code to the catch statement that cataches a FileNotFound exception, this code should end by exiting the program.
 * - Add a second catch that catches any other exceptions and rethrow the exception 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct FileNotFound {
	string message;
	string filename;
};

vector<string> load_words(string filename);
map<string, int> get_word_count(const vector<string>& words);

int main() {
	cout << "The Word Counter program\n\n";

	string filename = "";
	cout << "Enter a file name: ";
	cin >> filename;

	vector<string> words;
	try
	{
		words = load_words(filename);
	}
	catch(const FileNotFound& e)
	{
		cout << e.message << endl;
		cout << "You entered: " + e.filename << endl;
		cout << "Exiting program..." << endl;
		return -1;
	}
	catch(const exception& e)
	{
		throw e;
	}

	cout << endl;
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
	for (auto pair : word_count) {
		cout << pair.first << '=' << pair.second << ' ';
	}
	cout << endl << endl;
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
	else
	{
		throw FileNotFound {"File Not Found", filename }; 
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
