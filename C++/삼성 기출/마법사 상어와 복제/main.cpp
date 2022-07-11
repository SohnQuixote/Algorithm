#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
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
  왜 틀리는지 이해가 안됨
*/
int fish_dx[8] = {0,-1,-1,-1,0,1,1,1};
int fish_dy[8] = {-1,-1,0,1,1,1,0,-1};
int shark_dx[4] = {-1,0,1,0};
int shark_dy[4] = {0,-1,0,1};
vector<vector<vector<int>>> map(8,vector<vector<int>>(4,vector<int>(4,0))); //해당방향을 가진 물고기의 수
vector<vector<int>> smell(4,vector<int>(4,0));
//냄새 제한시간
int N = 4;
int shark_x,shark_y;
void print_smell()
{
  cout<<"printing smell::"<<endl;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<4;j++)
        {
          cout<<smell[i][j]<<' ';
        }
        cout<<endl;
      
    }
}
int fish_num(int x, int y)
{
  int result = 0;
  for(int d=0;d<8;d++)
    result+=map[d][x][y];
  return result;
}
void clear_fish(int x, int y)
{
  for(int d=0;d<8;d++)
    map[d][x][y] = 0;
}
void print_fish_num()
{
  cout<<"printing::"<<endl;
  for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
        {
          cout<<fish_num(i,j)<<' ';
        }
          cout<<endl;
      
    }
  
}
bool calc_range(int x, int y)
{
  if(x>=0&& x<4 && y>=0 && y<4)
    return true;
  return false;
}
int ccw_spin(int a, int b)
{
  int result = a-b;
  if(result<0)
    result+=8;
  return result%8;
}
void fish_move()
{
      queue<tuple<int,int,int,int>>q;
      for(int d=0;d<8;d++)
        {
          for(int i=0;i<4;i++)
            {
            for(int j=0;j<4;j++)
              {
                if(map[d][i][j]>0 )
                {
                  q.push(make_tuple(d,i,j,map[d][i][j]));
                  //해당 방향을 가진 물고기 존재

                }
              }

              
            }
        }
  while(!q.empty())
    {
      int d = get<0>(q.front());
      int i = get<1>(q.front());
      int j = get<2>(q.front());
      int num = get<3>(q.front());
      q.pop();
      for(int diff=0;diff<8;diff++)
      {
        int dir = ccw_spin(d,diff);
        int mov_i = i+fish_dx[dir];
        int mov_j = j+fish_dy[dir];
        //print_fish_num();
        if(calc_range(mov_i,mov_j) && !(mov_i == shark_x && mov_j == shark_y) && smell[mov_i][mov_j] == 0 )
        {
          map[d][i][j] -=num;
          map[dir][mov_i][mov_j] += num;
          break;  
        }
                      
      }   
    }
}


int cast(int s)
{
  int result =0;
  int i=0;
  while(i<s)
    {
      int mov[3] = {0,};
      vector<vector<vector<int>>>shark_ate(4,vector<vector<int>>(4,vector<int>(4,-500)));
      //1.
      vector<vector<vector<int>>> copy = map;
      //2.
      //cout<<shark_x<<' '<<shark_y<<endl;      
      //print_fish_num();
      fish_move();
      //print_fish_num();
      //3.
      vector<vector<int>>total_fish(4,vector<int>(4,0));
      int max_ate = -500;
      for(int one= 0;one<4;one++)
        {
          int shark_one_x = shark_x+shark_dx[one];
          int shark_one_y = shark_y+shark_dy[one];
          if(calc_range(shark_one_x,shark_one_y))
          {
            for(int two=0;two<4;two++)
              {
                int shark_two_x = shark_one_x+shark_dx[two];
                int shark_two_y = shark_one_y+shark_dy[two];
                if(calc_range(shark_two_x,shark_two_y))
                {
                  for(int thr = 0;thr<4;thr++)
                    {
                      int shark_thr_x = shark_two_x+shark_dx[thr];
                      int shark_thr_y = shark_two_y+shark_dy[thr];
                      if(calc_range(shark_thr_x, shark_thr_y))
                      {
                        int ate =0;
                        for(int r=0;r<4;r++)
                          for(int c=0;c<4;c++)
                            total_fish[r][c] = fish_num(r,c);
                        ate+=total_fish[shark_one_x][shark_one_y];
                        total_fish[shark_one_x][shark_one_y] = 0;
                        ate+=total_fish[shark_two_x][shark_two_y];
                        total_fish[shark_two_x][shark_two_y] = 0;
                        ate+=total_fish[shark_thr_x][shark_thr_y];
                        total_fish[shark_thr_x][shark_thr_y] = 0;
                        shark_ate[one][two][thr] = ate;
                      }
                    }
                  
                }

                
              }
            

            
          }
        }
      for(int r=0;r<4;r++)
        {
          for(int c=0;c<4;c++)
            {
              for(int t=0;t<4;t++)
              {
                //cout<<shark_ate[r][c][t]<<endl;
              if(shark_ate[r][c][t]>max_ate)
              {
                max_ate = shark_ate[r][c][t];
                mov[0] = r;
                mov[1] = c;
                mov[2] = t;
                
              }
              }
            }
        }
      for(int d=0;d<3;d++)
        {
        
          shark_x += shark_dx[mov[d]];
          shark_y += shark_dy[mov[d]];
          //cout<<shark_x<<' '<<shark_y<<endl;
          if(fish_num(shark_x,shark_y))
          {
            clear_fish(shark_x, shark_y);
            smell[shark_x][shark_y] =3;
          }
          
        }

      
      //4.
      for(int r=0;r<4;r++)
        {
        for(int c=0;c<4;c++)
          {
            if(smell[r][c] >0)
              smell[r][c]--;
            
          }
          
        }
      //5.
      for(int d=0;d<8;d++)
          for(int r=0;r<4;r++)
            for(int c=0;c<4;c++)
              map[d][r][c] += copy[d][r][c];
          
      //print_fish_num();
      //print_smell();
     i++; 
    }
  for(int r=0;r<4;r++)
    for(int c=0;c<4;c++)
      result+=fish_num(r,c);
  return result;
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
  cout<<cast(S)<<endl;
}