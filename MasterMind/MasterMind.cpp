/*
 * Raymond Rowland
 * 02SEP21
 * Final Assessment
 * 
 * Completed the man documentation 
 * Added command line agrument autoplay that plays the game itself 
 * Track the time it takes the User/AI to submit a valid guess and display the average at the end 
 * Supports an answer file named .mm to get the answer 
 */
 
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;
void TestUnique();

void GetUniqueNumbers(int (&numbers)[4])
{
	int currentTry = 0;
	bool unique = false;
	
	for(int x = 0; x < 4; x++)
	{
		do
		{
			unique = true;
			currentTry = rand() % 9;
			for(auto i: numbers)
			{
				if(i == currentTry)
				{
					unique = false;
					break;
				}
			}
		}while(!unique);
		
		numbers[x] = currentTry;
	}
}

int ConvertArrayToInt(int (&numbers)[4])
{
	int outValue = 0;
	int place = 1000;
	
	for(int i = 0; i < 4; place /= 10, i++)
	{
		outValue += numbers[i] * place;
	}
	
	return outValue;
}

bool ContainsDuplicates(string &guess)
{
	for(auto c: guess)
	{
		if(count(guess.begin(), guess.end(), c) > 1)
		{
			return true;
		}
	}
	
	return false;
}

string GetGuess()
{
	int guessInt = 0;
	stringstream ss;
	string guess = "";
	
	do
	{
		cout << "Enter Guess: ";
		cin >> guess;
		cin.ignore(1000, '\n');
		
		ss.clear();
		ss.str(guess);
		ss >> guessInt;
		if(guess.length() == 4 && !ss.fail())
		{
			if(ContainsDuplicates(guess))
			{
				cout << "Number Must Not Contain Duplicate Digits!!  Try Again." << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "Invalid Input!!  Please enter a four digit number" << endl;
		}
	}while(true);
	
	return guess;
}

bool CorrectAnswer(string correct, string guess)
{
	int red = 0;
    int white = 0;
    
	for(uint i = 0; i < correct.length(); i ++)
	{
		if(correct[i] == guess[i])
		{
			red++;
		}
		else
		{
			white ++;
		}
	}
	
	cout << red << " red, " << white << " white" << endl;
	
	return correct == guess;
}

void AutoPlay(string correctAnswer, int &numberOfGuesses, long long &elapsedTime)
{
	int uniqueGuess[4];
	string guess = "";
	int guessAsInt = 0;
	
	do
	{
		auto start = chrono::steady_clock::now();
		GetUniqueNumbers(uniqueGuess);
		guessAsInt = ConvertArrayToInt(uniqueGuess);
		guess = to_string(guessAsInt);
		cout << guess << endl;
		numberOfGuesses++;
		auto end = chrono::steady_clock::now();
		elapsedTime += chrono::duration_cast<chrono::microseconds>(end - start).count();
	}while(!CorrectAnswer(correctAnswer, guess));
}

int main(int argc, char* argv[]) 
{
    srand(time(nullptr));
    bool autoplayed = false;
    
    int numbers[4] = {0};
    string numberAsString = "";
    int correctAnswer = 0;
    
    int numberOfGuesses = 0;
    string currentGuess = "";
    
    long long elapsedTime = 0;
	
	ifstream iStream(".mm");
	if(iStream)
	{
		stringstream ss;
		string line = "";
		getline(iStream, line);
		ss.clear();
		ss.str(line);
		ss >> correctAnswer;

		if(!ss.fail() && correctAnswer > 1000 && correctAnswer < 9999 && !ContainsDuplicates(line) && line.length() == 4)
		{
			numberAsString = line;
		}
		else
		{
			cout << "Answer file may be corrupted.  Please repair and try again." << endl;
			return -2;
		}
	}
	else
	{
		GetUniqueNumbers(numbers);
		int correctAnswer = ConvertArrayToInt(numbers);
		numberAsString = to_string(correctAnswer);
	}
	
	
	
	//Uncomment to see the answer required to win.
	//cout << numberAsString << endl;
	
    if(argc > 1)
    {
		string arg1(argv[1]);
		if(arg1 == "autoplay" && argc < 3)
		{
			AutoPlay(numberAsString, numberOfGuesses, elapsedTime);
			autoplayed = true;
		}
		else
		{
			cout << "Invalid Argument!\nProper Usage:  ./MasterMind [autoplay]\nSee Man Pages for more information." << endl;
			return -1;
		}
	}
	else
	{
		do
		{
			auto start = chrono::steady_clock::now();
			currentGuess = GetGuess();
			auto end = chrono::steady_clock::now();
			elapsedTime += chrono::duration_cast<chrono::seconds>(end - start).count();
			numberOfGuesses++;
		}while(!CorrectAnswer(numberAsString, currentGuess));
	}
	
	cout << "You Win!  It took you " << numberOfGuesses << " guesses." << endl;
	cout << setprecision(2) << fixed;
	if(autoplayed)
	{
		cout << "Your average time between guesses was " << elapsedTime / static_cast<double>(numberOfGuesses) << " Microseconds" << endl;
	}
	else
	{
		cout << "Your average time between guesses was " << elapsedTime / static_cast<double>(numberOfGuesses) << " Seconds" << endl;
	}
}

void TestUnique()
{
	int numbers[4] {0};
	
    for(int i = 0; i < 1000; i ++)
    {
		GetUniqueNumbers(numbers);
		for(auto i: numbers)
		{
			int c = count(numbers, numbers + 4, i);
			if(c > 1)
			{
				cout << "Test Failed!!!" << endl;
				cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << " " << numbers[3] << endl;
			}
		}
	}
	cout << "Test Passed!!!" << endl;
}
