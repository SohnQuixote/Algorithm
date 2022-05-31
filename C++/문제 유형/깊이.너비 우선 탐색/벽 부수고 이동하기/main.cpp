#include <iostream>
#include <string>
#include <queue>
using namespace std;
/*
  벽 부수고 이동하기
  (0,0)에서 (N-1,M-1)까지 이동
  벽은 한개까지 부술 수 있음
  0 이동 할 수 있는 곳 1 이동할 수 없는 벽
  벽 한번씩 다 부숴볼 수 밖에 없음
  벽 부순 정보 갖고 있어야함
*/
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool Visit[1000][1000][2];
//배열에 직접 쓰고 지우지 않아도 큐로 해결하면 시간 제한 해결
//반복문이 많으면 시간초과됨
int calc(int **map,int N,int M)
{
  queue<pair<pair<int,int>,pair<int,int>>>Q;
  Q.push(make_pair(make_pair(0,0),make_pair(0,1)));
  int result = 9876543;
  Visit[0][0][0] = true;
  while(!Q.empty())
    {
      int x = Q.front().first.first;
      int y = Q.front().first.second;
      int B = Q.front().second.first;
      int cnt = Q.front().second.second;
      Q.pop();
        if (x == N - 1 && y == M - 1)
        {
            return cnt;
        }
      for(int i=0;i<4;i++)
        {
          int nx = x+dx[i];
          int ny = y+dy[i];
          if(nx>=0 &&nx<=N-1 && ny>=0 && ny<= M-1)
          {
            if(map[nx][ny] == 1 && B ==0)
            {
              Visit[nx][ny][B+1] = true;
              Q.push(make_pair(make_pair(nx, ny), make_pair(B + 1, cnt + 1)));

            }
                else if (map[nx][ny] == 0 && Visit[nx][ny][B] == false)
                {
                    Visit[nx][ny][B] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(B, cnt + 1)));
                }


            
          }
        }
    }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  int N,M;
  char ch;
  cin>>N>>M;
  int **map = new int*[N];
  for(int i=0;i<N;i++)
    map[i] = new int[M];
  for(int i=0;i<N;i++)
    {
      string Inp;
      cin>>Inp;
      for(int j=0;j<M;j++)
        {
        map[i][j] = Inp[j] - '0';
        //scanf("%1d" , &map[i][j]);
        }
    }
  cout<<calc(map,N,M)<<endl;
}