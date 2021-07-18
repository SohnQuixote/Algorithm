#include <iostream>
#include <cmath>

using namespace std;
int test(int a)
{
	if (a == 1)
	{
		return 0;
	}
	for (int i = 2; i<a; i++)
	{
		if (a%i == 0)
			return 0;
	}
	return 1;
}
int main(void)
{

	int n;
	int temp;
	cin >> n;
	int result = 0;
	for (int i = 0; i<n; i++)
	{
		cin >> temp;
		if (test(temp) == 1)
		{
			result++;
		}
	}
	cout << result;
}