#include<iostream> 
#include<string>
#include<vector>
using namespace std;

//void gameBoard(string player1, string player2);

int gameBoard()
{
	string play_1, play_2;
	cout << "Tic-Tac-Toe Time!\n\n";
	cout << "Enter player 1 name: \n";
	getline(cin, play_1);
	cout << "Enter player 2 name: \n";
	getline(cin, play_2);

	{
		string squares[3][3];
		//int num = 0;
		//int player = 0;
		system("cls");
		cout << "\n\n\tTic Tac Toe\n\n";

		cout << play_1 << " (X)  - " << play_2 << " (O)\n\n\n";
		for (int i = 0; i < 6; i++)
		{
			system("cls");
			cout << "\n\n\tTic Tac Toe\n\n";

			cout << "     |     |     " << endl;
			cout << "  " << squares[0][0] << "  |" << "  " << squares[0][1] << "  |" << "  " << squares[0][2] << endl;
			cout << "_____|_____|_____" << endl;
			cout << "     |     |     " << endl;
			cout << "  " << squares[1][0] << "  |" << "  " << squares[1][1] << "  |" << "  " << squares[1][2] << endl;
			cout << "_____|_____|_____" << endl;
			cout << "     |     |     " << endl;
			cout << "  " << squares[2][0] << "  |" << "  " << squares[2][1] << "  |" << "  " << squares[2][2] << endl;
			cout << "     |     |     " << endl << endl;
		}

	}
	return 0;
}