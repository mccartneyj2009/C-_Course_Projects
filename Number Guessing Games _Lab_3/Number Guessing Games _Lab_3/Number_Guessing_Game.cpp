#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	bool pa;
	do
	{
		unsigned seed = time(0);
		cout << "\nLets play a game...\n\n";
		cout << "Choose a number between 1-10\n\n";
		srand(seed);
		int myRandom = (rand() % 10 + 1);
		int myGuess;
		int numGuess = 1;
		cin >> myGuess;

		//User guess loop
		for (myGuess; myGuess != myRandom;)
		{
			cout << "Wrong! Try Again.\n\n";
			cin >> myGuess;
			numGuess = numGuess + 1;
		}
		//Users Guess is correct
		if (myGuess == myRandom)
		{
			cout << "\nCorrect!\n\n";
			cout << "You guessed the number in " << numGuess << " attempts.\n\n";
			bool validSelection = false;
			do
			{
				cout << "Would you like to play again? (Y/N)\n\n";
				char playAgain;
				cin >> playAgain;
				switch (playAgain)
				{
				case 'Y':
				case'y':
					pa = true;
					validSelection = true;
					break;
				case 'N':
				case 'n':
					pa = false;
					validSelection = true;
					break;
				default:
					cout << "Invalid Selection.\n\n";
				}
			} while (validSelection != true);
		}
	} while (pa != false);
	system("pause");
	return 0;
}