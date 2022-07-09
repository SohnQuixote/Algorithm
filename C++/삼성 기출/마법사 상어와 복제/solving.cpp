#include <iostream>
#include <vector>
using namespace std;
/*
  마법사 상어와 복제
  (4,4)
  (0,0) ~ (3,3)
  물고기 M마리 - 격자의 칸 하나
  -이동방향 가짐
  -상어도 격자의 칸 하나
  -둘 이상 물고기 같은칸 가능 - 마법사 상어 물고기 같은칸 가능

  1. 상어 복제마법 시전
  2. 물고기 이동 - 냄새 칸,상어칸, 범위 X칸 불가능 이동 가능할 때까지 회전
  3. 상어 연속 3칸 이동 물고기칸 이동 - 물고기 제외 - 냄새 남음 - 물고기 가장 많은 방법 이동 - 여러개 -> 사전순
  4. 두번전 마법 - 물고기 냄새 사라짐
  5. 1. 마법 완료 - 위차 방향 그대로
*/
int fish_dx[8] = {0,-1,-1,-1,0,1,1,1};
int fish_dy[8] = {-1,-1,0,1,1,1,0,-1};
int shark_dx[4] = {-1,0,1,0};
int shark_dy[4] = {0,-1,0,1};
vector<vector<vector<int>>> map(8,vector<vector<int>>(4,vector<int>(4,0))); //해당방향을 가진 물고기의 수
int N = 4;
int shark_x,shark_y;
int ccw_spin(int a)
{
  int result = a-1;
  if(result<0)
    result+=8;
  return result%8;
}
int cast(int s)
{

  
}
int main() {
  int M,S;
  cin>>M>>S;
  for(int i=0;i<M;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      a--;
      b--;
      c--;
      map[c][a][b]++;
      
    }
  cin>>shark_x>>shark_y;
  shark_x--;
  shark_y--;
  cout<<cast<<(S)<<endl;
}