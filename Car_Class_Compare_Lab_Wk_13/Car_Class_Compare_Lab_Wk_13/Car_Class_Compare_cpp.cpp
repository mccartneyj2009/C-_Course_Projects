#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class car
{
public:
	void mpgClass(int veh1, int veh2, int veh3, double mob1, double mob2, double mob3, double mob4, double mob5);   //Compare MPG
	void hpClass(int veh1, int veh2, int veh3, int mob1, int mob2, int mob3, int mob4, int mob5);    //Compare HP
	void torClass(int veh1, int veh2, int veh3, int mob1, int mob2, int mob3, int mob4, int mob5);   //Compare torque
	void spdClass(int veh1, int veh2, int veh3, double mob1, double mob2, double mob3, double mob4, double mob5);   //Compare 0-60mph Time 
	void priceClass(int veh1, int veh2, int veh3, int mob1, int mob2, int mob3, int mob4, int mob5); //Compare Price

private:
	int horsepower, torque, price;
	double mpg, acl;
};

int main()
{
	//Initializing variables
	double must[5] = {18.4,460,420,4.4,39995};//2018 Ford Mustang GT specs
	double camr[5] = {19,455,455,4.1,37995};//2018 Chevy Camaro SS specs
	double corv[5] = {18.2,650,650,2.9,79495};//2018 Corvette z06 1LZ specs
	double chrg[5] = {20,370,395,5.1,35495};//2018 Dodge Charger RT specs
	double chal[5] = {18,375,410,5.12,33995};//2018 Dodge Challenger RT specs
	vector<double> comparison;
	car car1;
	string cont;
	int c1, c2, c3, c4, c5, cp;
	bool C=1, C1C, C2C, C3C, invalid=0;

	//Program start
	cout << "Select 3 cars to compare:\n";
	cout << "Enter the numerical values associated with the cars to compare.\n\n";
	cout << "1 - 2018 Ford Mustang GT\n";
	cout << "2 - 2018 Chevrolet Camaro SS\n";
	cout << "3 - 2018 Chevrolet Corvette Z06 1LZ\n";
	cout << "4 - 2018 Dodge Charger RT\n";
	cout << "5 - 2018 Dodge Challenger RT\n\n";

	//Car Selections
	//First Car Selection
	do
	{
		cout << "Select first car.\n";
		cin >> c1; 
		cout << endl;
		if (c1 != 1 && c1 != 2 && c1 != 3 && c1 != 4 && c1 != 5)
		{
			cout << "Invalid selection. Please select a valid entry of 1-5\n";
			cin.clear();//lines prevent infinite loop
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			C1C = 1;
		}
		else if (c1 == 1 || c1 == 2 || c1 == 3 || c1 == 4 || c1 == 5)
		{
			C1C = 0;
		}
	} while (C1C == 1);
	//Second Car Selection
	do
	{
		cout << "Select Second car.\n";
		cin >> c2;
		cout << endl;
		if (c2 != 1 && c2 != 2 && c2 != 3 && c2 != 4 && c2 != 5)
		{
			cout << "Invalid selection. Please select a valid entry of 1-5\n";
			cin.clear();//lines prevent infinite loop
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			C2C = 1;
		}
		else if (c2 == 1 || c2 == 2 || c2 == 3 || c2 == 4 || c2 == 5)
		{
			C2C = 0;
		}
	} while (C2C == 1);
	//Third Car Selection
	do
	{
		cout << "Select third car.\n";
		cin >> c3;
		cout << endl;
		if (c3 != 1 && c3 != 2 && c3 != 3 && c3 != 4 && c3 != 5)
		{
			cout << "Invalid selection. Please select a valid entry of 1-5\n";
			cin.clear();//lines prevent infinite loop
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			C3C = 1;
		}
		else if (c3 == 1 || c3 == 2 || c3 == 3 || c3 == 4 || c3 == 5)
		{
			C3C = 0;
		}
	} while (C3C == 1);
	//Comparison Selections
	cout << "Select the comparisons you would like to see:\n";
	cout << "Enter the numerical values associated with the comparisons.\n\n";
	cout << "1 - Miles per Gallon (MPG)\n";
	cout << "2 - Horsepower (HP)\n";
	cout << "3 - Torque\n";
	cout << "4 - 0-60mph Time\n";
	cout << "5 - Price\n\n";
	do
	{
		cout << "Select a comparison.\n";
		cin >> cp;

		if (cp != 1 && cp != 2 && cp != 3 && cp != 4 && cp != 5)
		{
			cout << "Invalid Entry. Please select a valid entry of 1-5.\n";
			cin.clear();//lines prevent infinite loop
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			C = 1;
		}
		else if (cp == 1 || cp == 2 || cp == 3 || cp == 4 || cp == 5)
		{
			comparison.push_back(cp);
			do
			{
				cout << "Would you like to make another comparison? (Y/N)\n";
				cin >> cont;
				cout << endl;
				if (cont == "Y")
				{
					C = 1;
					invalid = 0;
				}
				else if (cont != "Y" && cont != "N")
				{
					cout << "Invalid Entry.\n";
					C = 1;
					invalid = 1; 
				}
				else
				{
					if (cont == "N")
					{
						C = 0;
						invalid = 0;
					}
				}
			} while (invalid == 1);
		}
	} while(C == 1 );
	
	system("cls");
	cout << "Comparisons........\n\n\n";
	//call functions
	for (unsigned int i = 0; i < comparison.size(); i++)//line used to search vector for comparisons that are to be made
		//call functions
		if (comparison[i] == 1)//mpg
		{
		  car1.mpgClass(c1, c2, c3, must[0], camr[0], corv[0], chrg[0], chal[0]);
		}	
	for (unsigned int i = 0; i < comparison.size(); i++)//line used to search vector for comparisons that are to be made
		//call functions
		if (comparison[i] == 2)//horsepower
		{
			car1.hpClass(c1, c2, c3, must[1], camr[1], corv[1], chrg[1], chal[1]);
		}
	for (unsigned int i = 0; i < comparison.size(); i++)//line used to search vector for comparisons that are to be made
		//call functions
		if (comparison[i] == 3)//torque
		{
			car1.torClass(c1, c2, c3, must[2], camr[2], corv[2], chrg[2], chal[2]);
		}
	for (unsigned int i = 0; i < comparison.size(); i++)//line used to search vector for comparisons that are to be made
		//call functions
		if (comparison[i] == 4)//0-60mph
		{
			car1.spdClass(c1, c2, c3, must[3], camr[3], corv[3], chrg[3], chal[3]);
		}
	for (unsigned int i = 0; i < comparison.size(); i++)//line used to search vector for comparisons that are to be made
		//call functions
		if (comparison[i] == 5)//price
		{
			car1.priceClass(c1, c2, c3, must[4], camr[4], corv[4], chrg[4], chal[4]);
		}

	cout << "End\n";
	system("pause");
	return 0; 
}
void car::mpgClass(int veh1, int veh2, int veh3, double mob1, double mob2, double mob3, double mob4, double mob5)
{
	cout << "Fued economy\n";
	if (veh1 == 1 || veh2 == 1 || veh3 == 1)
	{
		car car1;
		car1.mpg = mob1;
		cout << "2018 Ford Mustang GT Fuel Economy = " << car1.mpg << " mpg" << endl << endl;
	}
	if (veh1 == 2 || veh2 == 2 || veh3 == 2)
	{
		car car2;
		car2.mpg = mob2;
		cout << "2018 Chevrolet Camaro SS Fuel Economy = " << car2.mpg << " mpg" << endl << endl;
	}
	if (veh1 == 3 || veh2 == 3 || veh3 == 3)
	{
		car car3;
		car3.mpg = mob3;
		cout << "2018 Chevrolet Corvette Z06 1LZ Fuel Economy = " << car3.mpg << " mpg" << endl << endl;
	}
	if (veh1 == 4 || veh2 == 4 || veh3 == 4)
	{
		car car4;
		car4.mpg = mob4;
		cout << "2018 Dodge Charger RT Fuel Economy = " << car4.mpg << " mpg" << endl << endl;
	}
	if (veh1 == 5 || veh2 == 5 || veh3 == 5)
	{
		car car5;
		car5.mpg = mob5;
		cout << "2018 Dodge Challenger RT Fuel Economy = " << car5.mpg << " mpg" << endl << endl;
	}
	cout << "-----------------------------------------------------------------\n";
}

void car::hpClass(int veh1, int veh2, int veh3, int mob1, int mob2, int mob3, int mob4, int mob5)
{
	cout << "Horsepower\n";
	if (veh1 == 1 || veh2 == 1 || veh3 == 1)
	{
		car car1;
		car1.horsepower = mob1;
		cout << "2018 Ford Mustang GT Horsepower = " << car1.horsepower << " hp" << endl << endl;
	}
	if (veh1 == 2 || veh2 == 2 || veh3 == 2)
	{
		car car2;
		car2.horsepower = mob2;
		cout << "2018 Chevrolet Camaro SS Horsepower = " << car2.horsepower << " hp" << endl << endl;
	}
	if (veh1 == 3 || veh2 == 3 || veh3 == 3)
	{
		car car3;
		car3.horsepower = mob3;
		cout << "2018 Chevrolet Corvette Z06 1LZ Horsepower = " << car3.horsepower << " hp" << endl << endl;
	}
	if (veh1 == 4 || veh2 == 4 || veh3 == 4)
	{
		car car4;
		car4.horsepower = mob4;
		cout << "2018 Dodge Charger RT Horsepower = " << car4.horsepower << " hp" << endl << endl;
	}
	if (veh1 == 5 || veh2 == 5 || veh3 == 5)
	{
		car car5;
		car5.horsepower = mob5;
		cout << "2018 Dodge Challenger RT Horsepower = " << car5.horsepower << " hp" << endl << endl;
	}
	cout << "-----------------------------------------------------------------\n";
}
void car::torClass(int veh1, int veh2, int veh3, int mob1, int mob2, int mob3, int mob4, int mob5)
{
	cout << "Torque\n";
	if (veh1 == 1 || veh2 == 1 || veh3 == 1)
	{
		car car1;
		car1.torque = mob1;
		cout << "2018 Ford Mustang GT Torque = " << car1.torque << " ft-lbs" << endl << endl;
	}
	if (veh1 == 2 || veh2 == 2 || veh3 == 2)
	{
		car car2;
		car2.torque = mob2;
		cout << "2018 Chevrolet Camaro SS Torque = " << car2.torque << " ft-lbs" << endl << endl;
	}
	if (veh1 == 3 || veh2 == 3 || veh3 == 3)
	{
		car car3;
		car3.torque = mob3;
		cout << "2018 Chevrolet Corvette Z06 1LZ Torque = " << car3.torque << " ft-lbs" << endl << endl;
	}
	if (veh1 == 4 || veh2 == 4 || veh3 == 4)
	{
		car car4;
		car4.torque = mob4;
		cout << "2018 Dodge Charger RT Torque = " << car4.torque << " ft-lbs" << endl << endl;
	}
	if (veh1 == 5 || veh2 == 5 || veh3 == 5)
	{
		car car5;
		car5.torque = mob5;
		cout << "2018 Dodge Challenger RT Torque = " << car5.torque << " ft-lbs" << endl << endl;
	}
	cout << "-----------------------------------------------------------------\n";
}
void car::spdClass(int veh1, int veh2, int veh3, double mob1, double mob2, double mob3, double mob4, double mob5)
{
	cout << "Acceleration\n";
	if (veh1 == 1 || veh2 == 1 || veh3 == 1)
	{
		car car1;
		car1.acl = mob1;
		cout << "2018 Ford Mustang GT 0-60 mph = " << car1.acl << " Seconds" << endl << endl;
	}
	if (veh1 == 2 || veh2 == 2 || veh3 == 2)
	{
		car car2;
		car2.acl = mob2;
		cout << "2018 Chevrolet Camaro SS 0-60 mph = " << car2.acl << " Seconds" << endl << endl;
	}
	if (veh1 == 3 || veh2 == 3 || veh3 == 3)
	{
		car car3;
		car3.acl = mob3;
		cout << "2018 Chevrolet Corvette Z06 1LZ 0-60 mph = " << car3.acl << " Seconds" << endl << endl;
	}
	if (veh1 == 4 || veh2 == 4 || veh3 == 4)
	{
		car car4;
		car4.acl = mob4;
		cout << "2018 Dodge Charger RT 0-60 mph = " << car4.acl << " Seconds" << endl << endl;
	}
	if (veh1 == 5 || veh2 == 5 || veh3 == 5)
	{
		car car5;
		car5.acl = mob5;
		cout << "2018 Dodge Challenger RT 0-60 mph = " << car5.acl << " Seconds" << endl << endl;
	}
	cout << "-----------------------------------------------------------------\n";
}
void car::priceClass(int veh1, int veh2, int veh3, int mob1, int mob2, int mob3, int mob4, int mob5)
{
	cout << "Price\n";
	if (veh1 == 1 || veh2 == 1 || veh3 == 1)
	{
		car car1;
		car1.price = mob1;
		cout << "2018 Ford Mustang GT Price = $" << car1.price << endl << endl;
	}
	if (veh1 == 2 || veh2 == 2 || veh3 == 2)
	{
		car car2;
		car2.price = mob2;
		cout << "2018 Chevrolet Camaro SS Price = $" << car2.price << endl << endl;
	}
	if (veh1 == 3 || veh2 == 3 || veh3 == 3)
	{
		car car3;
		car3.price = mob3;
		cout << "2018 Chevrolet Corvette Z06 1LZ Price = $" << car3.price << endl << endl;
	}
	if (veh1 == 4 || veh2 == 4 || veh3 == 4)
	{
		car car4;
		car4.price = mob4;
		cout << "2018 Dodge Charger RT Price = $" << car4.price << endl << endl;
	}
	if (veh1 == 5 || veh2 == 5 || veh3 == 5)
	{
		car car5;
		car5.price = mob5;
		cout << "2018 Dodge Challenger RT Price = $" << car5.price << endl << endl;
	}
	cout << "-----------------------------------------------------------------\n";
}