#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  어항 정리
  N 4의 배수
*/
const int MAX = 100;
int N,K;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool calc_range(int x, int y)
{
  if(x>=0 && x<MAX && y>=0 && y<MAX)
    return true;
  return false;
}
vector<vector<int>> cw_spin(int w,int h, vector<vector<int>> spinning)
{
  //90도 회전
  vector<vector<int>>result(w,vector<int>(h,0));
  for(int r=0;r<w;r++)
    {
      for(int c=0;c<h;c++)
        {
          result[r][c] = spinning[h-1-c][r];

          
        }
    }
  return result;
}
 bool diff(vector<int>fishes)
{
  int mini = 987654321;
  int maxi = -987654321;
  for(int i=0;i<N;i++)
    {
      mini = min(mini,fishes[i]);
      maxi = max(maxi,fishes[i]);  
    }
  if(maxi-mini<=K)
    return true;
  return false;
}
int find_min(vector<int>fishes)
{
  int result = 987654321;
  for(int i=0;i<N;i++)
    result = min(result,fishes[i]);
  return result;
}
void print_field(vector<vector<int>> f)
{
  cout<<endl<<"printing::"<<endl;
  for(int i=95;i<100;i++)
    {
      for(int j=0;j<15;j++)
        {
          if(f[i][j] == -1)
            cout<<0<<' ';
          else
            cout<<f[i][j]<<' ';
          
        }
      cout<<endl;
    }
}
void stab_fish(vector<vector<int>> & field)
{
  vector<vector<int>> deg(MAX,vector<int>(MAX,0));
  queue<pair<int,int>>q;
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      if(field[i][j] != -1)
        q.push(make_pair(i,j));
  while(!q.empty())
    {
      pair<int,int>pos = q.front();
      q.pop();
      int x = pos.first;
      int y = pos.second;
      //cout<<x<<' '<<y<<field[x][y]<<endl;
      for(int d=0;d<4;d++)
        {
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y) && field[mov_x][mov_y] != -1 && field[x][y] >= field[mov_x][mov_y] +5 )
          {
            deg[x][y] -= (field[x][y] - field[mov_x][mov_y])/5;
            
            deg[mov_x][mov_y] += (field[x][y] - field[mov_x][mov_y])/5;

            
          }
          
        }
      
    }
    for(int i=0;i<MAX;i++)
      for(int j=0;j<MAX;j++)
        field[i][j] += deg[i][j];
}
int organize(vector<int>fishes)
{
  int result = 0;
  while(!diff(fishes))
    {

      //회전해서 올리기
      vector<vector<int>>field(MAX,vector<int>(MAX,-1));
      int one_add = find_min(fishes);
      for(int i=0;i<N;i++)
        if(fishes[i] == one_add)
          fishes[i]++;
      for(int i=0;i<N;i++)
        field[99][i] = fishes[i];
      //2개올리는것까지는 하드 코딩
      field[98][2] = field[99][1];
      field[99][1] = -1;
      field[98][3] = field[99][0];
      field[99][0] = -1;
      int s_x,s_y,s_w,s_h;
      int b_x,b_y;
      
      s_x = 98;s_y=2;
      s_w =2;s_h = 2;
      b_x = 99- s_w;b_y = s_y+s_w;
      int left_dist = N - 2* s_w;
      while(left_dist>=s_h)
        {
          //cout<<left_dist<<endl;
          //print_field(field);
          vector<vector<int>>spinning(s_h,vector<int>(s_w,0));
          for(int r=s_x;r<s_x+s_h;r++)
            {
              for(int c = s_y;c<s_y+s_w;c++)
                {
                  spinning[r-s_x][c-s_y] = field[r][c];
                  field[r][c]=-1;
                }
              
            }
          vector<vector<int>>spinned = cw_spin(s_w,s_h,spinning);
          for(int r=0;r<s_w;r++)
            {
              for(int c=0;c<s_h;c++)
                {
                  field[b_x+r][b_y+c] = spinned[r][c];
                  
                }
              
            }
          int tmp;
          tmp = s_h;
          s_h = s_w+1;
          s_w = tmp;
          s_x = b_x;
          s_y = b_y;
          b_x = 99-s_w;
          b_y = s_y+s_w;
          
          left_dist -= s_w;
          //print_field(field);
          //cout<<s_w<<' '<<s_h<<' '<<left_dist<<endl;
                    
        }
      //회전 잘 됐는지 확인 
      //3. 어항 물고기 수 조정

      //print_field(field);
      stab_fish(field);
      //print_field(field);
      //다시 일렬로
      
      fishes.clear();
      for(int c=0;c<MAX; c++)
        {
          for(int r=99;r>=0&& field[r][c] != -1;r--)
            {
              fishes.push_back(field[r][c]);

              
            }
        }
      for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
          field[i][j] = -1;
      for(int i=0;i<N;i++)
        field[99][i] = fishes[i];
      //print_field(field);
      //두번 회전해서 올림 - 하드코딩
      //처음 180도
      for(int i = N/2;i<N;i++)
        {
          field[98][i] = field[99][(N/2-1) - (i-N/2)];
          field[99][(N/2-1) - (i-N/2)] = -1;
        }
      //print_field(field);
      b_x = 96;
      b_y = N/2 + N/4;
      vector<vector<int>>spinning(2,vector<int>(N/4,0));
      vector<vector<int>> spinned;
      vector<vector<int>>final_spinned;
      for(int i=0;i<2;i++)
        {
          for(int j=0;j<N/4;j++)
            {
              spinning[i][j] = field[i+98][N/2+j];
              field[i+98][N/2+j] = -1;
              
            }
          
        }
      //print_field(field);
      spinned = cw_spin(N/4,2,spinning);
      final_spinned = cw_spin(2,N/4,spinned);
      for(int r = 0;r<2;r++)
        {
          for(int c=0;c<N/4;c++)
            {
              field[b_x+r][b_y+c] = final_spinned[r][c];

              
            }          
        }
      //print_field(field);
      stab_fish(field);
      //print_field(field);
      fishes.clear();
      for(int c=0;c<MAX; c++)
        {
          for(int r=99;r>=0&& field[r][c] != -1;r--)
            {
              fishes.push_back(field[r][c]);

              
            }
        }
      result++;
    }
  return result;
}
int main() {
  cin>>N>>K;
  vector<int>fishes(N,0);
  for(int i=0;i<N;i++)
    cin>>fishes[i];
  cout<<organize(fishes)<<endl;
  
}