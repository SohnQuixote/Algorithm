#include <iostream>
#include <vector>
using namespace std;
/*
  감시
  1- 한쪽 방향 - 선택지 4
  2 - 반대 - 선택지 2
  3 - 직각 선택지 4
  4 - 세방향 선택지 4
  5 - 네방향
  방향 칸 전체 감시 가능
  사각지대의 최소크기를 구하기
  dfs 사용
*/
int N,M;
//vector <pair<int,int>>cams[5];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool calc_range(int a, int b)
{
  if(a>=0 && a<b)
    return true;
  return false;
}
vector<vector<int>> spread_camera(vector<vector<int>> office, int x,int y, int d)
{
  office[x][y] = -1;
  int mov_x = x+dx[d];
  int mov_y = y+dy[d];
  while(calc_range(mov_x,N) && calc_range(mov_y,M) && office[mov_x][mov_y] != 6)
    {
      if(office[mov_x][mov_y] == 0)
        office[mov_x][mov_y] = -1;
      mov_x+=dx[d];
      mov_y+=dy[d];
    }
  return office;
}
bool chk_all(vector<vector<int>> office)
{
  bool result = true;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          if(office[i][j] >0 &&office[i][j]<6)
          {
            result = false;
            break;
          }
          
        }
      
    }
  return result;
}
int calc_unseen(vector<vector<int>> office)
{
  int result = 0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          if(office[i][j] == 0)
            result++;
        }
    }
  return result;
}
//1번 -> 하나씩
//본지역은 -1

int calc(vector<vector<int>> office)
{
  int result = calc_unseen(office);
  if(chk_all(office))
  {
    return result;
  }
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          if(office[i][j] > 0 && office[i][j] <6)
          {
            vector<vector<int>> orig_office = office;
            if(office[i][j] == 1)
            {
              for(int d=0;d<4;d++)
                {
                  office = orig_office;
                  office = spread_camera(office,i,j,d);              
                  result = min(result,calc(office));
                  
                }
              
              //모든 방향 다 호출해봐야함
            }
            else if(office[i][j]==2)
            {
               for(int d=0;d<2;d++)
                 {
                    office =orig_office;
                    office = spread_camera(office,i,j,d);
                   office = spread_camera(office,i,j,d+2);
                   result = min(result,calc(office));
                   
                 }
              
              
            }
            else if(office[i][j] == 3)
            {
              for(int d=0;d<4;d++)
                {
                  office = orig_office;
                  office = spread_camera(office,i,j,d);
                  office = spread_camera(office,i,j,(d+1) %4);
                  result = min(result,calc(office));                  
                }
            }
            else if(office[i][j] == 4)
            {
              for(int d = 0;d<4;d++)
                {
                  office = orig_office;
                  for(int c = 0;c<4;c++)
                    {
                      if(c!=d)
                      {
                        office = spread_camera(office,i,j,c);

                        
                      }

                      
                    }
                result = min(result,calc(office));
                  
                }
              
            }
            else
            {
              for(int d=0;d<4;d++)
                {
                  office = spread_camera(office,i,j,d);
                  
                }
              result = min(result,calc(office));              
            }
            //카메라 하나마다 재귀호출
            break;
          }
          
        }
      
    }
  return result;
}
int main() {
  
  vector<vector<int>> office(8,vector<int>(8,0));
  
  cin>>N>>M;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          cin>>office[i][j];
        }
      
    }
  cout<<calc(office)<<endl;
}