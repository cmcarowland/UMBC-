/*
 * Raymond Rowland
 * 30AUG21
 * Ex 11-1
 * Modify the test scores program so it uses algorythms presented in ch 11.
 * - Modify the program so it sorts the scores in descending order
 * - Add code to display the scores that utilizes the for_each algorythm with a function call
 * - Add code that gets and displays the highest and lowest scores
 * - Add code that gets the number of scores that are equal to 100 then display that number
 * - Modify the code that gets the total of the scores so ti uses the accumulate algorythm instead of range based loop
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

void PrintScore(int score)
{
	cout << score << " ";
}

bool SortDescending(int a, int b)
{
	return a > b;
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
        // calculate total of all scores
        int total = accumulate(scores.begin(), scores.end(), 0);
        
		cout << endl;
		sort(scores.begin(), scores.end(), SortDescending);
		for_each(scores.begin(), scores.end(), PrintScore);
		cout << endl;
		
		cout << endl << "Highest Grade: " << *max_element(scores.begin(), scores.end()) << endl;
		cout << "Lowest Grade: " << *min_element(scores.begin(), scores.end()) << endl;
        
        cout << "This Student Has " << count(scores.begin(), scores.end(), 100) << " Perfect Score(s)!" << endl;
        
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
