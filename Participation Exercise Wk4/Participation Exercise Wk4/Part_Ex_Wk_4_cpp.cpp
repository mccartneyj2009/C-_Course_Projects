#include <iostream>
#include <cstdlib>
using namespace std;

double numberAverage(double number1, double number2, double number3, double Average);

int main()
{
	double num1, num2, num3, numAvg,avg;
	numAvg = 0;
	cout << "Enter first number: \n\n";
	cin >> num1;
	cout << "Enter second number: \n\n";
	cin >> num2;
	cout << "Enter third number: \n\n";
	cin >> num3;

	avg = numberAverage(num1, num2, num3, numAvg);
	cout << "The average of the three numbers is " << avg << ".\n\n";

	system("pause");
	return 0;
}

double numberAverage(double number1, double number2, double number3, double Average)
{
	int totNum = 3;
	Average = (number1 + number2 + number3) / totNum;
	return(Average);
}