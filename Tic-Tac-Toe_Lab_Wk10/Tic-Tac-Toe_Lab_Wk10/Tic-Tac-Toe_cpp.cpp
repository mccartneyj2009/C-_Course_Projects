#include<iostream> 
#include<string>
#include<vector>
using namespace std;

void game(string player1, string player2);
int squareTracker(string squares[3][3], int num, int player);
void boardUpdate(string squares[3][3], string player1, string player2);

int main()
{
	bool quit = false;
	string ans;
	string play_1, play_2;
	do
	{
		cout << "Play Tic-Tac-Toe?(Y/N)\n\n";
		cin >> ans;
		if (ans == "Y")
		{
			cout << "Enter player 1 name: \n";
			cin >> play_1;
			cout << "Enter player 2 name: \n";
			cin >> play_2;
			game(play_1, play_2);
		}
		else
		{
			quit = true;
		}
	} while (!quit);
	system("pause");
	return 0;
}

void game(string player1, string player2)
{
	{
		string squares[3][3];
		int player = 0, num = 0, turn=1;
		int i=0,n=0;
		int winner=-1;
		vector <int> player1vect(i), player2vect(n);

		system("cls");
		squareTracker(squares, num, player);
		boardUpdate(squares, player1, player2);
		do
		{
			//player1 turn
			cout << player1 << " - (X) turn.\n\n";
			player = 1;
			cin >> num;
			i = num;
			player1vect.push_back(i);
			squareTracker(squares, num, player);
			boardUpdate(squares, player1, player2);
			turn++;
			if (((squares[0][0] == "X") && (squares[0][1] == "X") && (squares[0][2] == "X"))||	//(123) (horizontal winning combos)
				((squares[1][0] == "X") && (squares[1][1] == "X") && (squares[1][2] == "X"))||	//(456)
				((squares[2][0] == "X") && (squares[2][1] == "X") && (squares[2][2] == "X"))||	//(789)
				((squares[0][0] == "X") && (squares[1][0] == "X") && (squares[2][0] == "X"))||	//(147) (vertical winning combos)
				((squares[0][1] == "X") && (squares[1][1] == "X") && (squares[2][1] == "X"))||	//(258)
				((squares[0][2] == "X") && (squares[1][2] == "X") && (squares[2][2] == "X"))||	//(369)
				((squares[0][0] == "X") && (squares[1][1] == "X") && (squares[2][2] == "X"))||	//(159) (diagonal winning combos)
				((squares[0][2] == "X") && (squares[1][1] == "X") && (squares[2][0] == "X")))	//(357)
			{
				winner = 1;
				break;
			}
			//player2 turn
			cout << player2 << " - (O) turn.\n\n";
			player = 2;
			cin >> num;
			n = num;
			player2vect.push_back(n);
			squareTracker(squares, num, player);
			boardUpdate(squares, player1, player2);
			turn++;
			if (((squares[0][0] == "O") && (squares[0][1] == "O") && (squares[0][2] == "O")) ||	//(123) (horizontal winning combos)
				((squares[1][0] == "O") && (squares[1][1] == "O") && (squares[1][2] == "O")) ||	//(456)
				((squares[2][0] == "O") && (squares[2][1] == "O") && (squares[2][2] == "O")) ||	//(789)
				((squares[0][0] == "O") && (squares[1][0] == "O") && (squares[2][0] == "O")) ||	//(147) (vertical winning combos)
				((squares[0][1] == "O") && (squares[1][1] == "O") && (squares[2][1] == "O")) ||	//(258)
				((squares[0][2] == "O") && (squares[1][2] == "O") && (squares[2][2] == "O")) ||	//(369)
				((squares[0][0] == "O") && (squares[1][1] == "O") && (squares[2][2] == "O")) ||	//(159) (diagonal winning combos)
				((squares[0][2] == "O") && (squares[1][1] == "O") && (squares[2][0] == "O")))	//(357)
			{
				winner = 2;
				break;
			}
			else 
			{
				if (turn >=9)
				{
					cout << "Tie Game\n\n";
					break;
				}
			}
		} while (winner<0);

		//player1 winner section
		if (winner==1)
		{
			cout << player1 << " is the winner!\n";
			cout << player1<<" won with " << player1vect.size() << " moves.\n";
			cout << "The order of " << player1 << " turns was: ";
			for (unsigned int i = 0; i < player1vect.size(); i++)
				cout << player1vect[i] << " "<<"\n\n";
		}
		//player2 winner section
		if (winner==2)
		{
			cout << player2 << " is the winner!\n";
			cout << player2 << " won with " << player2vect.size() << " moves.\n";
			cout << "The order of " << player2 << " turns was: ";
			for (unsigned int i = 0; i < player2vect.size(); i++)
				cout << player2vect[i] << " "<<"\n\n";
		}
	}
}

int squareTracker(string squares[3][3], int num, int player)// function used to keep track of the square values and not allow a square to be overwritten.
{
	//set square values
	if (player==1)
	{
		if ((num == 1) && (squares[0][0] !="O")) //when player 1 selects a square, it marks the square with an "X" 
		{										// unless the square already has an "O" in it. 
			squares[0][0] = "X";
		}
		if ((num == 2) && (squares[0][1] != "O"))
		{
			squares[0][1] = "X";
		}
		if ((num == 3) && (squares[0][2] != "O"))
		{
			squares[0][2] = "X";
		}
		if ((num == 4) && (squares[1][0] != "O"))
		{
			squares[1][0] = "X";
		}
		if ((num == 5) && (squares[1][1] != "O"))
		{
			squares[1][1] = "X";
		}
		if ((num == 6) && (squares[1][2] != "O"))
		{
			squares[1][2] = "X";
		}
		if ((num == 7) && (squares[2][0] != "O"))
		{
			squares[2][0] = "X";
		}
		if ((num == 8) && (squares[2][1] != "O"))
		{
			squares[2][1] = "X";
		}
		if ((num == 9) && (squares[2][2] != "O"))
		{
			squares[2][2] = "X";
		}
	}
	else if (player==2)
	{
		if ((num == 1) && (squares[0][0] != "X"))//when player 2 selects a square, it marks the square with an "O" 
		{										// unless the square already has an "X" in it. 
			squares[0][0] = "O";
		}
		if ((num == 2) && (squares[0][1] != "X"))
		{
			squares[0][1] = "O";
		}
		if ((num == 3) && (squares[0][2] != "X"))
		{
			squares[0][2] = "O";
		}
		if ((num == 4) && (squares[1][0] != "X"))
		{
			squares[1][0] = "O";
		}
		if ((num == 5) && (squares[1][1] != "X"))
		{
			squares[1][1] = "O";
		}
		if ((num == 6) && (squares[1][2] != "X"))
		{
			squares[1][2] = "O";
		}
		if ((num == 7) && (squares[2][0] != "X"))
		{
			squares[2][0] = "O";
		}
		if ((num == 8) && (squares[2][1] != "X"))
		{
			squares[2][1] = "O";
		}
		if ((num == 9) && (squares[2][2] != "X"))
		{
			squares[2][2] = "O";
		}
	}
	else//default square values
	{
		squares[0][0] = "1";
		squares[0][1] = "2";
		squares[0][2] = "3";
		squares[1][0] = "4";
		squares[1][1] = "5";
		squares[1][2] = "6";
		squares[2][0] = "7";
		squares[2][1] = "8";
		squares[2][2] = "9";
	}

	return(squares[3][3], num, player);
}

void boardUpdate(string squares[3][3], string player1, string player2)//function draws the board and refreshes the square values after each player plays thier turn.
{
	system("cls");

	cout << player1 << " (X) - " << player2 << " (O)\n\n";
	cout << "\n\n   Tic Tac Toe\n\n";

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
