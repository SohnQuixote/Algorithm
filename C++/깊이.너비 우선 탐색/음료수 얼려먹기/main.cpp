#include <iostream>
#include <stack>
#include <vector>
#include <queue>
/*
  dfs 필요 자료구조 스택, (연결 정보 - 인접 행렬, 인접 리스트), 방문 정보
스택 빌때까지 탐색하는데 재귀함수로 호출하면 알아서 호출이 스택구조
vector<int> 사용
bfs 필요 자료구조 큐 , 연결정보, 방문정보
큐 빌때까지 탐색
음료수 얼려먹기
N,M -> N*M 얼음판
구멍 뚫려 있는 부분 0
그렇지 않은 부분 1
얼음판으로 만들 수 있는 아이스크림의 수
*/
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void dfs(int **map,int N,int M, int X,int Y)
{
  map[X][Y] = 1;
  for(int i=0;i<4;i++)
    {
      if((X+dx[i])>=0 && (X+dx[i])<=N-1 && (Y+dy[i])>=0 && (Y+dy[i])<=M-1)
      {
        if(map[X+dx[i]][Y+dy[i]] == 0)
        {
          dfs(map,N,M,X+dx[i],Y+dy[i]);
        }
      }
    }
}
int calc(int **map,int N,int M)
{
  int result = 0;
  for (int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        if(map[i][j] == 0)
        {
          dfs(map,N,M,i,j);
          result+=1;      
        }
    }

  
  return result;
}
int main() {
  int N,M;
  cin>>N>>M;
  int **map = new int*[N];
  for(int i=0;i<N;i++)
    {
      map[i] = new int[M];
    }
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        cin>>map[i][j];
    }
  cout<<calc(map,N,M)<<endl;
}