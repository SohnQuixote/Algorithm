#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
/*
  와일드 카드
  *이 문제
*/
int c;
string card, test;
int cache[101][101];
int max(int a, int b)
{
	int result;
	return result = a > b ? a : b;
}
int chk(int c, int t)
{
	int &result = cache[c][t];
	if (result != -1)
		return result;
	if (c == card.size() && t == test.size())
		return result = 1;
	if (card[c] == '*')
	{
		for (int i = t; i <= test.size(); i++)
			result = max(result, chk(c + 1, i));
		return result;
	}
	else if (card[c] == '?')
	{
		result = chk(c + 1, t + 1);
		return result;
	}
	else
	{
		if (card[c] == test[t])
		{
			result = chk(c + 1, t + 1);
			return result;
		}
		else
			return result = 0;



	}



	return result;
}


int main() {
	cin >> c;
	for (int tc = 0; tc < c; tc++)
	{
		
		cin >> card;
		int N;
		cin >> N;
		vector<string>result;
		for (int idx = 0; idx < N; idx++)
		{
			cin >> test;
			memset(cache, -1, sizeof(cache));
			if (chk(0, 0) == 1)
			{
				result.push_back(test);
			}

		}
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << '\n';

	}
}