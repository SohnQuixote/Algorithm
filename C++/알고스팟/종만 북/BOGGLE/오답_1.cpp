#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
  BOGGLE

*/
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
char boggle[5][5];
unordered_map<string, int>how_many;
bool calc_range(int x, int y)
{
	if (x >= 0 && x < 5 && y >= 0 && y < 5)
		return true;
	return false;
}
int c;
//단어는 최대 10글자
int visited[5][5] = { 0, };
void dfs(int dpth, string chk, int x, int y)
{
	how_many[chk] = 1;
	if (dpth == 10)
		return;
	for (int d = 0; d < 8; d++)
	{
		int mov_x = x + dx[d];
		int mov_y = y + dy[d];
		if (calc_range(mov_x, mov_y) && !visited[mov_x][mov_y])
		{
			visited[mov_x][mov_y] = 1;
			dfs(dpth + 1, chk + boggle[mov_x][mov_y], mov_x, mov_y);
			visited[mov_x][mov_y] = 0;


		}


	}




}



int main() {
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		vector<string>q;
		for (int r = 0; r < 5; r++)
		{
			string tmp;
			cin >> tmp;
			for (int c = 0; c < 5; c++)
			{
				boggle[r][c] = tmp[c];
				//visited[r][c] = 0;
			}
		}
		how_many.clear();
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				for (int vr = 0; vr < 5; vr++)
					for (int vc = 0; vc < 5; vc++)
						visited[vr][vc] = 0;
				visited[r][c] = 1;
				string tmp = "";
				tmp += boggle[r][c];
				dfs(1, tmp, r, c);



			}



		}
		int q_l;
		cin >> q_l;
		for (int idx = 0; idx < q_l; idx++)
		{
			string tmp;
			cin >> tmp;
			if (how_many[tmp])
			{
				cout << tmp << " YES\n";
			}
			else
			{
				cout << tmp << " NO\n";
			}


		}

	}
}