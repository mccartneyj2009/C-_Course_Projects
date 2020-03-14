#include <iostream>
#include <string>
using namespace std;

struct studentInfo  //Structuce that collects student information.
{
	string studentName;
	double GPA;
	int ACTscore;
	int SATscore;
};

void studentStruc(studentInfo& student, string name);
//Function used to gather all pertinent information about the student.

void studentEval(studentInfo& student);
//function used to determine if the student
//is Bad, OK, Good, Excellent.

int main()
{
	string startEval, name;
	studentInfo student;

	cout << "This program is used to determine how well a student "<< endl;
	cout << "has done on standardized tests...\n\n";
	cout << "Start student Evaluation? (Y/N)\n\n";
	cin >> startEval;

	if (startEval == "Y")
	{
		cout << "\nEnter Student name\n\n";
		cin.ignore();//This needed to inserted because the program would not stop scanning before it moved past 'getline'.
		getline(cin, name);
		studentStruc(student, name);
		studentEval(student);
	}
	else
	{
		cout << "\nGoodbye\n\n";
	}
	system("pause");
	return 0;
}


void studentStruc(studentInfo& student, string name)
{
	//User input of atleast two values is required.
	//Function used to gather all pertinent student information.
	system("cls");
	student.studentName = name;
	cout << "Enter a minimum of two values asked for." << endl;
	cout << "If student has not taken one of the standardized tests enter '0'.\n" << endl;
	cout << endl;
	cout << student.studentName<<"'s" << " GPA: ";
	cin >> student.GPA;
	cout << endl;
	cout << student.studentName << "'s" << " ACT Score: ";
	cin >> student.ACTscore;
	cout << endl;
	cout << student.studentName << "'s" << " SAT Score: ";
	cin >> student.SATscore;
	cout << endl;
}

void studentEval(studentInfo& student)
{
	//Based on user input, this function will determine if the student is bad, OK, good, or excellent.
	system("cls");
	int act, sat;
	double gpa, studentVal;
	//arrays for scores comparisons
	int stACT[] = { 0, 17 , 22 , 29 };
	int stSAT[] = { 0, 901 , 1051 , 1201 };
	double stGPA[] = { 0, 2.1, 3.0, 3.6 };

	//GPA Determination
	if (student.GPA == stGPA[0])
	{
		cout << "GPA: " << student.GPA;
		cout << ". No GPA\n";
		gpa = 0;
	}
	else if (student.GPA >= stGPA[0] && student.GPA < stGPA[1])
	{
		cout << "GPA: " << student.GPA;
		cout << ". Bad GPA\n";
		gpa = 1;
	}
	else if (student.GPA >= stGPA[1] && student.GPA < stGPA[2])
	{
		cout << "GPA: " << student.GPA;
		cout << ". OK GPA\n";
		gpa = 2;
	}
	else if (student.GPA >= stGPA[2] && student.GPA < stGPA[3])
	{
		cout << "GPA: " << student.GPA;
		cout << ". Good GPA\n";
		gpa = 3;
	}
	else if (student.GPA >= stGPA[3])
	{
		cout << "GPA: " << student.GPA;
		cout << ". Excellent GPA\n";
		gpa = 4;
	}
	//ACT Determination
	if (student.ACTscore == stACT[0])
	{
		cout << "ACT Score: " << student.ACTscore;
		cout << ". No ACT Score\n";
		act = 0;
	}
	else if (student.ACTscore >= stACT[0] && student.ACTscore < stACT[1])
	{
		cout << "ACT Score: " << student.ACTscore;
		cout << ". Bad ACT Score\n";
		act = 1;
	}
	else if (student.ACTscore >= stACT[1] && student.ACTscore < stACT[2])
	{
		cout << "ACT Score: " << student.ACTscore;
		cout << ". OK ACT Score\n";
		act = 2;
	}
	else if (student.ACTscore >= stACT[2] && student.ACTscore < stACT[3])
	{
		cout << "ACT Score: " << student.ACTscore;
		cout << ". Good ACT Score\n";
		act = 3;
	}
	else if (student.ACTscore >= stACT[3])
	{
		cout << "ACT Score: " << student.ACTscore;
		cout << ". Excellent ACT Score\n";
		act = 4;
	}
	//SAT Determination
	if (student.SATscore == stSAT[0])
	{
		cout << "SAT Score: " << student.SATscore;
		cout << ". No SAT Score\n";
		sat = 0;
	}
	else if (student.SATscore >= stSAT[0] && student.SATscore < stSAT[1])
	{
		cout << "SAT Score: " << student.SATscore;
		cout << ". Bad SAT Score\n";
		sat = 1;
	}
	else if (student.SATscore >= stSAT[1] && student.SATscore < stSAT[2])
	{
		cout << "SAT Score: " << student.SATscore;
		cout << ". OK SAT Score\n";
		sat = 2;
	}
	else if (student.SATscore >= stSAT[2] && student.SATscore < stSAT[3])
	{
		cout << "SAT Score: " << student.SATscore;
		cout << ". Good SAT Score\n";
		sat = 3;
	}
	else if (student.SATscore >= stSAT[3])
	{
		cout << "SAT Score: " << student.SATscore;
		cout << ". Excellent SAT Score\n";
		sat = 4;
	}
	//do average to decide about the student
	if (gpa != 0 && act != 0 && sat != 0)
	{
		studentVal = (((gpa + act + sat) / 3));
		cout << endl;
	}
	else
	{
		studentVal = ((gpa + act + sat) / 2);
		cout << endl;
	}
	//Declaration about student
	if ((studentVal ==0) || (gpa + act == 0) || (gpa + sat == 0) || (act + sat == 0))
	{
		cout << "\nNot enough information provided.\n\n";
	}
	else if (studentVal >= 1 && studentVal < 2)
	{
		cout << "\nBased on the given information, " << endl;
		cout << student.studentName << " is considered a bad student" << endl;
	}
	else if (studentVal >= 2 && studentVal < 3)
	{
		cout << "\nBased on the given information, " << endl;
		cout << student.studentName << " is considered an OK student" << endl;
	}
	else if (studentVal >= 3 && studentVal < 4)
	{
		cout << "\nBased on the given information, " << endl;
		cout << student.studentName << " is considered a good student" << endl;
	}
	else if (studentVal >= 4)
	{
		cout << "\nBased on the given information, " << endl;
		cout << student.studentName << " is considered an excellent student" << endl;
	}
}