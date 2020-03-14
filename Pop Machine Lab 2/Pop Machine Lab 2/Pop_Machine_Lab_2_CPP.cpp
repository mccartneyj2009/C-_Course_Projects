#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Items and Prices
		cout << "A: $.50\n";
		cout << "B: $1.00\n";
		cout << "C: $1.50\n";
		cout << "D: $2.00\n";
		cout << "E: $.75\n";
		cout << "F: $2.50\n";
	//Customer Selection
		double OrigPrice;
		int A, B, C, D, E, F;
		A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
		do
		{
			cout << "\nPlease make selection between A and F: ";
			char SelectedItem;
			cin >> SelectedItem;
			//Switches
			switch (SelectedItem)
				{
				case 'A':
				case 'a':
					cout << "\nSelection: A\n";
					cout << "Price: $.50\n";
					OrigPrice = .50;
					A = 1;
					break;
				case 'B':
				case 'b':
					cout << "Selection: B\n";
					cout << "Price: $1.00\n";
					OrigPrice = 1.00;
					B = 1;
					break;
				case 'C':
				case 'c':
					cout << "Selection: C\n";
					cout << "Price: $1.50\n";
					OrigPrice = 1.50;
					C = 1;
					break;
				case 'D':
				case 'd':
					cout << "Selection: D\n";
					cout << "Price: $2.00\n";
					OrigPrice = 2.00;
					D = 1;
					break;
				case 'E':
				case 'e':
					cout << "Selection: E\n";
					cout << "Price: $.75\n";
					OrigPrice = .75;
					E = 1;
					break;
				case 'F':
				case 'f':
					cout << "Selection: F\n";
					cout << "Price: $2.50\n";
					OrigPrice = 2.50;
					F = 1;
					break;
				default:
					cout << "Invalid selection.\n";
				}
		} while (A != 1 && B != 1 && C != 1 && D != 1 && E != 1 && F != 1);
	//Calcs
		double RemBal, MoneyIns;
		cout << "\nPlease Insert Money (Numerical value only. No special characters): ";
		cin >> MoneyIns;
		//Remaining Balance
			RemBal = 0;
			RemBal = OrigPrice - MoneyIns;
				if (RemBal < 0)
				{
					cout << "\nChange Due: $" << -RemBal << "\nHave a nice day!\n\n";
				}
				else if (RemBal > 0)
				{
					do
					{
						cout << "Remaining Balance: $" << RemBal << "\n\n";
						cout << "Please insert remaining balance: ";
						cin >> MoneyIns;
						RemBal = RemBal - MoneyIns;
					} while (RemBal > 0);
				}
				if (RemBal==0)
				{
					cout << "\nChange Due: $" << RemBal << "\nHave a nice day!\n\n";
				}
				if (RemBal < 0)
				{
					cout << "\nChange Due: $" <<-RemBal << "\nHave a nice day!\n\n";
				}
system("pause");
return 0;
}