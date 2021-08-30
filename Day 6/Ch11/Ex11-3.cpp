/*
 * Raymond Rowland
 * 30AUG21
 * Ex 11-3
 * Use a function object and a lambda expression with the Test Scores program
 * - Define structure named MinScore with a member named minimum that stores an integer value
 *   - Structure constructor accepts an int and assigns to the minimum member
 * - Overload the function call operator for the structure so it accepts an int value and returns a bool to indicate if the int is greater than or equal to the minimum
 *   -  Keep minimum value from being modified
 * - Comment out code that displays the number of scores that are equal to 100
 * - Add code that uses count_if with the MinScore structure to get the number of scores 90 or above
 * - Do the same for scores 80 or above
 * - Modify the code so it does not use the structure and uses lambda instead
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

struct MinScore
{
	int minimum = 0;
	
	MinScore(int m)
	{
		minimum = m;
	}
	
	bool operator () (int i) const
	{
		return i >= minimum;
	}
};

int sort_descending(int i, int j) {
	return i > j;
}

void display(int value) {
	cout << value << ' ';
}

int main()
{
    cout << "The Test Scores program\n\n";

    cout << "Enter test scores from 0 to 100.\n"
        << "To end the program, enter -1.\n\n";

    vector<int> scores;
    int score = 0;
    while (score != -1) {
        cout << "Enter score: ";
        cin >> score;

        if (cin.fail()) {
            cin.clear();             // clear error bits
            cin.ignore(1000, '\n');  // discard input up to end of line
            cout << "Invalid number. Try again.\n";
        }
        else if (score > 100) {
            cout << "Score must be from 0 to 100. Try again.\n";
        }
        else if (score < -1) {
            cout << "Score can't be a negative number. Try again.\n";
        }
        else if (score > -1) {     // valid score – add to vector
            scores.push_back(score);
        }
    }

    if (scores.empty()) {                 // vector is empty
        cout << "\nNo scores entered\n.";
    }
    else {                                 // vector contains scores
		// sort scores in descending order
		sort(scores.begin(), scores.end(), sort_descending);

		// display sorted scores
		cout << endl;
		for_each(scores.begin(), scores.end(), display);
		cout << endl;

		// display minimum and maximum scores
		auto max_iter = max_element(scores.begin(), scores.end());
		cout << "Highest score: " << *max_iter << endl;
		auto min_iter = min_element(scores.begin(), scores.end());
		cout << "Lowest score: " << *min_iter << endl;

		// display number of scores equal to 100
		//int count_100 = count(scores.begin(), scores.end(), 100);
		//cout << "This student has " << count_100 << " perfect score(s)!" << endl;
		//cout << "Scores 90 or above: " << count_if(scores.begin(), scores.end(), MinScore(90)) << endl;
		//cout << "Scores 80 or above: " << count_if(scores.begin(), scores.end(), MinScore(80)) << endl;

		cout << "Scores 90 or above: " << count_if(scores.begin(), scores.end(), [&](int i) { return i >= 90; }) << endl;
		cout << "Scores 80 or above: " << count_if(scores.begin(), scores.end(), [&](int i) { return i >= 80; }) << endl;

        // calculate total of all scores
        int total = accumulate(scores.begin(), scores.end(), 0);

        // get the count and calculate the average
        auto score_count = scores.size();
        double average = static_cast<double>(total) / score_count;
        average = round(average * 10) / 10;

        // display the score count, total, and average
        cout << '\n'  // blank line
            << "Score count:   " << score_count << endl
            << "Score total:   " << total << endl
            << "Average score: " << average << endl << endl;
    }
}
