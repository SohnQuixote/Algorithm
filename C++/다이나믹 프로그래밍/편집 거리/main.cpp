#include <iostream>
#include <string>
#include <vector>
/*
  편집 거리
  문자열 두개 A,B
  A편집 B만들려 함
  연산 - 삽입, 삭제, 교체
  최소 편집거리 계산
  편집거리 알고리즘은 외워둬야함
*/
using namespace std;
int main() 
{
  string a,b;
  cin>>a>>b;
  int a_size = a.length()+1;
  int b_size = b.length()+1;
  vector<vector<int>> table(a_size , vector<int>(b_size,0));
  for(int r=0;r<a_size;r++)
    {
      table[r][0] = r;
    }
  for(int c=0;c<b_size;c++)
    {
      table[0][c] = c;
    }
  for(int r=1;r<a_size;r++)
    {
      for(int c=1;c<b_size;c++)
        {
          if(a[r-1] == b[c-1])
          {
            table[r][c] = table[r-1][c-1];
            //동일하면 그대로 사용
          }
          else
          {
            table[r][c] = min(table[r][c-1]+1,min(table[r-1][c-1] +1 , table[r-1][c]+1));
            //r-1,c-1 에서 오는거 변경 
            //r, c-1 에서 오는거 삽입
            //r-1, c 에서 오는거 삭제 
            //ex so->su : (so->s) +u / (s -> su) + o / s(o-> u)
          }
        }
    }
  cout<<table[a_size-1][b_size-1]<<endl;
}