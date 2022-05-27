#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
/*
  청소년 상어
  4 * 4크기 공간
  한 칸에는 물고기 1마리 각 물고기 번호 방향 
  번호 (1~16) 방향 (상하좌우 대각선)
  번호 작은 물고기 부터 이동 -> 배열로 해서 이동시킴
  물고기 한칸 이동
  이동 못하는 칸이면 반시계 45도씩 계속 이동
  물고기 이동하면 서로 위치 바꿈
  상어 0,0부터 시작  
  그리디?
  행이 x 열이 y
*/
int dy[8] = {0,-1,-1,-1,0,1,1,1}; //0~7
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int result = 0;
bool calc_range(int a)
{
  if(a>=0 && a<=3)
    return true;
  return false;
}
void calc(vector<vector<pair<int,int>>> sea, int shark_dir,int shark_x,int shark_y, int shark_ate, vector<pair<int,int>> fishes)
{
  //물고기
  sea[shark_x][shark_y].first = -1;
  for(int i=1;i<17;i++)
    {
      int x = fishes[i].first;
      int y = fishes[i].second;
      if(sea[x][y].first != -1)
      {
        for(int d =0;d<8;d++)
          {
            int mov_dir = (sea[x][y].second +d) %8 ;
            int mov_x = x+dx[mov_dir];
            int mov_y = y+dy[mov_dir];
            if(calc_range(mov_x) && calc_range(mov_y) && !(mov_x == shark_x && mov_y == shark_y))
            {
              pair<int,int> swapped_loc = sea[mov_x][mov_y];
              sea[mov_x][mov_y] = make_pair(i,mov_dir);
              fishes[i] = make_pair(mov_x,mov_y);
              sea[x][y] = swapped_loc;
              if(swapped_loc.first>0)
                fishes[swapped_loc.first] = make_pair(x,y);
              break;
              
            }
          }
        
      }
        
    }
  //상어
  vector<pair<int,int>> moving_shark;
  int mov_x = shark_x +dx[shark_dir];
  int mov_y = shark_y +dy[shark_dir];
  //cout<<"original::"<<shark_x<<' '<<shark_y<<' '<<dx[shark_dir]<<' '<<dy[shark_dir]<<endl;
  while(calc_range(mov_x) && calc_range(mov_y))
    {
      //cout<<mov_x<<' '<<mov_y<<endl;
      moving_shark.push_back(make_pair(mov_x,mov_y));
      mov_x += dx[shark_dir];
      mov_y += dy[shark_dir];
    }
    if(moving_shark.size() == 0)
    {
      result = max(result,shark_ate);
    }
    for(int i=0;i<moving_shark.size();i++)
      {
        //vector<vector<pair<int,int>>> orig_sea = sea; 
        int chged_shark_dir = sea[moving_shark[i].first][moving_shark[i].second].second;
        int feed = sea[moving_shark[i].first][moving_shark[i].second].first;
        if(feed > 0)
        {
          vector<pair<int,int>> orig_fishes = fishes;
          calc(sea,chged_shark_dir,moving_shark[i].first,moving_shark[i].second , shark_ate+feed, fishes);
          fishes= orig_fishes;
        }
        //sea = orig_sea;
      }
}
int main() {
  vector<vector<pair<int,int>>> sea (4, vector<pair<int,int>>(4,make_pair(0,0)));
  //tuple<int,int,int> fishes_dir[17]; //1~16
  pair<int,int> fishes[17];
  //tuple써서 이동 방향과 좌표 저장
  for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
        {
          int num,dir;
          cin>>num>>dir;
          sea[i][j] = make_pair(num,dir-1);
          fishes[num] = make_pair(i,j);
        }
      
    }
  vector<pair<int,int>> fishes_vec;
  fishes_vec.push_back(make_pair(-1,-1));  
  for(int i=1;i<=16;i++)
    fishes_vec.push_back(fishes[i]);
  int first_food = sea[0][0].first;
  int first_dir = sea[0][0].second;
  sea[0][0].first = -1;
  //상어
  calc(sea,first_dir,0,0,first_food,fishes_vec);
  cout<<result<<endl;
}