#include <iostream>
#include <string>
using namespace std;

int main()
{
	for (int bottles = 20; bottles >= 0; bottles--)
	{
		if (bottles == 0)
		{
			cout << "ZERO......";
			break;
		}
		cout << bottles << " bottles of beer......." << endl;

	}
	system("pause");
	return 0;
}