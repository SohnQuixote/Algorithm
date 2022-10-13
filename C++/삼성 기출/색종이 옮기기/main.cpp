#include <iostream>
using namespace std;
/*
  색종이 붙이기
  1*1, 2*2, 3*3,4*4,5*5
  각 종류 색종이 5개씩
  모든 1을 덮는데 필요한 색종이의 최소 개수
  dfs로하면 될 것으로 보임
  가장 왼쪽 위에 있는 1
  색종이 겹쳐도 안됨
*/
int arr[10][10] = {0,};
int papers[6] = {0,5,5,5,5,5};
int result = 987654321;
int jongied[10][10] = {0,};
void find_next_one(int &x, int &y)
{
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
        {
          if(arr[i][j])
          {
            x=i;
            y=j;
            return;
          }

          
        }

      
    }

  
}
bool chk_all_covered()
{
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      if(arr[i][j])
        return false;
  return true;
}
bool can_cover(int x,int y, int t)
{
  if(x+t>10)
    return false;
  if(y+t>10)
    return false;

  
  for(int i=x;i<x+t;i++)
    for(int j=y;j<y+t;j++)
      if(!arr[i][j] || jongied[i][j])
        return false;
  if(papers[t])
    return true;
  else
    return false;

  
}
bool paper_remain()
{
  int chk=0;
  for(int i=1;i<=5;i++)
    {
      chk+=papers[i];
    }
  if(chk)
    return true;
  else
    return false;
  
}
void covering(int x, int y, int t)
{
  for(int r=x;r<x+t;r++)
    {
    for(int c=y;c<y+t;c++)
      {
        jongied[r][c] = 1;
        arr[r][c] = 0;
      }
    }
}
void recover(int x, int y, int t)
{
  for(int r=x;r<x+t;r++)
    {
    for(int c=y;c<y+t;c++)
      {
        jongied[r][c] =0;
        arr[r][c] = 1;
      }
    }
  
}
void cover(int paper,int sx, int sy)
{
  
  if(chk_all_covered())
  {
    result = min(result, paper);
    return;
  }
  //커버 못할 경우
  if(!paper_remain())
  {
    return;
  }
  //이렇게 하면 중복되는 부분문제가 되나?
  //그렇다
  //어떻게 해결해야 하나?
  //시작지점을 정해야 한다
  //첫번째는 0,0
  //두번째는 반복을 해서 다음 빈칸
      int nx=0;
      int ny=0;
        if(arr[sx][sy])
        {
          for(int t=5;t>=1;t--)
            {
              if(can_cover(sx,sy,t) && result >(paper+1))
              {
                //전부다 커버한 뒤 재귀 호출 시행
                covering(sx,sy,t);
                //다른 타입으로도 해봐야 해서 복구
                //다음 1빈칸을 찾아야함
                papers[t]--;
                find_next_one(nx,ny);
                cover(paper+1,nx,ny);
                papers[t]++;
                recover(sx,sy,t);
                
              }

              
            }
          
        }

  
  
}
int main() {
  int sx =-1;
  int sy = -1;
  for(int r=0;r<10;r++)
    {
    for(int c=0;c<10;c++)
      {
        cin>>arr[r][c];
        if(arr[r][c] && (sx ==-1 && sy ==-1)) 
        {
          sx =r;
          sy =c;
        }
      }
    }
  cover(0,sx,sy);
  if(result != 987654321)
    cout<<result;
  else
    cout<<-1;
}