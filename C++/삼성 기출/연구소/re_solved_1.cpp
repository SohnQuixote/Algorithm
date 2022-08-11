#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
/*
  연구소 복습
  좀 더 효율적으로 풀어보자!!!
*/
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;
int max_surf = -987654321;
int dfsed[8][8] = {0,};
int grid[8][8] = {0,};
bool calc_range(int x, int y)
{
  if(x>=0 && x<n && y>=0 && y<m)
    return true;
  return false;
  
}
//DFS로 조합
void print_grid(int visited[8][8])
{
  for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
      {
        cout<<visited[i][j]<<' ';

        
      }
    cout<<endl;
      
    }

  
}
void bfs(int visited[8][8])
{
  //print_grid(visited);

  int tmp_visited[8][8] = {0,};
  for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
      tmp_visited[i][j] = visited[i][j];

      
    }
  
  queue<pair<int,int>>q;
  int infected[8][8] = {0,};
  for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
      {
        if(visited[i][j] == 2)
        {
          q.push({i,j});
          infected[i][j] = 1;
        }

        
      }


      
    }
  while(!q.empty())
    {
      int x, y;
      tie(x,y) = q.front();
      q.pop();
      for(int d=0;d<4;d++)
        {
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y) && tmp_visited[mov_x][mov_y] == 0 && infected[mov_x][mov_y] == 0)
          {
            infected[mov_x][mov_y] = 1;
            tmp_visited[mov_x][mov_y] = 2;
            q.push({mov_x,mov_y});
          }
          
        }


      
    }
    //print_grid(visited);
    int tmp_cnt = 0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(!tmp_visited[i][j])
          tmp_cnt++;

  if(tmp_cnt>max_surf)
    //print_grid(visited);
  max_surf= max(tmp_cnt,max_surf);  
}

/*
7 7
2 0 0 0 1 1 0
0 0 1 0 1 0 0
0 1 1 0 1 0 0
0 1 0 0 1 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
*/
void calc(int visited[8][8] ,int x, int y, int cnt)
{
  if(cnt == 3)
  {
    //print_grid(visited);
    //이때 BFS호출해야함
    bfs(visited);

    
    return;
  }
  for(int i=x;i<n;i++)
    {
        if(i>x)
        {
          y = 0;
        }
    for(int j=y;j<m;j++)
      {    
        if(!visited[i][j])
        {
          visited[i][j] = 1;
          //print_grid(visited);
          calc(visited,i,j+1,cnt+1);
          visited[i][j] = 0;
        }

        
      }



      
    }



  
}
//BFS로 모두 펼쳐나가보기
int main() {
  cin>>n>>m;
  int possible[8][8] = {0,};
  for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
      {
        cin>>grid[i][j];
        possible[i][j] = grid[i][j];
        //이미 배치했다는 뜻!
      }
    }
  //bfs(grid);
  calc(possible,0,0,0);
  cout<<max_surf<<endl;
}