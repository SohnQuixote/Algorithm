#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
/*
  인구 이동
  N*N크기 땅
  원소 내용 - 인구의 수
  나라 - 1*1
  인구차이 L명 이상 R명 이하 - 국경선 염
  다 열리면 인구이동 시작
  인접한 칸을 통해서만 이동 - 연합
  연합 각칸 인구수 - 연합 인구수/연합 칸 개수
  큐 사용해서 BFS -> 연합들 벡터로 완성
  거리 계산 - 중복안하기 위해서 bool 필요 -> 해당 거리를 하나씩 보고 연합 뭉치기 -> 연합끼리 계산해서 거리 업데이트 
  갈 수 있을 때만 BFS - 벡터에 저장
  모두다 들를때까지 시행
*/
const int MAX =  51;
vector<vector<int>> map(MAX,vector <int>(MAX,0)); //0 과 짝수 나라 사이에 있는 좌표 - 나라사이 거리
//stack<tuple<int,int,int>> unions[2500];//갖고 있는 인구 +좌표 연합 생성 됐으면 임시로 저장 자료구조
bool need_to_chk[51][51];
bool visited[51][51][51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
stack<tuple<int,int,int>>s; //거리 누적 + 좌표
bool chk_boundary(int a,int N)
{
  //0과 N-1 사이 쳌
  if(a>=0 && a<N)
    return true;
  return false;
}
int calc(int x,int y,int L,int R,int N)
{
  //여는 시작지점
  int result =0;
  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  s.push(make_tuple(map[x][y],x,y));
  while(!q.empty())
    {
      x = q.front().first;
      y = q.front().second;
      q.pop();
      need_to_chk[x][y] = true;
      for(int i=0;i<4;i++)
        {
          int mov_x = x+dx[i];
          int mov_y = y+dy[i];
          if(chk_boundary(mov_x,N) && chk_boundary(mov_y,N) && visited[x][y][mov_x][mov_y] == false)
          {
            visited[x][y][mov_x][mov_y] = true;
            visited[mov_x][mov_y][x][y] = true;
            int diff = abs(map[x][y] - map[mov_x][mov_y]);
            if(diff>=L && diff<=R)
            {
              q.push(make_pair(mov_x,mov_y)); 
              int accum_dist = get<0>(s.top());
              accum_dist += map[mov_x][mov_y];
              s.push(make_tuple(accum_dist,mov_x,mov_y));
            }
            
          }
          
        }

      
    }
  if(s.size() == 1)
  {
    return 0;
  }
  else
  {
    int accum_dist = get<0>(s.top());
    int size = s.size();
    while(!s.empty())
      {
        int x = get<1>(s.top());
        int y =get<2>(s.top());
        s.pop();
        map[x][y] = accum_dist/size;
        
      }
    result =1;
  }
  return result;
}
int main() {
  int N,L,R;
  cin>>N>>L>>R;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cin>>map[(i)][(j)];
        }
    }
  int flag = 0;
  int result =0;
  do{
    for(int i=0;i<MAX;i++)
      for(int j=0;j<MAX;j++)
        for(int k=0;k<MAX;k++)
          for(int p=0;p<MAX;p++)
            visited[i][j][k][p] = false;
    for(int i=0;i<MAX;i++)
      for(int j=0;j<MAX;j++)
        need_to_chk[i][j] = false;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(!need_to_chk[i][j])
            flag = max(flag,calc(i,j,L,R,N));
          
        }

      
    }
    if(flag == 0 && result ==0)
    {
      cout<<0<<endl;
      return 0;
    }
    if(flag)
      result+=1;
  }while(flag);
  cout<<result<<endl;
}