#include <vector>
#include <iostream>

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

vector<int>temp;
void calc(int n, int m)
{


	for (int i = n; i<m; i++)
	{
		if (test(i) == 1)
		{
			temp.push_back(i);
		}
	}

}
int main(void)
{
	int n, m;


	cin >> n >> m;
	temp.reserve(m - n);
	calc(n, m);
	int result = 0;
	if (temp.size() == 0)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i<temp.size(); i++)
	{
		result += temp.at(i);
	}
	cout << result << endl << temp.at(0) << endl;
	return 0;
}