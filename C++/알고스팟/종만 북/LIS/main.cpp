#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
  LIS
  0개 이상의 숫자를 지우면 부분수열이 나옴
  이러한 부분 수열인데 순증가하는 증가 부분수열
  가장 긴것의 길이를 계산
  뒤에서부터 봐보자
  뒤에서 부터 보면서 증가수열의 최대길이를 갱신하기
  LIS[i] - 현재까지의 증가수열의 길이
  동적 계획에서 할 것
*/
int C;
int N;
int arr[500];
int LIS[500] = { 0, };
int main() {
	cin >> C;
	for (int tc = 0; tc < C; tc++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			LIS[i] = 1;
		}
		//LIS[0] =1;
		int result = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (arr[j] < arr[i])
				{
					LIS[i] = max(LIS[i], LIS[j] + 1);
				}

			}
			result = max(result, LIS[i]);

		}
		cout << result << '\n';
		//cout<<LIS[0]<<'\n';

	}


}