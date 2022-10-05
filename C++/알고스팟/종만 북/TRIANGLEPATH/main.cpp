#include <iostream>
#include <cstring>
using namespace std;
/*
  TRIANGLE PATH
  모든 경로중 포함된 숫자의 최대합
*/
int C;
int N;
int dx[2] = { 1,1 };
int dy[2] = { 0,1 };
int arr[100][100] = { 0, };
int cache[100][100] = { 0, };
int result = 0;
bool calc_range(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	return false;
}
void start(int x, int y)
{
	//모든 경로중 포함된 숫자의 최대합은 무조건 끝행
	if (result < cache[x][y])
		result = cache[x][y];
	for (int d = 0; d < 2; d++)
	{
		int mov_x = x + dx[d];
		int mov_y = y + dy[d];
		if (calc_range(mov_x, mov_y))
		{
			int moving = cache[x][y] + arr[mov_x][mov_y];
			if (moving > cache[mov_x][mov_y])
			{
				cache[mov_x][mov_y] = moving;
				start(mov_x, mov_y);
			}

		}

	}


}
int main() {
	cin >> C;
	for (int tc = 0; tc < C; tc++)
	{
		cin >> N;
		result = 0;
		memset(cache, 0, sizeof(cache));
		for (int i = 0; i < N; i++)
		{
			for (int c = 0; c <= i; c++)
			{
				cin >> arr[i][c];
			}
		}
		cache[0][0] = arr[0][0];
		start(0, 0);
		//cout << cache[N - 1][N - 1] << '\n';
		cout << result << '\n';


	}
}