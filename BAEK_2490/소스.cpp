#include <iostream>

using namespace std;

int main(void)
{
	// �� 0 �� 1 ���������� ABCDE 32104
	int a, b, c, d;
	int temp;
	for (int i = 0; i<3; i++)
	{
		cin >> a >> b >> c >> d;
		temp = a + b + c + d;
		switch (temp)
		{
		case 3:
			cout << "A" << endl;
			break;
		case 2:
			cout << "B" << endl;
			break;
		case 1:
			cout << "C" << endl;
			break;
		case 0:
			cout << "D" << endl;
			break;
		case 4:
			cout << "E" << endl;
			break;

		}


	}

}