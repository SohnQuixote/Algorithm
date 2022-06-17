#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
  연구소 3
  재귀조합 사용
  dfs + bfs
*/
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N,M;
int healthy_g = 0;
int v_num =0;
const int INF = 987654321;
int answer = INF;
const int MAX = 50;
vector<vector<int>> lab(MAX,vector<int>(MAX,0));
vector<pair<int,int>>viruses(10,make_pair(0,0));
vector<vector<bool>>infected(MAX,vector<bool>(MAX,false));
bool calc_range(int x,int y)
{
  if(x>=0 && x<N && y>=0 && y<N && lab[x][y] != -1)
    return true;
  return false;
}
int bfs(queue<pair<int,int>>q,vector<vector<int>> taken_time)
{
  int infected_g= 0;
  int result = 0;
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
          if(calc_range(mov_x,mov_y))
          {
            if(taken_time[mov_x][mov_y] == -1|| taken_time[mov_x][mov_y] > taken_time[x][y] +1)
            {
              taken_time[mov_x][mov_y] = taken_time[x][y] +1;
              q.push(make_pair(mov_x,mov_y));
            if(lab[mov_x][mov_y] == 0)
            {
              infected_g++;
              result = max(result,taken_time[mov_x][mov_y]);
            }
            }

            
            
          }
        }
      
    }
  if(infected_g == healthy_g)
    return result;
  else
    return INF;
}
void dfs(vector<bool>selected,int idx,int cnt)
{
  if(cnt == M)
  {
    queue<pair<int,int>> q;
    vector<vector<int>>taken_time(MAX,vector<int>(MAX,-1));
    for(int i=0;i<v_num;i++)
      {
        if(selected[i])
        {
          q.push(viruses[i]);
          taken_time[viruses[i].first][viruses[i].second] = 0;
        }
        
      }
    answer = min(answer,bfs(q,taken_time));
    return;
  }
  for(int i=idx;i<v_num;i++)
    {
      selected[i] = true;
      dfs(selected,i+1,cnt+1);
      selected[i] = false;
    }
}
int main() {
  cin>>N>>M;
  for(int i=0;i<N;i++)
    {
    for(int j=0;j<N;j++)
      {
        cin>>lab[i][j];
        if(lab[i][j] == 0)
        {
          healthy_g++;
        }
        else if(lab[i][j]== 1)
        {
          lab[i][j] = -1;
          
        }
        else
        {
          viruses[v_num] = make_pair(i,j);
          v_num++;
          infected[i][j] = true;
        }
      }
      
    }
  vector<bool>selected(v_num,false);
  dfs(selected,0,0);
  if(answer == INF)
    cout<<-1<<endl;
  else
    cout<<answer<<endl;
  //v_num개에서 M개 선택
  
}