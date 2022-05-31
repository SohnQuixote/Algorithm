#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*
  인구 이동
  N*N크기 땅
  원소 내용 - 인구의 수
  나라 - 1*1
  인구차이 L명 이상 R명 이하 - 국경선 염
  다 열리면 인구이동 시작
  인접한 칸을 통해서만 이동 - 연합
  연합 각칸 인구수 - 연합 인구수/연합 칸 개수
  큐 사용해서 BFS -> 연합들 벡터로 완성
  거리 계산 - 중복안하기 위해서 bool 필요 -> 해당 거리를 하나씩 보고 연합 뭉치기 -> 연합끼리 계산해서 거리 업데이트 
*/
const int MAX =  101;
vector<vector<int>> map(MAX,vector <int>(MAX,0)); //0 과 짝수 나라 사이에 있는 좌표 - 나라사이 거리
stack<tuple<int,int,int>> unions[2500];//갖고 있는 인구 +좌표 연합 생성 됐으면 임시로 저장 자료구조
bool cities[51][51][51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool chk_boundary(int a,int N)
{
  //0과 N-1 사이 쳌
  if(a>=0 && a<N)
    return true;
  return false;
}
bool calc(int N,int L,int R)
{
  //거리 체크하고 없으면 return - while
  //거리 계산 위해 두번 들를 수 도 있음
  bool result = false;
  queue <pair<int,int>> q;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          for(int k=0;k<N;k++)
            {
              for(int p=0;p<N;p++)
                {
                  cities[i][j][k][p] = false;
                }
            }
        }
    }
  q.push(make_pair(0,0));
  int union_number = 0;
  unions[union_number].push(make_tuple(map[0][0],0,0));
  while(!q.empty())
    {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      int way_dist = get<0>(unions[union_number].top());
      int way_x = get<1>(unions[union_number].top());
      int way_y = get<2>(unions[union_number].top());
      for(int i=0;i<4;i++)
        {
          int mov_x = x+dx[i];
          int mov_y = y+dy[i];
          if(chk_boundary(mov_x,N) && chk_boundary(mov_y,N) && cities[x][y][mov_x][mov_y] == false) //바운더리에 있고 안가봄
          {
            cities[x][y][mov_x][mov_y] = true; //가봤다 표시
            cities[mov_x][mov_y][x][y] = true;
            int dif_dist = abs(map[x][y] - map[mov_x][mov_y]);//거리 계산
            if(dif_dist>=L && dif_dist<=R)
            {
              //거리가 범위 안에 있고 이전에 연합과 연결
              
              if(way_x == x && way_y == y)
              {
                way_dist += map[mov_x][mov_y];
                unions[union_number].push(make_tuple(way_dist, mov_x,mov_y));
              }
              else{
                union_number++;
                unions[union_number].push(make_tuple(map[mov_x][mov_y], mov_x,mov_y));
              }
              
              //연합 정보 필요
            result = true;              
            }
            q.push(make_pair(mov_x,mov_y));
          }
        }
      
    }
  if(result)
  {
  for(int i=0;i<union_number+1;i++)
    {
      int way_dist = get<0>(unions[i].top());
      int city_num = unions[i].size();
      while(!unions[i].empty())
        {
          int x = get<1>(unions[i].top());
          int y = get<2>(unions[i].top());
          unions[i].pop();
          map[x][y] = way_dist/city_num;
        }
      
    }
  }
  return result;
}
int main() {
  int N,L,R;
  cin>>N>>L>>R;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cin>>map[(i)][(j)];
        }
    }
  int result = 0;
  while(calc(N,L,R))
    {
      result+=1;
    }
  cout<<result<<endl;
  //calc_dist(N);
  //cout<<calc(N,L,R)<<endl;
}