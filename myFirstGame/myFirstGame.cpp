// myFirstGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	system("cls");

	char fName[20];

	cout << "What is your name?\n";

	cin >> fName;

	bool starting = false;

	while (starting == false)
	{
		int guessF = 0;
		bool secondGuess = false;
		char diff = 'z';
		char resetDiff = 'q';
		int numCups = 0;
		const char *numCupsText = "";
		char menu = 'a';
		bool menuChoose = false;
		bool won = false;
		bool lost = false;

		srand(time(NULL));

		cout << "Hello, " << fName << "!\n";

		cout << "What difficulty do you want to play on?\n";

		cout << "[e]asy, [m]edium, [h]ard\n";


		while (resetDiff != diff)
		{
			cin >> diff;

			switch (diff)
			{
			case 'e':
				cout << "You have chosen Easy\n";
				resetDiff = 'e';
				numCups = 3;
				numCupsText = "(1,2,3)";
				break;
			case 'm':
				cout << "You have chosen Medium\n";
				resetDiff = 'm';
				numCups = 4;
				numCupsText = "(1,2,3,4)";
				break;
			case 'h':
				cout << "You Have chosen Hard\n";
				resetDiff = 'h';
				numCups = 5;
				numCupsText = "(1,2,3,4,5)";
				break;
			default:
				cout << "Please choose a real difficulty\n";
				resetDiff = 'q';
				diff = 'z';
			}
		}

		cout << "Guess which cup has the little ball. " << numCupsText << "\n";

		int awnserF = rand() % numCups + 1;

		while (won == false)
		{
			cin >> guessF;

			if (guessF > numCups)
			{
				cout << "Sorry that is not within the range...\n";
			}
			else if (guessF <= 0)
			{
				cout << "Sorry that is not within the range...\n";
			}
			else if (guessF != awnserF)
			{
				cout << "Sorry, " << guessF << " is the wrong cup.\n";

				lost = true;
				won = true;
			}
			else
			{
				cout << "Yay, " << guessF << " is the correct cup, " << fName << "...\n";

				won = true;
				lost = false;
			}
		}

		if (won == true && lost == false)
		{
			cout << "You won!!!\n";
		}
		else if (lost == true && won == true)
		{
			cout << "Sorry, " << fName << ", you lost...\n";
		}
		else
		{
			cout << "How did you get to this output???\nYou didn't win nor lost...\nSkiping ahead...\n";
		}

		cout << "New Game? (y/n)\n";
		
		while (menuChoose == false)
		{
			cin >> menu;

			if (menu == 'y' || menu == 'Y')
			{
				system("cls");

				starting = false;

				menuChoose = true;
			}
			else if (menu == 'n' || menu == 'N')
			{
				cout << "OK, bye...\n";

				starting = true;

				menuChoose = true;
			}
			else
			{
				cout << "Please Choose another awnser\n";

				menuChoose = false;
			}
		}
	}
}