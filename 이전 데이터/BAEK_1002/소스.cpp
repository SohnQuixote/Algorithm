#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

double calc_distance(int a, int b, int c, int d)
{
	return sqrt(((double)a - (double)c)*((double)a - (double)c) + ((double)b - (double)d)*((double)b - (double)d));
}
int main(void)
{
	int t;
	int x_1, y_1, r_1, x_2, y_2, r_2;

	//scanf("%d", &t);
	cin >> t;
	double distance;
	vector<int> v;
	v.reserve(t);
	for (int i = 0; i<t; i++)
	{
		//scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);

		cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		distance = calc_distance(x_1, y_1, x_2, y_2);
		if (distance == 0)
		{
			if (r_1 == r_2)
			{
				v.push_back(-1);

			}
			if (r_1 != r_2)
			{
				v.push_back(0);
			}
		}
		else if (distance == (r_1 + r_2))
		{
			v.push_back(1);
		}
		else if (distance<(r_1 + r_2))
		{
			v.push_back(2);
		}

		else if (distance>(r_1 + r_2))
		{
			v.push_back(0);
		}
	}
	for (int i = 0; i<t; i++)
	{
		//printf("%d ", v.at(i));
		cout << v.at(i);
	}

}