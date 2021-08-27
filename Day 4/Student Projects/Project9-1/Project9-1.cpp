/*
 * Raymond Rowland
 * 27AUG21
 * Project 9-1: Game Stats
 * Create a program that allows you to view the statistics for a player of a game.
 * Specifications
 * - The program should use a structure named Player to store the player’s name, wins, losses, and ties.
 * - The program should use a vector of Player objects to store the data for each player.
 * - You can code the vector of players at the beginning of the program using any names and statistics that you want. Make sure to provide stats for at least three players.
 * - The program should begin by displaying an alphabetical list of the names of the players.
 * - The program should allow the user to view the stats for the specified player.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>

#include "console.h"

using namespace std;
using namespace console;

struct Player
{
	string name = "";
	int wins = 0;
	int losses = 0;
	int ties = 0;
	void Print();
};

void Player::Print()
{
	const int col_width = 8;
	cout << setw(col_width) << left << "Wins:" << right << wins << endl
	<< setw(col_width) << left << "Losses:" << right << losses << endl
	<< setw(col_width) << left << "Ties:" << right << ties << endl << endl;
}

int main()
{
	srand(time(nullptr));
	
	vector<Player> players;
	string playerNames[] = {"Mike", "Joel", "Mary" };
	string userInput = "";
	bool isPlayer = false;
	
	for(auto n: playerNames)
	{
		players.push_back(Player{n, rand() % 100, rand() % 100, rand() % 100 });
	}
	
	cout << "Game Stats Program\n\nALL PLAYERS:\n";
	for(auto p: players)
	{
		cout << p.name << endl;
	}
	
	
	do
	{
		isPlayer = false;
		cout << "Enter a player name: ";
		getline(cin, userInput);
		for(auto p: players)
		{
			if(p.name == userInput)
			{
				p.Print();
				isPlayer = true;
				break;
			}
		}
		if(!isPlayer)
		{
			cout << "There is no player named " << userInput << endl << endl;
		}
		
	}while(tolower(get_char("Continue? (y/n): ")) == 'y'); 
	
	cout << "Bye!" << endl;
}
