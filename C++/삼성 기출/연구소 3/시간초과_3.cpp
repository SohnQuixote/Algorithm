#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
const int INF = 987654321;
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
/*
  일단 모든 바이러스에서 M개 선택은 해야함
  전역변수 사용하여 크면 안함
  동적계획 사용
  연구소 3
  바이러스 M개 활성상태로 변경하려 함
  연구소 N*N 정사각형
  모든 바이러스 빈칸에 퍼뜨리는 최소 시간
*/
int healthy_g = 0;
bool calc_range(int x,int y,vector<vector<int>> lab)
{
  if(x>=0 && x<N && y>=0 && y<N && lab[x][y] !=-1)
    return true;
  return false;
}
void print_lab(vector<vector<int>> lab)
{
  cout<<endl<<"printing::"<<endl;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<lab[i][j]<<' ';
        }
      cout<<endl;
    }
}
int chk_good(vector<vector<int>> lab)
{
  int result = 0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(lab[i][j] == INF)
            return INF;
        }
    }
  return result;
}
int infest_all(vector<vector<int>> lab,queue<pair<int,int>>&q,vector<vector<int>>t)
{
  int result = INF;
  int infect_g = 0;
  int taken_time = 0;
  while(!q.empty())
    {
      pair<int,int> pos = q.front();
      q.pop();
      int x = pos.first;
      int y = pos.second;
      for(int d=0;d<4;d++)
        {
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y,lab))
          {
            if(t[mov_x][mov_y] ==-1)
            {
              t[mov_x][mov_y] = t[x][y] +1;
              if(lab[mov_x][mov_y] == INF)
              {
                infect_g++;
                taken_time = t[mov_x][mov_y];
              }
              q.push(make_pair(mov_x,mov_y));  
            }
            
          }
        }
    }
  if(infect_g == healthy_g)
    return taken_time;
  return result;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  
  cin>>N>>M;
  vector<vector<int>> lab(50,vector<int>(50,0));
  queue<pair<int,int>>q;
  vector<pair<int,int>>viruses(10,make_pair(0,0));
  int v_num = 0;
  for(int i=0;i<N;i++)
    {
    for(int j=0;j<N;j++)
      {
        int tmp;
        cin>>tmp;
        if(tmp == 1)
          lab[i][j] = -1;
        else if(tmp == 2)
        {
          lab[i][j] = 0;
          viruses[v_num] = make_pair(i,j);
          v_num++;
        }
        else
        {
          lab[i][j] = INF;
          healthy_g++;
        }
      }
    }
  //print_lab(lab);
  vector<int>comb(v_num,0);
  for(int i=0;i<M;i++)
    {
      comb[i] = 1;
    }
  sort(comb.begin(),comb.end());
  int ans = INF;
  do{
    vector<vector<int>>t(50,vector<int>(50,-1));
    for(int i=0;i<v_num;i++)
      {
        if(comb[i])
        {
          q.push(viruses[i]);
          t[viruses[i].first][viruses[i].second] = 0;
        }
      }
     ans = min(ans,infest_all(lab,q,t));
    }while(next_permutation(comb.begin(),comb.end()));
  if(ans == INF)
    cout<<-1<<endl;
  else
    cout<<ans<<endl;
    //INF없으면 격자에서 최댓값이 걸린 시간의 수
    //v_num개 중 m개 선택
    //동적계획 활용하여 중복계산 방지
    //모든 경우 해봐도 INF나오면 -1 출력
  
}