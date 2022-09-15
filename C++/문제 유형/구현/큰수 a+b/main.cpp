#include <iostream>
#include <string>
#include <vector>

#include <unordered_map>

#include <queue>

#include <algorithm>
using namespace std;
/*
10000
*/
int a[100005] = { 0, };
int b[100005] = { 0, };
int result[100005] = { 0, };
int main() {
	for (int i = 0; i < 100000; i++)
	{
		a[i] = -1;
		b[i] = -1;
	}
	string A_num, B_num;
	cin >> A_num >> B_num;
	//뒤집어야함
	reverse(A_num.begin(), A_num.end());
	reverse(B_num.begin(), B_num.end());
	//역순으로 넣기
	for (int i = 0; i < A_num.size(); i++)
	{
		a[i] = A_num[i] - '0';
	}
	for (int i = 0; i < B_num.size(); i++)
	{
		b[i] = B_num[i] -'0';
	}
  int size = A_num.size();
  if(size<B_num.size()) size = B_num.size();
	for (int i = 0; i < size; i++)
	{
		if (a[i] != -1 && b[i] != -1)
		{
			//두개다 더하기
			int plus = a[i] + b[i] + result[i];
			result[i] = plus % 10;
			result[i + 1] += plus / 10;
		}
		else if (a[i] == -1 && b[i] == -1)
		{

		}
		else
		{
			int pp = a[i];
			if (pp == -1) pp = b[i];
			int plus = pp + result[i];
			result[i] = plus % 10;
			result[i + 1] += plus / 10;

		}


	}
	int start_idx;
	for (int i = 100000; i >= 0 && result[i] == 0; i--)
	{
		start_idx = i;
	}
	start_idx--;
	for (int i = start_idx; i >= 0; i--)
	{
		cout << result[i];
	}
}