// myFirstGame.cpp : Defines the entry point for the console application.
// Created by, Nick Mullally a.k.a. Nire Inicana / thakyZ

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	// Clear console.
	system("cls");

	// Variable for the player's name.
	char fName[20];

	cout << "Welcome to guess which cup has the little ball.\n";
	cout << "Copyright (c) 2014 Nick Mullally";

	cout << "Created by, Nick Mullally\n\n";

	cout << "What is your name?\n";

	// Input for the player's name.
	cin >> fName;

	// Check if fName is a valid char.
	if (cin.fail() && (cin.peek() != EOF || cin.peek() != '\n'))
	{
		cin.clear();
		cin.ignore(256,'\n');

		cout << "Please use a valid const char.\n";
	}
	else
	{
		// The bool for the restart of the game.
		bool starting = true;

		// Start of the game.
		while (starting == true)
		{
			int answerCup = 0; // The correct answer for the cup.
			int guessCup = 0; // The Number for the guessed cup.
			char diff = 'z'; // The difficulty selector.
			char resetDiff = 'q'; // The way to restart the difficulty selector.
			int numCups = 0; // The number of cups based off of difficulty.
			const char *numCupsText = ""; // The generated text for how many cups there is.
			char newGame = 'a'; // The selector for restarting the game.
			bool gameCheck = false; // Check to see if the game is over.
			bool lost = false; // Check to see if the player lost the game.

			// Set up the random number generator.
			srand(time(NULL));

			cout << "Hello, " << fName << "!\n";

			cout << "What difficulty do you want to play on, " << fName << "?\n";

			cout << "[e]asy, [m]edium, [h]ard, e[x]treme\n";

			// The difficulty selector.
			while (resetDiff != diff)
			{
				// The input for which difficulty to play on.
				cin >> diff;

				// Check to see if diff is a vail char.
				if (cin.fail() && (cin.peek() != EOF || cin.peek() != '\n'))
				{
					cin.clear();
					cin.ignore(256,'\n');

					cout << "Error: Please use a valid char.\n";
				}
				else
				{
					switch (diff)
					{
						case 'e':
							cout << "You have chosen Easy.\n";
							resetDiff = 'e';
							numCups = 3;
							numCupsText = "(1,2,3)";
							break;
						case 'm':
							cout << "You have chosen Medium.\n";
							resetDiff = 'm';
							numCups = 5;
							numCupsText = "(1,2,3,4,5)";
							break;
						case 'h':
							cout << "You have chosen Hard.\n";
							resetDiff = 'h';
							numCups = 7;
							numCupsText = "(1,2,3,4,5,7)";
							break;
						case 'x':
							cout << "You have chosen Extreme.\n";
							resetDiff = 'x';
							numCups = 11;
							numCupsText = "(1,2,3,4,5,6,7,8,9,10,11)";
							break;
						default:
							// Needed this for the chance the player inputs the wrong letter.
							cout << "Please choose a real difficulty\n";
							resetDiff = 'q';
							diff = 'z';
					}
				}
			}

			cout << "Guess which cup has the little ball in it. " << numCupsText << "\n";

			// Generate the answer to which cup the ball is in.
			answerCup = rand() % numCups + 1;

			// Start the game.
			while (gameCheck == false)
			{
				// Input for the guessed cup.
				cin >> guessCup;

				// Check to see if guessCup is a vaild int.
				if (cin.fail() && (cin.peek() != EOF || cin.peek() != '\n'))
				{
					cin.clear();
					cin.ignore(256,'\n');

					cout << "Error: Please use a valid int.\n";
				}
				else
				{
					if (guessCup > numCups)
					{
						// This is to tell if the guessed cup is in range.
						cout << "Sorry that is not within the range...\n";
					}
					else if (guessCup <= 0)
					{
						// This is to tell if the guessed cup is in range.
						cout << "Sorry that is not within the range...\n";
					}
					else if (guessCup != answerCup)
					{
						// This is to check if the player lost.
						cout << "Sorry, " << guessCup << " is the wrong cup.\n";

						lost = true; // The player has lost.
						gameCheck = true; // The game is over.
					}
					else
					{
						// This is to check if the player has won.
						cout << "Yay, " << guessCup << " is the correct cup, " << fName << "...\n";

						gameCheck = true; // The game is over.
						lost = false; // The player didn't lose.
					}
				}
			}

			// The message if the player has won or not.
			if (gameCheck == true && lost == false)
			{
				// This is to display that the player has won.
				cout << "You won!!!\n";
			}
			else if (lost == true && gameCheck == true)
			{
				// This is to display that the player has lost.
				cout << "Sorry, " << fName << ", you lost... You guessed, Cup #" << guessCup << ", The correct cup was, Cup #" << answerCup << ".\n";
			}
			else
			{
				// * - Easter Egg - * Just incase the player has gotten to this part and didn't end the game and didn't win or did win.
				cout << "How did you get to this output, " << fName << "???\nYou didn't win nor lost...\nSkiping ahead...\n";
			}

			cout << "New Game? (y/n)\n";

			// This is to select a new game.
			while (newGame == 'a')
			{
				// This is the input for the new game.
				cin >> newGame;

				// Check to see if newGame is a valid char.
				if (cin.fail() && (cin.peek() != EOF || cin.peek() != '\n'))
				{
					cin.clear();
					cin.ignore(256,'\n');

					cout << "Error: Please use an valid char.\n";
				}
				else
				{
					if (newGame == 'y' || newGame == 'Y')
					{
						// This is to check if the player said yes.
						// This is the way to clear the state for the new game.
						system("cls");

						// This is to say that the game is restarting
						starting = true;

						// At this part the game is restarting.
					}
					else if (newGame == 'n' || newGame == 'N')
					{
						// This is to check if the player said no.
						cout << "OK, " << fName << ", good bye...\n";

						// This is to say the game isn't restarting
						starting = false;

						// At this point the game ends.
					}
					else
					{
						// This is if you choose an invalid answser.
						cout << "Please Choose another answer.\n";

						// This is to restart to choose again.
						newGame = 'a';
					}
				}
			}
		}
	}

	return 0;
}
