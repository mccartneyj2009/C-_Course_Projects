#include <iostream>
#include <string>
using namespace std;

int main()

{
	string CarMake;
	string CarModel;
	int CarYear;
	int CarMilage;
	string CarColor;

	//Determining Car Make
	cout << "Please enter car make: ";
	cin >> CarMake;

	//Determining Car Model
	cout << "Please enter car model: ";
	cin >> CarModel;

	//Determining Car Year
	cout << "Please enter car year: ";
	cin >> CarYear;

	//Determining Car Mileage
	cout << "Please enter car milage: ";
	cin >> CarMilage;

	//Determining Car Color
	cout << "Please enter car color: ";
	cin >> CarColor;

	//System response
	cout << "The car is a " << CarColor << " " << CarYear << " " << CarMake << " " <<
		CarModel << " with " << CarMilage << " Miles." << endl;
	if (CarMilage > 100000) {
		cout << "This car has a lot of miles.";
	}

	//Keeps window open until enter is pressed 1 additional time
	cin.clear();
	cin.ignore();
	cin.get();


	return 0;
}