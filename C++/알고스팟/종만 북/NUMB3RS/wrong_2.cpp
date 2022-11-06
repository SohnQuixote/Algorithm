#include <iostream>
#include <cstring>
using namespace std;
/*
  numb3rs
  두니발 박사 검문을 피해 산길로만 이동
  두니발 박사 교도소 탈출 당일 인접한 마을 하나로 으신
  매일 인접한 마을로 움직여 은신
  d일후에 두니발 교수 각 마을에 있을 확률을 계산
  0일 -> 교도소 인근 마을로
  함수(날짜,마을)

*/
int c;
int n, d, p;
int town[51][51];
int connected[51];
double cache[101][51];

double escape(int day, int t)
{
	//현재 day에서 출발지 town에서 갈수 있는 모든 경우의 수
	//이전거에서 현재 확률 곱해서 넣기?
	double &ret = cache[day][t];
	if (ret!=-1) return ret;
	//연결된 지역으로 역추적
	ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (town[i][t])
		{
			ret += ((double)(1) / (double)(connected[i])) * escape(day - 1, i);

		}



	}
	return ret;


}





int main() {
	cin >> c;
	for (int tc = 0; tc < c; tc++)
	{
		cin >> n >> d >> p;
		for(int i=0;i<101;i++)
        for(int j=0;j<51;j++)
          cache[i][j] = -1;
    //memset(cache, -1, sizeof(cache));
		memset(connected, 0, sizeof(connected));
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				cin >> town[r][c];
				if (town[r][c])
					connected[r]++;
			}


		}
		//첫번째 교도소에서 확률 초기화?
		for (int s = 0; s < n; s++)
		{
			if (town[p][s])
			{
				cache[0][s] = (double)(1) /(double)( connected[p]);
			}
      else
      {
        cache[0][s] = 0;
      }


		}
		for (int s = 0; s < n; s++)
				escape(d - 1, s);
		int t;
		cin >> t;
		for (int s = 0; s < t; s++)
		{
			int num;
			cin >> num;
			printf("%.7f ", cache[d - 1][num]);

		}
		printf("\n");


	}
}