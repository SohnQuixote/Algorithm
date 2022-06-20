#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
/*
  새로운 게임 2
  크기 N*N체스판 진행
  말 위에 다른 말 가능
  체스판 각 칸 흰색 빨간색 파란색
  턴 한번 1번~k번 순서대로 이동
  위에 있는 말 같이 이동(말 수를 하나의 차원 별도로 하여 순서 없으면 -1(1~k))
  말 4개 쌓이면 게임 종료
  흰색 위에 있는 말도 같이 이동
  빨간색 이동 후 순서 반대로 바뀜
  파란색 이동 방향 반대로 한칸
  벗어나는 경우 방향 반대로 바꾼 뒤 한칸
`  0-흰 1-빨 2-파
*/
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
const int MAX = 12;
int board[MAX][MAX] ={0,};
//해당 보드의 색깔 - 더이상 변하지 않음
vector<vector<vector<int>>> grid(MAX,vector<vector<int>>(MAX,vector<int>(11,0)));
//보드 위에 있는 말들
vector<tuple<int,int,int>> dir(11,make_tuple(0,0,0));
//해당 말의 방향및 좌표
vector<vector<int>>height(MAX,vector<int>(MAX,0));
//얼마나 높게 되어 있는지
int N;
int chg_dir(int a)
{
  if(a==1)
    return 2;
  else if(a==2)
    return 1;
  else if(a==3)
    return 4;
  else
    return 3;
}
void print_grid(int h)
{
  for(int he =1;he<=h;he++)
    {
      cout<<endl<<he<<endl;
      for(int i=0;i<N;i++)
        {
          for(int j=0;j<N;j++)
            {
              cout<<grid[i][j][he]<<' ';
            }
          cout<<endl;
        }
    }
  
}
bool calc_range(int x, int y)
{
  if(x>=0&&x<N &&y>=0 && y<N)
    return true;
  return false;
}
int play(int k)
{
  int result = 0;
  int max_height= 1;
  while(result<=1000)
    {
      result++;
      for(int i=1;i<=k;i++)
        {
          //1번부터 k번 이동
          queue<tuple<int,int,int,int,int>>q;          
          //행좌표 열좌표 상대높이 말의숫자
          int x = get<0>(dir[i]);
          int y = get<1>(dir[i]);
          int d = get<2>(dir[i]);
          int cur_h = 0;
          int mov_x = x + dx[d];
          int mov_y = y+ dy[d];
          for(int h=1;h<=height[x][y];h++)
            {
              if(grid[x][y][h] == i)
              {
                cur_h = h;
                //이동하려는 말 높이
              }
            }
          
              if(calc_range(mov_x,mov_y) && board[mov_x][mov_y] == 0)
              {
                //흰
                for(int h = cur_h;h<=height[x][y];h++)
                {
                  q.push(make_tuple(mov_x,mov_y,h-cur_h,grid[x][y][h],get<2>(dir[grid[x][y][h]])));     
                }
                for(int h=cur_h;h<=height[x][y];h++)
                  grid[x][y][h] = 0;
                
                while(!q.empty())
                  {
                    tuple<int,int,int,int,int>pos = q.front();
                    q.pop();
                    
                    int mov_x = get<0>(pos);
                    int mov_y = get<1>(pos);
                    int h = get<2>(pos);
                    int c = get<3>(pos);
                    int orig_d = get<4>(pos);
                    height[x][y] -=1;
                    //grid[x][y][cur_h+h] = 0;

                    height[mov_x][mov_y] +=1;
                    grid[mov_x][mov_y][height[mov_x][mov_y]] = c;
                    
                    dir[c] = make_tuple(mov_x,mov_y,orig_d);
                  }
                max_height = height[mov_x][mov_y];
              }



                
              else if(calc_range(mov_x,mov_y) && board[mov_x][mov_y] == 1)
              {
                //빨
                for(int h = height[x][y];h>=cur_h;h--)
                {
                  q.push(make_tuple(mov_x,mov_y,h-height[x][y],grid[x][y][h],get<2>(dir[grid[x][y][h]])));     
                }
                for(int h=cur_h;h<=height[x][y];h++)
                  grid[x][y][h] = 0;
                max_height = height[x][y];
                while(!q.empty())
                  {
                    tuple<int,int,int,int,int>pos = q.front();
                    q.pop();
                    
                    int mov_x = get<0>(pos);
                    int mov_y = get<1>(pos);
                    int h = get<2>(pos);
                    int c = get<3>(pos);
                    int orig_d = get<4>(pos);
                    height[x][y] -=1;
                    //grid[x][y][max_height -h] = 0;

                    height[mov_x][mov_y] +=1;
                    grid[mov_x][mov_y][height[mov_x][mov_y]] = c;
                    dir[c] = make_tuple(mov_x,mov_y,orig_d);
                  }
                max_height = height[mov_x][mov_y];
              }


                
              else if((calc_range(mov_x,mov_y) &&board[mov_x][mov_y] == 2)||!calc_range(mov_x,mov_y))
              {
                //파
                d = chg_dir(d);
                mov_x = x+dx[d];
                mov_y = y+dy[d];
                //dir[i] = make_tuple(mov_x,mov_y,d);
                if(calc_range(mov_x,mov_y))
                {
                  if(board[mov_x][mov_y] == 0)
                  {
                //흰
                  for(int h = cur_h;h<=height[x][y];h++)
                    q.push(make_tuple(mov_x,mov_y,h-cur_h,grid[x][y][h],get<2>(dir[grid[x][y][h]])));
                    
                for(int h=cur_h;h<=height[x][y];h++)
                  grid[x][y][h] = 0;
                
                while(!q.empty())
                  {
                    tuple<int,int,int,int,int>pos = q.front();
                    q.pop();
                    
                    int mov_x = get<0>(pos);
                    int mov_y = get<1>(pos);
                    int h = get<2>(pos);
                    int c = get<3>(pos);
                    int orig_d = get<4>(pos);
                    height[x][y] -=1;
                    //grid[x][y][cur_h+h] = 0;

                    height[mov_x][mov_y] +=1;
                    grid[mov_x][mov_y][height[mov_x][mov_y]] = c;
                    if(c==i)
                      dir[c] = make_tuple(mov_x,mov_y,d);
                    else
                      dir[c] = make_tuple(mov_x,mov_y,orig_d);
                  }
                max_height = height[mov_x][mov_y];
              }
              else if(board[mov_x][mov_y] == 1)
              {
                for(int h = height[x][y];h>=cur_h;h--)
                  q.push(make_tuple(mov_x,mov_y,h-height[x][y],grid[x][y][h],get<2>(dir[grid[x][y][h]])));
                
                for(int h=cur_h;h<=height[x][y];h++)
                  grid[x][y][h] = 0;
                
                max_height = height[x][y];
                while(!q.empty())
                  {
                    tuple<int,int,int,int,int>pos = q.front();
                    q.pop();
                    
                    int mov_x = get<0>(pos);
                    int mov_y = get<1>(pos);
                    int h = get<2>(pos);
                    int c = get<3>(pos);
                    int orig_d = get<4>(pos);
                    height[x][y] -=1;
                    //grid[x][y][max_height -h] = 0;

                    height[mov_x][mov_y] +=1;
                    grid[mov_x][mov_y][height[mov_x][mov_y]] = c;
                    
                    if(c==i)
                      dir[c] = make_tuple(mov_x,mov_y,d);
                    else
                      dir[c] = make_tuple(mov_x,mov_y,orig_d);
                  }
                max_height = height[mov_x][mov_y];
              }  
              }
            
          }
            
    
    if(max_height>=4)
      return result;
    }
      //print_grid(max_height);
  }
  if(result == 1001)
    return -1;
  return result;
}
int main() {
  int K;
  cin>>N>>K;
  for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)   
        cin>>board[i][j];
  for(int i=1;i<=K;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      a--;
      b--;
      grid[a][b][1] = i;
      height[a][b] = 1;
      dir[i] = make_tuple(a,b,c);
    }
  //print_grid(1);
  cout<<play(K)<<endl;
}