#include <iostream>
using namespace std;
bool areFriends[10][10];
void initFriends(bool a[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			a[i][j] =false;
		}
	}
}
int calc_result(bool taken[10],int n)
{
	int result = 0;
	//재귀호출 앞에부분에는 언제나 기저사례가 있어야 한다.
	int flag = 1;
	int first_free = -1;
	for (int i = 0; i < n; i++)
	{
		if (taken[i] == false)
		{
			flag = 0;
			first_free = i;
			break;
		}
	}
	if (flag)
	{
		return 1;
	}

	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (taken[i] == false && taken[j] == false && areFriends[i][j] == true)
			{
				taken[i] = true;
				taken[j] = true;
				result += calc_result(taken, n);
				taken[i] = false;
				taken[j] = false;
			}


		}




	}*/
	for (int pair_with = first_free + 1; pair_with < 10; pair_with++)
	{
		if (taken[first_free] == false && taken[pair_with] == false && areFriends[first_free][pair_with] == true)
		{
			taken[first_free] = true;
			taken[pair_with] = true;
			result += calc_result(taken, n);
			taken[first_free] = false;
			taken[pair_with] = false;
			//이렇게 하고 리턴해야지 호출한곳에서 다른 조합을 시도할 수 있음
		}


	}
	return result;

	//재귀호출로 해결
}
int main(void)
{
	int C;
	cin >> C;
	int n, m;
	int temp_a, temp_b;
	bool taken[10];
	for (int i = 0; i < 10; i++)
	{
		taken[i] = false;
	}
	for (int i = 0; i < C; i++)
	{
		cin >> n >> m;
		initFriends(areFriends);
		for (int j = 0; j < m; j++)
		{
				cin >> temp_a >> temp_b;
				areFriends[temp_a][temp_b] = true;
		}
		cout << calc_result(taken,n);
	}

}