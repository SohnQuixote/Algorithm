#include <iostream>
#include <vector>
using namespace std;
/*
  게리맨더링 2
  재현시 N*N 격자
  구역 다섯개 선거구
  선거구 - 구역 포함 
  선거구 구역 모두 연결 
  다른 구역 안거침
  모두 다 나눠보고 계산
*/
const int MAX = 20;
int summ = 0;
int N;
vector<vector<int>>grid(MAX,vector<int>(MAX,0));
pair<int,int> find_mi_ma(vector<int>surf)
{
  int mini = 987654321;
  int maxi = -1;
  for(int i=1;i<6;i++)
    {
      mini = min(mini,surf[i]);
      maxi = max(maxi,surf[i]);
    }
  return make_pair(mini,maxi);
}
void print_sur(vector<vector<int>> s)
{
  cout<<endl<<"printing::"<<endl;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<s[i][j]<<' ';
        }
      cout<<endl;
    }
}
int divide_conquer(int x, int y, int d_1,int d_2,vector<vector<int>> sur)
{
  int result = 0;
  pair<int,int> tmp;
  vector<int>surfaces(6,0);
  int remain = 0;
  for(int r = 0;r<N;r++)
    {
      for(int c=0;c<N;c++)
        {
          if(sur[r][c] != 5)
          {
          if(r<x+d_1 && c<=y)
          {
            surfaces[1] += grid[r][c];
            sur[r][c] = 1;
            remain+= grid[r][c];
          }
          if(r<= x+d_2 && c>y )
          {
            surfaces[2] += grid[r][c];
            sur[r][c] = 2;
            remain+= grid[r][c];
          }
          if(r>= x+d_1 && c < y-d_1+d_2)
          {
            surfaces[3] += grid[r][c];
            sur[r][c] = 3;
            remain+= grid[r][c];
          }
          if(r>x+d_2 &&c>= y-d_1+d_2)
          {
            surfaces[4] += grid[r][c];
            sur[r][c] = 4;
            remain+=grid[r][c];
          }
        }
        }
    }
  surfaces[5] = summ-remain;
  //print_sur(sur);
  tmp = find_mi_ma(surfaces);
  return (tmp.second - tmp.first);
}
void sector_five(vector<vector<int>> &f, int x, int y,int d_1,int d_2)
{
  //경계선 그리고 행 기준으로 경계선 각 끝부분 찾아서 5로 대체  
  for(int i = 0;i<=d_1;i++)
    {
      f[x+i][y-i] = 5;
    }
  for(int i=0;i<=d_2;i++)
    {
        f[x+i][y+i] = 5;
    }
  for(int i=0;i<=d_2;i++)
    {
      f[x+d_1+i][y-d_1+i] = 5;
    }
  for(int i=0;i<=d_1;i++)
    {
      f[x+d_2+i][y+d_2-i] = 5;
    }
  for(int r =0;r<N;r++)
    {
      int start =-1;
      int end = -1;
      for(int c=0;c<N;c++)
        {
         if(f[r][c] == 5)
         {
           start = c;
           break;
         }
        }
      for(int c= N-1;c>=0;c--)
        {
          if(f[r][c] == 5)
          {
            end = c;
            break;
          }
          
        }
        if(start != -1 && end != -1)
        {
          for(int c= start;c<end;c++)
            {
              f[r][c] = 5;
            }
          
        }
    }
}
int calc()
{
  int result = 987654321;
  for(int x =0;x<N;x++)
    {
      for(int y =0;y<N;y++)
        {
          //기준 점
          for(int d_1 =1;d_1<N;d_1++)
            {
              for(int d_2 = 1;d_2<N;d_2++)
                {
                  if(x+d_1+d_2 < N && y-d_1 >=0 && y+d_2 < N)
                  {
                      //cout<<x<<' '<<y<<' '<<d_1<<' '<<d_2<<endl;
                      vector<vector<int>>sur(N,vector<int>(N,0));
                      sector_five(sur,x,y,d_1,d_2);
                      result = min(result,divide_conquer(x,y,d_1,d_2,sur));
                  }
                }
              
            }
          
        }      
    }
  return result;
}
int main() 
{
  cin>>N;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cin>>grid[i][j];
          summ+=grid[i][j];
        }
    }
  cout<<calc()<<endl;

  
}