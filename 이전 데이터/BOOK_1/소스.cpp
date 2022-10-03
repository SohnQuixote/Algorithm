#include <iostream>
#include <vector>
using namespace std;
int countParings(int *a, int b, int c)
{
	int result;
	int max = (b*(b + 1)) / 2;
	int calc = 0;
	int count = 0;
	for (int i = 0; i < 2 * c; i += 2)
	{
		calc = 0;
		calc += a[i] + a[i + 1];
		count++;
		if (calc == max && count == b)
		{
			result++;
			i = 0;
			count = 0;
		}

	}

}
//스택을 써야할거 같음
int main(void)
{
	int a;
	int b; int c;
	int temp;
	vector<int>b_;
	int list[90];
	vector<int>result_;
	cin >> a;
	result_.reserve(a);
	b_.reserve(a);
	for (int i = 0; i < a; i++)
	{

			cin >> b >> c;
			b_.push_back(b);
			for (int j = 0; j < 2*c; j++)
			{
				cin >> temp;
				list[j] = temp;
				result_.push_back(countParings(list,b,2*c));
			}


	}
	for (int i = 0; i < result_.size(); i++)
	{
		cout << result_.at(i) << endl;
	}

}