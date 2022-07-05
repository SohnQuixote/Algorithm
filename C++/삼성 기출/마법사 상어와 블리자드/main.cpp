#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
/*
  마법사 상어와 블리자드 
  상어- 한가운데 
  번호 -한가운데에서 반시계 회전하면서 됨
  구슬 -1,2,3
  구슬 번호 연속칸에 있으면 연속 구술
  블리자드 마법
1.
  d방향 거리 s이하 모든칸 구슬 파괴 ->빈칸 -> 벽 파괴 X
  파괴된후 숫자 낮은칸 빈칸이면 이동
2.
  구슬 폭발 -> 4개 이상 연속 구슬 폭발함 
  구슬 또 이동 - 다시 폭발
  폭발 안할 때까지 반복
3.
  구슬 변화
  같은 구슬-그룹 ->
  구슬 두개 변환 ->(그룹에 있는 구슬 개수, 그룹 이루고 있는 구슬 번호)
  블리자드 M번 수행
  ->(N*폭발한 N번 구슬 개수)
*/
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};
int score = 0;
int N,M;
vector<vector<int>>grid(50,vector<int>(50,0));
vector<pair<int,int>>coord_num(2500,make_pair(0,0));
int marble_num = 0;
//번호에 따른 좌표
bool calc_range(int x, int y)
{
  if(x>=1 && x<=N && y>=1 && y<=N)
    return true;
  return false;
  
}
void print_grid()
{
  cout<<"printing::"<<endl;
  for(int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
        {
          cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
}
void init_num(int N)
{
  int cent_x = (N+1)/2;
  int cent_y = (N+1)/2;
  int mov_x = cent_x;
  int mov_y = cent_y;
  int step = 1;
  int num = 1;
  while(mov_x != 0 && mov_y !=0)
    {
      int i=0;
      if(step%2 == 1)
      {
        i=0;
        while(i<step)
          {
            mov_y +=dy[3];
            i++;
            if(mov_x == 1 && mov_y == 0)
            {
              return;
            }
            coord_num[num] = make_pair(mov_x,mov_y);
            num++;
          }
        i=0;
        while(i<step)
          {
            mov_x += dx[2];
            i++;
            coord_num[num] = make_pair(mov_x,mov_y);
            num++;
          }

      
      }
      else
      {
        i=0;
        while(i<step)
          {
            mov_y +=dy[4];
            i++;
            coord_num[num] = make_pair(mov_x,mov_y);
            num++;
            
            
          }
        i=0;
        while(i<step)
          {
            mov_x+=dx[1];
            i++;
            coord_num[num] = make_pair(mov_x,mov_y);
            num++;
            
          }
        
      }
      step++;
    }
}
void move_marbles()
{
  //이동하는거에서 시간초과 뜨는거 같음
  vector<int>putting_marbles;
  for(int i=1;i<N*N;i++)
    {
      int x = coord_num[i].first;
      int y = coord_num[i].second;
      if(grid[x][y] != 0)
      {
        putting_marbles.push_back(grid[x][y]);
        grid[x][y] = 0;
      }
    }
  int num = 1;
  for(int i=0;i<putting_marbles.size();i++)
    {
      int x = coord_num[num].first;
      int y = coord_num[num].second;
      grid[x][y] = putting_marbles[i];
      num++;
    }
}
tuple<int,int,int> dfs_group(int start, int marble_num ,vector<bool>&visited)
{
  int group_num = 0;
  queue<int>q;
  q.push(start);
  while(!q.empty())
    {
      int pos = q.front();
      q.pop();
      visited[pos] = true;
      group_num++;
      int mov = pos+1;
      if(visited[mov] == false)
      {
        int mov_x = coord_num[mov].first;
        int mov_y = coord_num[mov].second;
        if(grid[mov_x][mov_y] == marble_num)
          q.push(mov);
        
      }

      
    }
  return make_tuple(start,group_num,marble_num);
}
vector<tuple<int,int,int>> grouping_marbles(int &marbles)
{
  vector<tuple<int,int,int>>result;
  //시작 번호, 그룹의 수, 구슬 번호
  int max_group_num = N*N;
  vector<bool>visited(max_group_num,false);
  for(int i=1;i< max_group_num;i++)
    {
      int x = coord_num[i].first;
      int y = coord_num[i].second;
      if(grid[x][y] > 0 && !visited[i])
      {
        result.push_back(dfs_group(i,grid[x][y], visited));
        marbles = max(marbles,get<1>(result.back()));
        
      }
    }
  return result;
}
void scoring(vector<tuple<int,int,int>> g)
{
  for(int i=0;i<g.size();i++)
    {
      int start = get<0>(g[i]);
      int g_num = get<1>(g[i]);
      int m_num = get<2>(g[i]);
      if(g_num>=4)
      {
        int i=0;
        while(i<g_num)
          {
            int x = coord_num[start].first;
            int y = coord_num[start].second;
            grid[x][y] = 0;
            i++;
            start+=1;
            
            
            
          }
        score+= g_num * m_num;
        
      }

      
    }
}
void cast_blizzard(pair<int,int>cmd)
{
  vector<vector<int>>chged(50,vector<int>(50,0));
  vector<tuple<int,int,int>> groups;
  //1.구슬 파괴
  int dir = cmd.first;
  int speed= cmd.second;
  int i=0;
  int cast_x = (N+1)/2;
  int cast_y = (N+1)/2;
  int mov_x = cast_x;
  int mov_y = cast_y;
  int popped_marbles= 0;
  while(i<speed)
    {
      mov_x += dx[dir];
      mov_y += dy[dir];
      if(calc_range(mov_x,mov_y))
      {
        grid[mov_x][mov_y] =0;
      }
      i++;
      
    }
  //2.구슬 채우기
  //print_grid();
  move_marbles();
  //print_grid();
  //그룹 찾기
  int marbles = 0;
  groups = grouping_marbles(marbles);
  while(marbles >=4)
    {

      marbles = 0;
      groups = grouping_marbles(marbles);
      scoring(groups);
      move_marbles();
      //print_grid();
      
    }
  //3.구슬폭발 -이동 반복
  
  //그룹 정보 -> 시작번호 - 그룹 수 - 구슬번호
  
  //4.위단계에서 그룹정보 계속 저장 -> 그룹수가 3개이하면 브레이크
  
  //5.구슬 변화
  int num = 1;
  for(int i=0;i<groups.size() && num < N *N;i++)
    {
      int f = get<1>(groups[i]);
      int s = get<2>(groups[i]);
      int f_x = coord_num[num].first;
      int f_y = coord_num[num].second;
      int s_x = coord_num[num+1].first;
      int s_y = coord_num[num+1].second;
      chged[f_x][f_y] = f;
      chged[s_x][s_y] = s;
      num+=2;
      
    }
  grid = chged;
  //print_grid();
  
}
int main() {
  cin>>N>>M;
  init_num(N);
  for(int i =1;i<=N;i++)
    {
    for(int j=1;j<=N;j++)
      {
        cin>>grid[i][j];
      }
    
    }
  for(int i=0;i<M;i++)
    {
      int a,b;
      cin>>a>>b;
      cast_blizzard(make_pair(a,b));
    }
  cout<<score<<endl;
}