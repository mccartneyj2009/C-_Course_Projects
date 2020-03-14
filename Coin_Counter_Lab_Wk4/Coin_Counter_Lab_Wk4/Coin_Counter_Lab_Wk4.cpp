#include <iostream>
#include <cstdlib>
using namespace std;

double coinCounter(double pennies, double nickels, double dimes, double quarters);

int main()
{
	double pen, nik, dim, qrt,value;
	cout << "Please insert pennies, nickels, dimes, and quarters.\n\n";
	cout << "Pennies inserted: \n";
	cin >> pen;
	cout << "\nNickels inserted: \n";
	cin >> nik;
	cout << "\nDimes inserted: \n";
	cin >> dim;
	cout << "\nQuarters inserted: \n";
	cin >> qrt;

	value = coinCounter(pen,nik,dim,qrt);

	cout << "\nYou have inserted: \n" << pen << " pennies\n"
		<< nik << " nickels\n" << dim << " dimes\n" << qrt << " quarters.\n\n";
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "The total value adds up to $" << value<<"\n\n";
	
	system("pause");
	return 0;
}

double coinCounter(double pennies, double nickels, double dimes, double quarters)
{
	double penValue,nikValue,dimValue, qrtValue,totalValue;
	penValue = (pennies*.01);
	nikValue = (nickels*.05);
	dimValue = (dimes*.10);
	qrtValue = (quarters*.25);

	totalValue = (penValue + nikValue + dimValue + qrtValue);
	return(totalValue);
}