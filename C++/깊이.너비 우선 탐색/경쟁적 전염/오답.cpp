#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
/*
  경쟁적 전염
  N*N 시험관
  바이러스 1~K
  매초 번호가 낮은 모든 바이러스 증식 - 상 하 좌 우
  S초 지난 후 (X,Y) 바이러스 종류 출력
  queue 사용해서 매초 좌표를 초기화  
  우선순위 큐 사용  
*/
struct cmp{
  bool operator()(tuple<int,int,int,int>a, tuple<int,int,int,int>b)
{
  if(get<3>(a)>get<3>(b))
    return true;
  else if(get<0>(a)>get<0>(b))
    return true;
  else
    return false;
}

};
const int MAX = 201;
int map[MAX][MAX] ={0,};
vector<pair<int,int>>viruses[1001];
priority_queue<tuple<int,int,int,int> , vector<tuple<int,int,int,int>> , cmp> q; //번호 좌표 시간
//queue<pair<int,int>> q; // - 걸린 시간, 바이러스 번호, 좌표
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
//바이러스 이동
void infection(int S,int N)
{
  //특정 바이러스 감염
  /*for(int i=0;i<viruses[V].size();i++)
    {
      q.push(make_pair(viruses[V][i].first,viruses[V][i].second));
      //좌표를 저장
    }*/
  while(!q.empty())
    {
      int v = get<0>(q.top());
      int x = get<1>(q.top());
      int y = get<2>(q.top());
      int t = get<3>(q.top());
      q.pop();
      if(t==S)
        continue;
      if(t != S)
        q.push(make_tuple(v,x,y,t+1));
      for(int i=0 ;i<4;i++)
        {
          int mov_x = x+dx[i];
          int mov_y = y+dy[i];
          
          if(mov_x >= 1 && mov_x <= N && mov_y >=1 && mov_y <=N && map[mov_x][mov_y] == 0 )
          {
            map[mov_x][mov_y] = v;
            q.push(make_tuple(v,mov_x,mov_y,t+1));
            //viruses[V].push_back(make_pair(mov_x,mov_y));
          }
        }
      
    }
  //한번만 전염 시키고 맘
  
}
int main() {
  int N,K;
  cin>>N>>K;
  int S,X,Y;
  for(int i=1;i<N+1;i++)
    {
      for(int j=1;j<N+1;j++)
        {
          int temp;
          cin>>temp;
          if(temp!=0)
          {
            q.push(make_tuple(temp,i,j,0));
            //viruses[temp].push_back(make_pair(i,j));      
            //바이러스 번호 -> 좌표
          }
          map[i][j] = temp;
        }
    }
  cin>>S>>X>>Y;
  infection(S,N);
  cout<<map[X][Y]<<endl;
  
  //sort(viruses.begin(),viruses.end());
  //바이러스 1번 부터 나옴
  
  /*for(int i=0;i<viruses.size();i++)
    {
      cout<<get<0>(viruses[i])<<' '<<get<1>(viruses[i])<<' '<<get<2>(viruses[i])<<endl;
    }*/
  
}