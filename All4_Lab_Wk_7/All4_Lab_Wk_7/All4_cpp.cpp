#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void dist(float avgMPG, int fuel, int totdist);//overloaded function
void dist(float& mpg, int& fuel, float& totdist);//overloaded function


void dist(float avgMPG, int fuel, int totdist=1)//Call-by-Value and default parameter of totdist
{
	float miles;
	miles = (avgMPG * fuel)/totdist;
	cout << "\nThe distance you can travel on a full tank of gas is " << miles << " miles\n\n";
}

void dist(float& mpg, int& fuel, float& totdist)//Call-by-Reference
{
	float miles;
	float totTanks;
	miles = mpg * fuel;
	totTanks =totdist/miles;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	if (totTanks>0 && totTanks<=1)
	{
		totTanks = 1;
		cout << "\nYou will need to fill your gas tank " << totTanks << " time while on your trip.\n";
	}
	else
	{
		totTanks = totTanks;
		cout << "\nYou will need to fill your gas tank " << totTanks << " times while on your trip.\n";
	}
}


int main()
{
	float AverageMPG, TotalDistance;
	int FuelCap;

	cout << "Use this calculator to determine how many tanks of gas you will\n"
		"need during a trip.\n\n";
	cout << "What is your vehicles average MPG?\n";
	cin >> AverageMPG;
	cout << "\nWhat is the capacity of the fuel tank?\n";
	cin >> FuelCap;
	dist(AverageMPG, FuelCap);//overloaded function
	cout << "What is the total distance of your trip?\n";
	cin >> TotalDistance;
	dist(AverageMPG, FuelCap, TotalDistance);//overloaded function
	cout << "Average Miles per Gallon: " << AverageMPG<<"\n";
	cout << "Fuel tank capacity: " << FuelCap<<"\n\n";

	system("pause");
	return 0;
}
