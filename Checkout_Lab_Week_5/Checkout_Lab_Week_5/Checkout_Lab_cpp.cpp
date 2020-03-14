#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

double subTotal(double price, double quantity, double subTot);
double taxTotal(double tax, double subTot);
double CouponCode(double code, double taxTot);

int main()
{
	double price=0, quant=0, sub = 0, taxTot=0, deduct=0, finalTot;
	char coup = 'n';

	sub = subTotal(price, quant, sub);
	taxTot = taxTotal(taxTot, sub);

	cout << "\nThe total after tax is: $" << taxTot << "\n\n";
	cout << "Do you have a coupon code? (y/n): \n";
	cin >> coup;

	if (coup == 'y')
	{
		finalTot = CouponCode(deduct, taxTot);
		cout << "\nTotal Due: $" << finalTot << "\n\n";
	}
	else
	{
		cout << "Total due: $" << taxTot << "\n\n";
	}


	system ("pause");
	return 0;
}

double subTotal(double price, double quantity, double subTot)
{
	double newsub, oldsub=0;
	char ans;
	ans = 'y';

	do
	{
	cout << "Enter quantity: \n";
	cin >> quantity;
	cout << "Enter price: \n";
	cin >> price;
	subTot = price * quantity;
	newsub = subTot + oldsub;
	oldsub = newsub;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "The Sub-Total is: $" << newsub << "\n\n";
	cout << "Would you like to add more items? (y/n)\n";
	cin >> ans;
    } while (ans == 'y' || ans == 'Y');

	return(newsub);
}
double taxTotal(double tax, double subTot)
{
	double afterTaxTotal, taxRate = .05;
	tax = subTot*taxRate;
	afterTaxTotal = subTot + tax;
	return(afterTaxTotal);
}
double CouponCode(double code, double taxTot)
{
	int coupCode, n;
	double final;
	cout << "Please enter coupon code (5-digit numerical value): \n";
	cin >> coupCode;
	n = coupCode % 10;
	if (n==1)
	{
		final = taxTot * .5;
	}
	else if(n==5 && taxTot<5)
	{
		final = 0;
	}
	else if (n == 5 && taxTot >= 5)
	{
		final = taxTot - 5;
	}
	else
	{
		cout << "Invalid coupon code.\n\n";
		final = taxTot;
	}
	return (final);
}