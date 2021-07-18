#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
int fac(int a)
{
	if (a == 1)
	{
		return 1;
	}
	else
	{
		return a * fac(a - 1);
	}
}
int calc(int a, int b)
{
	return fac(a) / fac(a - b)*fac(b);
}
int main(void)
{
	int t;
	int n, m;
	vector <int> v;
	cin >> t;
	v.reserve(t);
	for (int i = 0; i<t; i++)
	{
		cin >> n >> m;
		v.push_back(calc(n, m));
	}
	for (int i = 0; i<t; i++)
	{
		cout << v.at(i);
	}
}