#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
/*
  상어 중학교
  N*N 격자
  블록 - 검은 블록,무지개, 일반-> M가지 색상
 검은 - -1
  무지개- 0
  일반 - M이하 자연수
  블록 그룹 - 연결된 블록 집합
  일반 블록색 전부 같음 - 검은색 포함 X 
  무지개 상관 없음
  기준 블록 - 무지개 블록 아니면서 행/열 가장 작은 블록
  오토 플레이 기능
  1. 가장 큰 블록 그룹 찾기 - 여러개 - 무지개 여러개 - 기준 행 가장 큰거 - 열 가장 큰거 -> dfs 사용 기준점도 찾아야함
  2. 블록 모두 제거
  - 블록수 제곱점 얻기
  3. 중력 작용
  4. 반시계 방향 회전
  5. 중력 작용   
  중력 - 검은색 제외 행의 밑으로 이동
  -2가 비어있는 것
*/
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N,M;
bool auto_flag=  true;
int score = 0;
vector<vector<int>> grid(20,vector<int>(20,0));
void print_grid()
{
  cout<<"printing::"<<endl;
  for(int i=0;i<N;i++)
    {
    for(int j=0;j<N;j++)
      {
        if(grid[i][j] == -2)
          cout<<"E ";
        else if(grid[i][j] == -1)
          cout<<"B ";
        else
          cout<<grid[i][j]<<' ';
        
      }
      cout<<endl;
    }
}
bool cmp(tuple<int,int,int,int,int> a , tuple<int,int,int,int,int>b)
{
  int a_one = get<0>(a);
  int b_one = get<0>(b);
  int a_two = get<1>(a);
  int b_two  =get<1>(b);
  int a_thr = get<2>(a);
  int b_thr = get<2>(b);
  int a_fou = get<3>(a);
  int b_fou = get<3>(b);
  if(a_one>b_one)
  {
    return true;
  }
  if(a_one == b_one)
  {
    if(a_two > b_two)
    {
      return true;
    }
    if(a_two == b_two)
    {
      if(a_thr>b_thr)
      {
        return true;
      }
      if(a_thr == b_thr)
      {
        if(a_fou>b_fou)
          return true;
        return false;
      }
      return false;
    }
    return false;
  }
  return false;
}
bool calc_range(int x, int y)
{
  if(x>=0 && x<N && y>=0 && y<N)
    return true;
  return false;
  
}
//그룹 찾기
//tuple -> (블록 수, 무지개 수, 기준 블록 행, 기준 블록 열, 그룹 넘버)
//0에서 시작하면 못지움
tuple<int,int,int,int,int> make_group(int x, int y, int g_num,vector<vector<tuple<int,int,int>>> &group)
{
  tuple<int,int,int,int,int> result;
  int block_num = 0;
  int rainbow_num = 0;
  int cent_x = 987654;
  int cent_y = 987654;
  queue<pair<int,int>> q;
  queue<pair<int,int>> r_q;
  vector<vector<bool>>visited(N,vector<bool>(N,false));
  int color  =grid[x][y];
  q.push(make_pair(x,y));
  r_q.push(make_pair(x,y));
  visited[x][y] = true;
  if(grid[x][y] == 0)
    rainbow_num++;
  block_num++;
  
  while(!q.empty())
    {
      pair<int,int> pos = q.front();
      int x = pos.first;
      int y = pos.second;
      if(grid[x][y] >0)
      {
      if(x < cent_x)
      {
        cent_x = x;
        cent_y = y;
        
      }
      else if(x == cent_x && y < cent_y)
      {
        cent_y = y;
      }
      }
      q.pop();
      for(int d=0;d<4;d++)
        {
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y) && !visited[mov_x][mov_y])
          {
            if(grid[mov_x][mov_y] == color|| grid[mov_x][mov_y] == 0)
            {
              visited[mov_x][mov_y] = true;
              q.push(make_pair(mov_x,mov_y));
              r_q.push(make_pair(mov_x,mov_y));
              if(grid[mov_x][mov_y] == 0)
                rainbow_num++;
              block_num++;
            }

            
          }
          
        }
      
    }
  while(!r_q.empty())
    {
      pair<int,int> pos = r_q.front();
      r_q.pop();
      int x = pos.first;
      int y = pos.second;
      group[x][y] = make_tuple(block_num,rainbow_num,g_num);
    }

  result = make_tuple(block_num,rainbow_num,cent_x,cent_y,color);
  return result;
}
//반시계 회전하기
void ccw_spin()
{
  vector<vector<int>>tmp = grid;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          grid[i][j] = tmp[j][N-1-i];

          
        }
    }
}
//중력 작용시키기
void gravity()
{
  int color;
  for(int c=0;c<N;c++)
    {
      for(int r=N-2;r>=0;r--)
        {
          if(grid[r][c] >=0)
          {
            int moving_r = r;
            while(moving_r+1<N && grid[moving_r+1][c] == -2)
              {
                moving_r++;
              }
            grid[moving_r][c] = grid[r][c];
            if(moving_r>r)
              grid[r][c] = -2;
            
          }
          
        }

      
    }

  
}
void scoring_block(int x, int y, int color)
{
  //dfs 한번 더 쓰는게 맞음
  int deleted = 1;
  queue<pair<int,int>>q;
  grid[x][y] = -2;
  q.push(make_pair(x,y));
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
          if(calc_range(mov_x,mov_y) )
          {
            if(grid[mov_x][mov_y] == color || grid[mov_x][mov_y] == 0)
            {
              deleted++;
              grid[mov_x][mov_y] = -2;
              q.push(make_pair(mov_x,mov_y));
              
            }
            
          }
              
        }
      
      
    }
  score+=(deleted * deleted);
}
void auto_play()
{
  vector<vector<tuple<int,int,int>>>group(N,vector<tuple<int,int,int>>(N,make_tuple(0,0,-1))); //블록 수, 무지개 블록 수, 그룹 넘버
  int group_num = 0;
  vector<tuple<int,int,int,int,int>>chk; //정렬해서 가장 좋은거 첫번째로 오게해서 그룹넘버로 삭제 후 점수 취득
  //그래비티 회전은 아예 다른 결
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(get<0>(group[i][j]) ==0 && grid[i][j] != -1 && grid[i][j] != -2 && grid[i][j] != 0)
          {
            //무지개 블록 시작점 불가능
            //모든 좌표 다해서 다 넣기
            tuple<int,int,int,int,int>tmp = make_group(i,j,group_num,group);
            if(get<0>(tmp)>1)
            {
              chk.push_back(tmp);
              //하나인 블록은 의미 없음
            }
            group_num++;
            //chk.push_back(make_group(i,j,group_num,group));//그룹 나누고 골라야함
            
          }
          
        }
    }
    if(chk.size() == 0)
    {
      auto_flag = false;
      return;
      //그룹을 찾지 못함
    }
    sort(chk.begin(),chk.end(),cmp);
    int x  =get<2>(chk[0]);
    int y = get<3>(chk[0]);
    int color = get<4>(chk[0]);
    //print_grid();
    scoring_block(x,y,color);
    //print_grid();
    gravity();
    //print_grid();
    ccw_spin();
    //print_grid();
    gravity();
    //print_grid();
    //잘지워짐
    //중력 작용
    //반시계 회전
    //중력작용
    
}
int main() {
  cin>>N>>M;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin>>grid[i][j];
  while(auto_flag)
    auto_play();
  cout<<score<<endl;
}