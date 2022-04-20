#include <iostream>
#include <vector>
using namespace std;
/*
유기농 배추
테스트 케이스 T
입력 M,N, 배추수 K
vector<>로 하기
2차원 배열이 더 쉬워보임
dfs로 해결
*/
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void dfs(int **map,int x,int y,int N,int M)
{
  map[x][y] = 0;
  for (int i=0;i<4;i++)
    {
      int tmp_x = x+dx[i];
      int tmp_y = y+dy[i];
      if(tmp_x>=0 && tmp_x<= N-1 && tmp_y >=0 && tmp_y <= M-1)
      {
        if(map[tmp_x][tmp_y] == 1)
        {
          dfs(map,tmp_x,tmp_y,N,M);
        }
      }
    }
}
int calc(int **map,int N,int M)
{
  int result = 0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          if(map[i][j] == 1)
          {
            dfs(map,i,j,N,M);
            result+=1;
          }
        }
    }
  return result;
}
int main() {
  int T,N,M;
  int K;
  int **map;
  int x,y;
  cin>>T;
  int *results = new int[T];
  for(int i=0;i<T;i++)
    {
      cin>>M>>N;
      cin>>K;
      map = new int*[N];
      for(int i=0;i<N;i++)
        {
          map[i] = new int[M];
        }
      for(int i=0;i<K;i++)
        {
          cin>>x>>y;
          map[y][x] = 1;
        }
      results[i] = calc(map,N,M);
    for (int i = 0; i < N; i++)
		  delete [] map[i];
	  delete [] map;
    }
  for(int i=0;i<T;i++)
    {
      cout<<results[i]<<endl;
    }
}