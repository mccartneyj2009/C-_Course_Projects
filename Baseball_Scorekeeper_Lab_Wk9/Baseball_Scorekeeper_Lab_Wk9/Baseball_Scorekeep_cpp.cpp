#include <iostream>
#include <string>
using namespace std;

int main()
{
	int hinscore, ainscore, hscore=0, ascore=0, inn, i;
	const int MAXinn = 20;
	string homeTeam, awayTeam;

	//intro stuff
	cout << "Home team name: \n";//Home Team
	getline(cin, homeTeam);
	cout <<"\nThe home team is: "<< homeTeam<< "\n\n";
	cout << "Away team name: \n"; //Away Team 
	getline(cin, awayTeam);
	cout << "\nThe away team is: " << awayTeam << "\n\n";
	cout << "PLAY BALL!\n\n";

	//game
	for (inn=1; inn <10; inn++)
			{
				//outputs
				cout << "Inning " << inn << "\n";
				cout << awayTeam << " Score: " << ascore << "\n";
				cout << homeTeam << " Score: " << hscore << "\n\n";
				//Score input from user
				cout <<"During the " << inn << " inning, the " << awayTeam << " scored "; cin >> ainscore;
				cout <<"During the " << inn << " inning, the " << homeTeam << " scored "; cin >> hinscore;
				//math and logic
				int homeScore[MAXinn], awayScore[MAXinn], inning[MAXinn];
				inning[inn] = inn;
				homeScore[inn] = hinscore;
				awayScore[inn] = ainscore;
				hscore = homeScore[inn] + hscore;
				ascore = awayScore[inn] + ascore;
				//End of inning recap
				cout << "\nAt the end of the " << inn << " inning, the " << awayTeam << " have scored " << ascore << endl;
				cout<<"and the "<<homeTeam<<" have scored "<<hscore<<".\n\n";	
				if (inn == 9 && hscore != ascore) break;
			}
	//after 9 innings a team has won
	if (inn == 9)
	{
		if (hscore > ascore)//Home team won
		{
			cout << "The " << homeTeam << " are the winners of todays game.\n\n";
			cout << "The final score of todays game is, "<< endl;
			cout << "the " << homeTeam << " " << hscore << endl;
			cout << "the " << awayTeam << " " << ascore << endl;
		}
		else if (hscore < ascore)//Away team won
		{
			cout << "The " << awayTeam << " are the winners of todays game.\n\n";
			cout << "The final score of todays game is, " << endl;
			cout << " the " << awayTeam << " " << ascore << endl;
			cout << " the " << homeTeam << " " << hscore << endl;
		}
	}
	else //after 9 innings a team has not won
	{
		for (inn>9 && inn<MAXinn && hscore==ascore;i=true;)
		{
			//outputs
			cout << "Tie Game.\n\n";
			cout << "Inning " << inn << "\n";
			cout << awayTeam << " Score: " << ascore << "\n";
			cout << homeTeam << " Score: " << hscore << "\n\n";
			//Score input from user
			cout << "During the " << inn << " inning, the " << awayTeam << " scored "; cin >> ainscore;
			cout << "During the " << inn << " inning, the " << homeTeam << " scored "; cin >> hinscore;
			//math and logic
			int homeScore[MAXinn], awayScore[MAXinn], inning[MAXinn];
			inning[inn] = inn;
			homeScore[inn] = hinscore;
			awayScore[inn] = ainscore;
			hscore = homeScore[inn] + hscore;
			ascore = awayScore[inn] + ascore;
			//End of inning recap
			cout << "\nAt the end of the " << inn << " inning, the " << awayTeam << " have scored " << ascore << endl;
			cout << "and the " << homeTeam << " has scored " << hscore << ".\n\n";
			inn++;
			if (hscore != ascore) break;
		}
		if (hscore > ascore)//Home team won
		{
			cout << "The " << homeTeam << " are the winners of todays game.\n\n";
			cout << "The final score of todays game is, " << endl;
			cout << "the " << homeTeam << " " << hscore << endl;
			cout << "the " << awayTeam << " " << ascore << endl;
		}
		else if (hscore < ascore)//Away team won
		{
			cout << "The " << awayTeam << " are the winners of todays game.\n\n";
			cout << "The final score of todays game is, " << endl;
			cout << "the " << awayTeam << " " << ascore << endl;
			cout << "the " << homeTeam << " " << hscore << endl;
		}
	}
	system("pause");
	return 0;
}
