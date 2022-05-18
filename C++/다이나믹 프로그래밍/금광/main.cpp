#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  탑다운/보텀업
  금광 
  n*m크기 금광 
  첫번째 열 출발 금 캐기 시작
  첫번째 열 어느행이든 가능
  m번에 걸쳐서 오른쪽 위, 오른쪽 오른쪽 아래 이동 
*/
//vector<vector<int>>mine( 21, vector<int>(21,0));
//매번 max로 해서 이동 - 마지막 열의 최댓값이 최대 크기
//큐로도 bfs로 가능하지만 반복문으로 한번 해결 
int dr[3] = {-1,0,1};
int dc[3] = {1,1,1}; //우측 위 , 우측 , 우측 아래
bool range_chk(int a, int r)
{
  if(a>=0 && a< r)
  {
    return true;
  }
  return false;
}
int calc(vector<vector<int>>mine, int n,int m)
{
  int result  =0;
  vector<vector<int>> mov_mine = mine; //최댓값 저장
  for(int c = 0;c<m-1;c++)
    {
      //첫 열부터
      for(int r = 0;r<n;r++)
        {
        //모든 행 쳌
          for(int i=0;i<3;i++)
            {
              //이동 방향 전부 쳌
              int mov_r = r+dr[i];
              int mov_c = c+dc[i];
              if(range_chk(mov_r,n) && range_chk(mov_c,m))
              {
                //갈수 있음
                mov_mine[mov_r][mov_c] = max(mov_mine[mov_r][mov_c] , mov_mine[r][c] + mine[mov_r][mov_c]); //계속해서 누적 안되게 이동할 위치는 변경 안된 정보 사용
                
              }
              
            }
      
          
        }
      /*cout<<"이동 열::"<<c<<endl;
      for(int r = 0;r<n;r++)
        {
          for(int c = 0;c<m;c++)
            {
              cout<<mov_mine[r][c]<<' ';
            }
          cout<<endl;
        }*/
      
    }
  for(int r = 0;r<n;r++)
    {
     result = max(result, mov_mine[r][m-1]); 
    }
  return result;
}
int main() {
  int T,n,m;
  cin>>T;
  vector<int>result;  
  for(int i=0;i<T;i++)
    {
      cin>>n>>m;
      vector<vector<int>>mine(n,vector<int>(m,0)); //n*m광산 생성
      //0~n-1 , 0~m-1 - 이 범위 벗어나면 못감
      for(int r = 0;r<n;r++)
        {
          for(int c = 0;c<m;c++)
            {
              cin>>mine[r][c];
            }
        }
      result.push_back(calc(mine,n,m));
    }
  for(int i=0;i<T;i++)
    {
      cout<<result[i]<<endl;
    }
}