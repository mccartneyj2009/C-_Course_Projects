#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <ctime>


using namespace std;

//******************************Program Description*********************************//
//Program used for car rental purposes. User will answer a series of questions when 
//prompted by the system. Based on the user repsonses, the program will decide which
//vehicle fits the users preferences. 
//*********************************************************************************//

//based on user feed back, output the nearest selection available
//verify selection is valid
//if not valid run program again
//if valid ask how long the rental is needed
//based on user input, print the equivalent of a receipt with 
//car make, model, price, and duration of rental
//output when the car needs to be returned based on the system time.


//preferred car (class)
class PrefCar
{
public:
	double rental(int&, int&, double&, int&);

private:
	int econ, vehClass, price;
};

//Declaration of Functions
int ageLimit(int&, int&);//Function to determine if old enough to rent.
int fuelDecision(string EcImportant, int& fuelEco);//Function to decide about fuel economy.
int ClassDecision(string cClass, int&);//Function to decide about fuel economy.
double PriceRange(double&, double&);//Function to determine price range acceptable to user.
void carFinalized(int&);//Function used to finalize car selection and duration.

//Main Program start
int main() 
{
	//Initializing
	int allowed=0, userAge, FECO=0, carType=0, carChoice=0;
	double UserpRange, pRange;
	bool runPG = 1, ins = 1, fuelValid = 1, ClassValid = 1, PriceValid=1;
	string carClass, fuelEc, runProgram, insured;
	PrefCar preferredCar;

	//Description of program to user
	cout << "This program is used to help a user find a car to rent.\n";
	cout << "The user will be prompted with a series of questions to help\n";
	cout << "determine which car will fit the users parameters.\n\n";

	//Main Loop will continue to run while user indicates that they want to rent a vehicle.
	do
	{
		cout << "Would you like to find a car to rent? (Yes/No)\n";
		cin >> runProgram;
		if (runProgram == "Yes"|| runProgram == "yes" || runProgram == "Y" || runProgram == "y" || runProgram == "YES")
		{
			system("cls");
			//portion of program that executes when the user indicates that they want to rent a vehicle.
			cout << "Please your age:\n";
			cin >> userAge;
			ageLimit(userAge, allowed);
			//if user is old enough, this runs
			if (allowed==1)
			{
				do
				{
					cout << "Are you insured? (Yes/No)\n";
					cin >> insured;
					if (insured == "Yes" || insured == "yes" || insured == "Y" || insured == "y" || insured == "YES")
					{
						//Fuel Economy
						do
						{
							cout << "Is fuel economy important? (Yes/No)\n";
							cin >> fuelEc;
							if (fuelEc == "Yes" || fuelEc == "yes" || fuelEc == "Y" || fuelEc == "y" || fuelEc == "YES"||
								fuelEc == "No" || fuelEc == "no" || fuelEc == "N" || fuelEc == "n" || fuelEc == "NO")
							{
								fuelDecision(fuelEc, FECO);
								fuelValid = 0;
							}
							else
							{
								cout << "Invalid entry. Please enter Yes or No.\n";
								cin.clear();//lines prevent infinite loop
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								ins = 1;
							}
						} while (fuelValid==1);

						//Car Class Type
						do
						{
							cout << "What vehicle class is preferred?\n";
							cout << "Please choose one of the following class types: Coupe, Sedan, SUV, Van, Truck\n";
							cin >> carClass;
							if (carClass =="Coupe"|| carClass == "coupe"||carClass =="COUPE" ||
								carClass == "Sedan"|| carClass == "sedan" || carClass == "SEDAN"||
								carClass == "SUV" || carClass == "suv" || carClass == "Suv" ||
								carClass == "Van" || carClass == "van" || carClass == "VAN" ||
								carClass == "Truck" || carClass == "truck" || carClass == "TRUCK")
							{
								ClassDecision(carClass, carType);
								ClassValid = 0;
							}
							else
							{
								cout << "Invalid entry.\n";
								cin.clear();//lines prevent infinite loop
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								ClassValid = 1;
							}
						} while (ClassValid==1);
					
						//Price Range
						do
						{
							cout << "What is the desired price range? (Per day)\n";
							cout << "$15, $25, $35, $50, $75, $100\n";
							cout << "(Enter numeric value only. No special characters.)\n";
							cin >> UserpRange;
							if (UserpRange> 0)
							{
								PriceRange(UserpRange,pRange);
								PriceValid = 0;
							}
							else
							{
								cout << "Invalid entry.\n";
								cin.clear();//lines prevent infinite loop
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								PriceValid = 1;
							}
						} while (PriceValid==1);
						preferredCar.rental(FECO, carType, pRange, carChoice);
						carFinalized(carChoice);
						ins = 0;
					}
					else if (insured == "No" || insured == "no" || insured == "N" || insured == "n" || insured == "NO")
					{
						//if not insured, this runs.
						cout << "Sorry. You must be insured to rent a vehicle.\n";
						break;
					}
					else //Invalid entry
					{
						cout << "Invalid entry. Please enter Yes or No.\n";
						cin.clear();//lines prevent infinite loop
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						ins = 1;
					}
				} while (ins==1);
				break;
			}
			else //if user is not old enough, this runs.
			{
				cout << "Sorry. You are not old enough to rent.\n";
				break;
			}
			runPG = 1;

		}
		else if (runProgram == "No" || runProgram == "no" || runProgram == "N" || runProgram == "n" || runProgram == "NO") //User does not wish to rent.
		{
			cout << "Program Terminated\n";
			runPG = 0;
		}
		else //Invalid entry
		{
			cout << "Invalid entry. Please enter Yes or No.\n";
			cin.clear();//lines prevent infinite loop
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			runPG = 1;
		}
	} while (runPG==1);
	
	system("pause");
	return 0;
}

int ageLimit(int& age, int& allwd)
{

	if (age > 21)
	{
		allwd = 1;
	}
	else if (age < 21)
	{
		allwd = 0;
	}

	return (allwd);
}

int fuelDecision(string EcImportant, int& fuelEco)
{
	//fuel economy decision
	if (EcImportant == "Yes" || EcImportant == "yes" || EcImportant == "Y" || EcImportant == "y" || EcImportant == "YES")
	{
		fuelEco = 1;
	}
	else if (EcImportant == "No" || EcImportant == "no" || EcImportant == "N" || EcImportant == "n" || EcImportant == "NO")
	{
		fuelEco = 0;
	}
	return fuelEco;
}

int ClassDecision(string cClass, int& cType)
{
	//Car Type decision. Class types: Coupe, Sedan, SUV, Van, Truck\n";
	if (cClass == "Coupe" || cClass == "coupe" || cClass == "COUPE")
	{
		cType = 1;
	}
	else if (cClass == "Sedan" || cClass == "sedan" || cClass == "SEDAN")
	{
		cType = 2;
	}
	else if (cClass == "SUV" || cClass == "suv" || cClass == "Suv")
	{
		cType = 3;
	}
	else if (cClass == "Van" || cClass == "van" || cClass == "VAN")
	{
		cType = 4;
	}
	else if (cClass == "Truck" || cClass == "truck" || cClass == "TRUCK")
	{
		cType = 5;
	}
	return cType;
}

double PriceRange(double& UserPrice, double& price)
{
	if (UserPrice<=15)
	{
		price = 1;
	}
	else if (UserPrice>15 && UserPrice<=25)
	{
		price = 2;
	}
	else if (UserPrice > 25 && UserPrice <= 35)
	{
		price = 3;
	}
	else if (UserPrice > 35 && UserPrice <= 50)
	{
		price = 4;
	}
	else if (UserPrice > 50 && UserPrice <= 75)
	{
		price = 5;
	}
	else if (UserPrice > 75 && UserPrice <= 100)
	{
		price = 6;
	}
	else if (UserPrice > 100)
	{
		price = 7;
	}

	return price;
}

void carFinalized(int& finalCarChoice)
{
	system("cls");
	string custAns;
	int days, RentalTotal;

	time_t t = time(0);
	tm* now = localtime(&t);

	if (finalCarChoice == 1)
	{
		//car 1
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Honda Civic.\n";
		cout << "Mpg = 31\n";
		cout << "The price per day for rental is $15/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 15 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout<<"in "<<days<<" days from "<<now->tm_mon + 1 << "-" << now->tm_mday << "-"<<(now->tm_year+1900)<<"\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
	if (finalCarChoice == 2)
	{
		//car 2
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Chevrolet Corvette.\n";
		cout << "Mpg = 16\n";
		cout << "The price per day for rental is $100/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 100 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
	if (finalCarChoice == 3)
	{
		//car 3
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Chevrolet Impala.\n";
		cout << "Mpg = 22\n";
		cout << "The price per day for rental is $25/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 25 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
	if (finalCarChoice == 4)
	{
		//car 4
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Chrysler 300.\n";
		cout << "Mpg = 19\n";
		cout << "The price per day for rental is $35/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 35 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
	if (finalCarChoice == 5)
	{
		//car 5
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Toyota RAV4.\n";
		cout << "Mpg = 23\n";
		cout << "The price per day for rental is $35/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 35 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
	if (finalCarChoice == 6)
	{
		//car 6
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Ford Explorer.\n";
		cout << "Mpg = 19\n";
		cout << "The price per day for rental is $50/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 50 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
	if (finalCarChoice == 7)
	{
		//car 7
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Ford Transit Wagon (12 passenger).\n";
		cout << "Mpg = 16\n";
		cout << "The price per day for rental is $50/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 50 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}

	}
	if (finalCarChoice == 8)
	{
		//car 8
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Dodge Grand Caravan.\n";
		cout << "Mpg = 20\n";
		cout << "The price per day for rental is $25/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 25 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
	if (finalCarChoice == 9)
	{
		//car 9
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Ford F-150.\n";
		cout << "Mpg = 20\n";
		cout << "The price per day for rental is $75/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 75 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
	if (finalCarChoice == 10)
	{
		//car 10
		cout << "The car chosen based on the given parameters is a \n";
		cout << "Nissan Frontier.\n";
		cout << "Mpg = 19\n";
		cout << "The price per day for rental is $35/day.\n";
		cout << "How many days will you be renting?\n";
		cin >> days;
		RentalTotal = 35 * days;
		cout << "The total for " << days << " days is $" << RentalTotal << ".\n";
		cout << "Do you wish to proceed with this transaction? (Yes/No)\n";
		cin >> custAns;
		if (custAns == "Yes" || custAns == "yes" || custAns == "YES" || custAns == "Y" || custAns == "y")
		{
			cout << "Thank you. Please make sure to return your rental\n";
			cout << "in " << days << " days from " << now->tm_mon + 1 << "-" << now->tm_mday << "-" << (now->tm_year + 1900) << "\n";
		}
		else if (custAns == "No" || custAns == "no" || custAns == "NO" || custAns == "N" || custAns == "n")
		{
			cout << "Please start process over to try and determine a selection that \n";
			cout << "better fits your needs.\n";
		}
	}
}

double PrefCar::rental(int& fuel, int& type, double& price, int& decision)
{
	//Declarations and value setting
	PrefCar selectedCar;
	selectedCar.econ = fuel;
	selectedCar.vehClass = type;
	selectedCar.price = price;
	int userInputArray[3] = { selectedCar.vehClass, selectedCar.econ,selectedCar.price };
	int coupe1[3] = { 1,1,1 };//{Vehicle Class, Fuel Efficient, Price Range}
	int coupe2[3] = { 1,0,6 };
	int sedan1[3] = { 2,1,2 };
	int sedan2[3] = { 2,0,3 };
	int suv1[3] = { 3,1,3 };
	int suv2[3] = { 3,0,4 };
	int van1[3] = { 4,1,2 };
	int van2[3] = { 4,0,4 };
	int truck1[3] = { 5,1,5 };
	int truck2[3] = { 5,0,3 };
	int car=0;

	//coupe selected
	if (userInputArray[0]==1)
	{
		if (userInputArray[1] == 1)
		{
			car = 1;
		}
		else if (userInputArray[2] <= coupe2[2])
		{
			car = 1;
		}
		else if (userInputArray[2]>5)
		{
			car =2;
		}
	}
	//sedan selected
	if (userInputArray[0] == 2)
	{
		if (userInputArray[1] == 1)
		{
			car = 3;
		}
		else if (userInputArray[2] <= sedan2[2])
		{
			car = 3;
		}
		else if (userInputArray[2] >= 5)
		{
			car = 4;
		}
	}
	//suv selected
	if (userInputArray[0] == 3)
	{
		if (userInputArray[1] == 1)
		{
			car = 5;
		}
		else if (userInputArray[2] <= suv2[2])
		{
			car = 5;
		}
		else if (userInputArray[2] >= 5)
		{
			car = 6;
		}
	}
	//van selected
	if (userInputArray[0] == 4)
	{
		if (userInputArray[1] == 1)
		{
			car = 7;
		}
		else if (userInputArray[2] <= van2[2])
		{
			car = 7;
		}
		else if (userInputArray[2] >= 5)
		{
			car = 8;
		}
	}
	//truck selected
	if (userInputArray[0] == 5)
	{
		if (userInputArray[1] == 1)
		{
			car = 9;
		}
		else if (userInputArray[2] <= truck1[2])
		{
			car = 10;
		}
		else if (userInputArray[2] >= 5)
		{
			car = 9;
		}
	}
	decision = car;
	return decision;
}
