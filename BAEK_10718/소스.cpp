#include <iostream>

using namespace std;
int find(int a, int b, int c)
{
	if (a>b&&b >= c)
	{
		return b;
	}
	else if (a>c && c >= b)
	{
		return c;
	}
	else if (b>a && a >= c)
	{
		return a;
	}
	else if (b>c&& c >= a)
	{
		return c;
	}
	else if (c>b && b >= a)
	{
		return b;
	}
	else if (c>a && a >= b)
	{
		return a;
	}

}
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << find(a, b, c);
}