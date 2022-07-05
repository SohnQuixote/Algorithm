#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  마법사 상어와 비바라기
  N*N 격자
  격자 각칸 바구니
  바구니 저장물 제한 없음
  0,0 ~ N-1,N-1
  모듈러 연산해야됨
  비바라기 시전
  ->(N-1,(0,1))
  ->(N-2,(0,1))
  비구름 생성  
  이동 명령 -> 
1. 모든 구름 d방향 s칸 이동
2. 구름에서 비가 내려 저장된 물의양 증가
3. 구름 사라짐
4. 물이 증가한 칸에 인접한 대각선의 바구니 물 양 1증가
5. 물양 2이상인 칸에 구름 생김 물의 양 줄어듬
-> 구름이 생기는 칸 -> 사라진칸 아니어야함
*/
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int N,M;
vector<vector<int>>buckets(50,vector<int>(50,0));
vector<vector<bool>>cloud(50,vector<bool>(50,false));
int mod_add(int a,int b)
{
  int result = a+b;
  while(result <0)
    result+=N;
  return (result %N);
}
bool calc_range(int x, int y)
{
  if(x>=0 && x<N && y>=0 && y<N)
    return true;
  return false;
  
}
void clear_cloud()
{
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cloud[i][j] = false;
}
void move_clouds(pair<int,int>cmd)
{
  vector<vector<bool>>tmp_c;
  int dir = cmd.first;
  int speed = cmd.second;
  queue<pair<int,int>>q;
  //1. 모든 구름 이동
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(cloud[i][j])
          {
            q.push(make_pair(i,j));
            cloud[i][j] = false;
          }
          
        }
    }
  while(!q.empty())
    {
      pair<int,int>pos = q.front();
      q.pop();
      int x = pos.first;
      int y = pos.second;
      int mov_x = mod_add(x,speed * dx[dir]);
      int mov_y = mod_add(y,speed * dy[dir]);
      cloud[mov_x][mov_y] = true;
      //2.구름 비가내려서 물의 양 1증가
      buckets[mov_x][mov_y]++;
    }
  

  //3.구름 사라짐
  tmp_c = cloud;
  clear_cloud();
  //4.물복사
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(tmp_c[i][j])
          {
            q.push(make_pair(i,j));
          }
          
        }
      
    }
  
  while(!q.empty())
    {
      int buckets_num = 0;
      pair<int,int> pos = q.front();
      int x =pos.first;
      int y = pos.second;
      q.pop();
      
      for(int d=1;d<5;d++)
        {
          int dir = 2*d;
          int mov_x = x+dx[dir];
          int mov_y = y+dy[dir];
          if(calc_range(mov_x,mov_y) && buckets[mov_x][mov_y]>0)
          {
            buckets_num++;
            
          }
          
        }
      buckets[x][y] += buckets_num;
    }
  //5.새로운 물로 구름
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(buckets[i][j]>=2 && !tmp_c[i][j])
          {
            cloud[i][j] = true;
            buckets[i][j]-=2;
          }

          
        }
    }
}
int accum_water()
{
  int result = 0;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      result+=buckets[i][j];
  return result;
}
int main() {
  cin>>N>>M;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin>>buckets[i][j];
  cloud[N-1][0] = true;
  cloud[N-1][1] = true;
  cloud[N-2][0] = true;
  cloud[N-2][1] = true;
  
  for(int i=0;i<M;i++)
    { 
      int a,b;
      cin>>a>>b;
      move_clouds(make_pair(a,b));

      
    }
  cout<<accum_water()<<endl;
}