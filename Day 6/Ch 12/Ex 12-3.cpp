/*
 * Raymond Rowland
 * 31AUG21
 * Ex 12-3
 * Modify the test scores program so it uses a two dimensional array to score a fixed number of scores for multiple students
 * - Modify the code in main so it defines a two-dimensional array that can store up to 10 students with 3 score per student
 * - Modify the instrustions of the program so the indicate max students
 * - Modify the loop so when the user enters -1 or until the user enters the max number of students
 *   - Within this loop add a nested loop that contains code that gets the scores for each student
 * - Add any additional code for the shile loop to work correctly
 * - Modify the code that checks if any scores have been entered so it checks the counter variable for the number of students
 * - Modify the code thats executed if scores have been entered so it loops through the array for each student that has scores and displays those scores and the average score on the console
 */
#include <iostream>
#include <cmath>

using namespace std;

int calculate_total(int scores[], int count);
const int max_student_number = 10;
const int max_grade_per_student = 3;

int main() 
{
    int scores[max_student_number][max_grade_per_student] { 0 };  // set each element in array to 0
	int scores_count[max_student_number] { 0 };

    cout << "The Test Scores program\n\n";

    cout << "Enter test scores (" << max_grade_per_student << " max).\n"
         << "Make sure each score is between 0 and 100.\n"
         << "To end the program, enter -1.\n\n";

    // initialize counter and score variables
    int score_count = 0, score = 0, student_count = 0;

    // prevent out of bounds access by making sure
    // score count is less than capacity
    while (student_count < max_student_number && score != -1) {
		cout << "Enter Scores for Student " << student_count + 1 << endl;
		while (score_count < max_grade_per_student && score != -1) 
		{
			cout << "Enter score: ";
			cin >> score;

			if (cin.fail()) {
				cin.clear();             // clear bad input flag
				cin.ignore(1000, '\n');  // discard input up to end of line
				cout << "Invalid number. Try again.\n";
			}
			else if (score > 100) {
				cout << "Score must be from 0 to 100. Try again.\n";
			}
			else if (score < -1) {
				cout << "Score can't be a negative number. Try again.\n";
			}
			else if (score > -1) {
				scores[student_count][score_count] = score;   // store score in array
				++score_count;                 // increment score count
				scores_count[student_count] = score_count;
			}
		}
		student_count++;
		score_count = 0;
		cout << endl;
    }
    cout << endl;

    if (student_count == 0) {
        cout << "No scores entered.\n\n";
    }
    else {
        // calculate total and average scores
        for(int i = 0; i < max_student_number; i++)
        {
			double total = calculate_total(scores[i], scores_count[i]);
			
			if(total == 0)
				break;
				
			double average = total / scores_count[i];
			average = round(average * 10) / 10;
			cout << "Student " << i +1 << ": "; 
			for(auto x: scores[i])
			{
				if(x > 0)
					cout << x << " ";
			}
			cout << "\tAverage score: " << average << endl;
		}
    }

    return 0;
}

int calculate_total(int scores[], int count) 
{
    int total = 0.0;
    for (int i = 0; i < count; ++i) {
        total += scores[i];
    }
    return total;
}
