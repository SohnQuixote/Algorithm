#include <iostream>
#include <vector>
using namespace std;
/*
  정수 삼각형
  맨 위부터 시작하여 아래있는 수 선택 내려옴 선택된 수 합 최대 경로
  배열 활용하여 밑 삼각행렬처럼 구현
*/
int dr[2] = {1,1};
int dc[2] = {0,1};
int calc(vector<vector<int>> tri , int N)
{
  int answer = -1;
  vector<vector<int>> mov_tri = tri;
  for(int r = 0;r<N-1;r++)
    {
      //끝에서 두번째 행까지
      for(int c=0;c<N;c++)
        {
          if(mov_tri[r][c] == -1)
          {
            break;
          }
          else
          {
            for(int i=0;i<2;i++)
              {
                int mov_r = r+dr[i];
                int mov_c = c+dc[i];
                mov_tri[mov_r][mov_c] = max(mov_tri[mov_r][mov_c], mov_tri[r][c]+ tri[mov_r][mov_c]);
              }
          }
        }
    }
  for(int c=0;c<N;c++)
    answer = max(answer, mov_tri[N-1][c]);
  return answer;
}
int main() {
  //std::cout << "Hello World!\n";
  int answer;
  int N;
  cin>>N;
  vector<vector<int>> triangle(N,vector<int>(N,-1));
  //미리 -1로 초기화여 불가능한 곳 표시
  for(int r=0;r<N;r++)
    {
      for(int c=0;c<=r;c++)
        {
          cin>>triangle[r][c];
        }
    }//잘 생성됨
    answer = calc(triangle,N);
    cout<<answer<<endl;
    /*for(int r=0;r<N;r++)
    {
      for(int c=0;c< N;c++)
        {
          cout<<triangle[r][c]<<' ';
        }
      cout<<endl;
    }*/
  
}