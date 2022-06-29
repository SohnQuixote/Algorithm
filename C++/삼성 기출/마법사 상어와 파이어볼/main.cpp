#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <numeric>
using namespace std;
/*
  마법사 상어와 파이어볼
  결과 - 남아있는 파이어볼 질량
*/

int N,M,K;
const int MAX = 50;
vector<vector<int>>map(MAX,vector<int>(MAX,0));
//무게 누적
queue<tuple<int,int,int,int,int>>a_q;
//행, 열, 질량, 방향, 속력, 합쳐짐 여부, 합쳐진 방향(홀|짝)
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int calc_fire()
{
  int result = 0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        result+=map[i][j];
    }
  return result;
}
int modular_calc(int a, int b)
{
  int result =a+b;
  while(result<0)
    {
      result+=N;
    }
  return result % N;
}
int cast_fire_ball()
{
  queue<tuple<int,int,int,int,int>>q;
  queue<tuple<int,int,int,int,int>>c_q = a_q;
  
  int i=0;
  int result = 0;
  while(i<K)
    {
      vector<vector<tuple<int,int,int,bool>>>tmp_map(N,vector<tuple<int,int,int,bool>>(N,make_tuple(0,0,-1,false)));
      //누적 질량, 누적 속도 ,누적방향 , 두개 이상 여부
      vector<int> dir_chk[N][N]; //-->방향 다 누적해서 체크하는 수밖에 없음
      q = c_q;
      queue<tuple<int,int,int,int,int>>tmp_q;
      result = 0;
      while(!q.empty())//차례한번
        {
          tuple<int,int,int,int,int>info = q.front();
          q.pop();
          int x = get<0>(info);
          int y = get<1>(info);
          int m = get<2>(info);
          int s = get<3>(info);
          int d = get<4>(info);
          int mov_x = modular_calc(x,s*dx[d]);
          int mov_y = modular_calc(y,s*dy[d]);
          tuple<int,int,int,bool> map_pos = tmp_map[mov_x][mov_y];
          int mov_m = get<0>(map_pos) + m;
          int mov_s = get<1>(map_pos) + s;
          if(mov_m>m)
            tmp_map[mov_x][mov_y] = make_tuple(mov_m,mov_s,d,true);
          else
            tmp_map[mov_x][mov_y] = make_tuple(mov_m,mov_s,d,false);
          dir_chk[mov_x][mov_y].push_back(d %2);
          //전부 누적 완료
          map[x][y] = 0;
          //result +=m;
        }

      //누적된거 나누거나 바로 큐에 집어넣기
      for(int r=0;r<N;r++)
        {
          for(int c=0;c<N;c++)
            {
              tuple<int,int,int,bool>info = tmp_map[r][c];
              int m = get<0>(info);
              int s = get<1>(info);
              int d = get<2>(info);
              bool two_more = get<3>(info);
              if(m>0)
              {
              
              if(two_more == true)
              {
                //4개로 나눠야함
                m/=5;
                if(m>0)
                {
                  int size = dir_chk[r][c].size();
                  s/=size;
                  int chk = accumulate(dir_chk[r][c].begin(),dir_chk[r][c].end(),0);
                  if(chk ==0 || chk == size)
                  {
                    //모두짝/홀
                    tmp_q.push(make_tuple(r,c,m,s,0));
                    tmp_q.push(make_tuple(r,c,m,s,2));
                    tmp_q.push(make_tuple(r,c,m,s,4));
                    tmp_q.push(make_tuple(r,c,m,s,6));
                    map[r][c] = 4*m;
                  }
                  else
                  {
                    tmp_q.push(make_tuple(r,c,m,s,1));
                    tmp_q.push(make_tuple(r,c,m,s,3));
                    tmp_q.push(make_tuple(r,c,m,s,5));
                    tmp_q.push(make_tuple(r,c,m,s,7));
                    map[r][c] = 4*m;
                  }

                  
                }
              }
              else
              {
                tmp_q.push(make_tuple(r,c,m,s,d));
                map[r][c] = m;
              }
              } 
            }
        }
      c_q = tmp_q;      
      i++;
      
      
    }
  result = calc_fire();
  return result;
}
int main() {
  cin>>N>>M>>K;
  for(int i=0;i<M;i++)
    {
      int r,c,m,s,d;
      cin>>r>>c>>m>>s>>d;
      r--;c--;
      //rcmsd
      map[r][c] =m;
      a_q.push(make_tuple(r,c,m,s,d));
      //cout<<endl<<r<<' '<<c<<' '<<s*dx[d]<<' '<<modular_calc(r ,s*dx[d])<<' '<<s*dy[d]<<' '<<modular_calc(c, s*dy[d])<<endl;
    }
  cout<<cast_fire_ball()<<endl;
}