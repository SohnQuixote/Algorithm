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
bool calc_range(int a)
{
  if(a>=0 && a<=3)
    return true;
  return false;
}
int ate_total = 0;
int calc(vector<vector<int>> sea,tuple<int,int,int> fishes[],int shark_x,int shark_y, int shark_dir, int shark_ate)
{
    for(int i=1;i<=16;i++)
      {
        int orig_dir = get<0>(fishes[i]);
        int fish_x = get<1>(fishes[i]);
        int fish_y = get<2>(fishes[i]);
        if(orig_dir != -1)
        {
          //물고기 생존
          int mov_dir;
          int mov_fish_x;
          int mov_fish_y;
          for(int d = 0;d<8;d++)
            {
              mov_dir = (orig_dir+d)%8;
              mov_fish_x = fish_x +dx[mov_dir];
              mov_fish_y = fish_y +dy[mov_dir];
              if(calc_range(mov_fish_x) && calc_range(mov_fish_y) && (mov_fish_x != shark_x || mov_fish_y != shark_y))
              {
                int mov_fish_num = sea[mov_fish_x][mov_fish_y];
                sea[mov_fish_x][mov_fish_y] = i;
                sea[fish_x][fish_y] = mov_fish_num;
                fishes[i] = make_tuple(mov_dir,mov_fish_x,mov_fish_y);
                if(mov_fish_num != 0)
                {
                  fishes[mov_fish_num] = make_tuple(get<0>(fishes[mov_fish_num]) , fish_x,fish_y);
                }
                
                break;
              }
              
            }
        }
      }
  /*for(int i=1;i<17;i++)
    {
      cout<<get<0>(fishes[i])<<' '<<get<1>(fishes[i])<<' '<<get<2>(fishes[i])<<endl;
    }*/
  //물고기 이동은 잘되는 것으로 보임
    /*for(int r=0;r<4;r++)
      {
        for(int c=0;c<4;c++)
          {
            cout<<sea[r][c]<<' ';
          }
        cout<<endl;
        
      }*/
    //상어 이동
    int mv_shark = 0;
    int mv_shark_x = shark_x + dx[shark_dir];
    int mv_shark_y = shark_y + dy[shark_dir];
    int orig_shark_ate = shark_ate;
    while(calc_range(mv_shark_x) && calc_range(mv_shark_y))
      {
        //cout<<"moving shark..."<<mv_shark_x<<' '<<mv_shark_y<<' '<<shark_dir<<endl;
        //범위 안에 있을 때
        if(sea[mv_shark_x][mv_shark_y] != 0)
        {
          //먹이가 있음
          int chged_shark_dir = get<0>(fishes[sea[mv_shark_x][mv_shark_y]]);
          fishes[sea[mv_shark_x][mv_shark_y]] = make_tuple(-1,-1,-1); //먹어서 없어짐//이동 필요 없음
          int fed = sea[mv_shark_x][mv_shark_y];
          sea[shark_x][shark_y] = 0;
          sea[mv_shark_x][mv_shark_y] = 0;
          //cout<<orig_shark_ate<<' '<<fed<<endl;
          shark_ate = max(shark_ate, calc(sea,fishes,mv_shark_x,mv_shark_y,chged_shark_dir, orig_shark_ate + fed));//누적됨
          sea[mv_shark_x][mv_shark_y] = fed;
          fishes[sea[mv_shark_x][mv_shark_y]] = make_tuple(chged_shark_dir,mv_shark_x,mv_shark_y);                 //안먹고 다른곳도 먹어봐야함
          ate_total++;
          
        }
        mv_shark_x += dx[shark_dir];
        mv_shark_y += dy[shark_dir];

        
    }
    
  return shark_ate;
}
int main() {
  vector<vector<int>> sea (4, vector<int>(4,0));
  tuple<int,int,int> fishes_dir[17]; //1~16
  //tuple써서 이동 방향과 좌표 저장
  for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
        {
          int num,dir;
          cin>>num>>dir;
          fishes_dir[num] = make_tuple(dir-1,i,j);
          sea[i][j] = num;
          
        }
      
    }
  int shark_dir = get<0>(fishes_dir[sea[0][0]]);
  int first_food = sea[0][0];
  //cout<<"first food::"<<sea[0][0]<<endl;
  fishes_dir[sea[0][0]] = make_tuple(-1,-1,-1);//먹혔음
  /*for(int i=1;i<17;i++)
    {
      cout<<get<0>(fishes_dir[i])<<' '<<get<1>(fishes_dir[i])<<' '<<get<2>(fishes_dir[i])<<endl;
    }*/
  sea[0][0] = 0;
  cout<<calc(sea,fishes_dir,0,0,shark_dir, first_food)<<endl;
  //cout<<ate_total+1<<endl;
}