#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
const int INF = 987654321;
vector<bool>chose(10,false);
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
vector<pair<int,int>>viruses(10,make_pair(0,0));
vector<vector<int>> laba(50,vector<int>(50,0));
int v_num = 0;
int answer = INF;
/*
  일단 모든 바이러스에서 M개 선택은 해야함
  전역변수 사용하여 크면 안함
  동적계획 사용
  연구소 3
  바이러스 M개 활성상태로 변경하려 함
  연구소 N*N 정사각형
  모든 바이러스 빈칸에 퍼뜨리는 최소 시간
*/
vector<vector<bool>>v_exist(50,vector<bool>(50,false));
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
          else if(!v_exist[i][j])
            result = max(result,lab[i][j]);
          
        }
      
    }
  return result;
}
void infest_all(vector<vector<int>> lab,queue<pair<int,int>>q,vector<vector<bool>>active)
{
  //queue<pair<int,int>>c_q;
  while(!q.empty())
    {
      pair<int,int>pos = q.front();
      q.pop();
      int x = pos.first;
      int y = pos.second;
      for(int d= 0;d<4;d++)
        {
          int mov_x = x+ dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y,lab))
          {
            if(lab[mov_x][mov_y] == 0 && !active[mov_x][mov_y])
            {
              lab[mov_x][mov_y] = lab[x][y]+1;
              q.push(make_pair(mov_x,mov_y));
            }
            else if(lab[mov_x][mov_y] >(lab[x][y]+1)){
              lab[mov_x][mov_y] =lab[x][y] +1;
              q.push(make_pair(mov_x,mov_y));
            }
            
          }
        }
      
    }
  answer = min(answer,chk_good(lab));
}
void C(int index, int depth)
{
    if (depth == M)
    {
      //cout<<endl;
      queue<pair<int,int>>q;
      vector<vector<bool>> active(50,vector<bool>(50,false));
      for(int i=0;i<v_num;i++)
      {
        if(chose[i])
        {
          q.push(viruses[i]);
          active[q.back().first][q.back().second] = true;
          //cout<<q.back().first<<' '<<q.back().second<<endl;
        }
      }
      infest_all(laba,q,active);
      return;
    }
    else
    {
        for(int i = index; i < viruses.size(); i++)
        {
            if(chose[i] == true) continue;
            chose[i] = true;
            C(i + 1, depth + 1);
            chose[i] = false;
        }
    }
}


int main() {
  cin>>N>>M;
  for(int i=0;i<N;i++)
    {
    for(int j=0;j<N;j++)
      {
        int tmp;
        cin>>tmp;
        if(tmp == 1)
          laba[i][j] = -1;
        else if(tmp == 2)
        {
          laba[i][j] = 0;
          v_exist[i][j] = true;
          viruses[v_num] = make_pair(i,j);
          v_num++;
        }
        else
          laba[i][j] = INF;
      }
    }
  C(0,0);
  if(answer == INF)
    cout<<-1<<endl;
  else
    cout<<answer<<endl;
  
}