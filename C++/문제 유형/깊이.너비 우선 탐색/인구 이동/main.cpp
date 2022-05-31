#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>
#include <stack>
#include <algorithm>
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
  갈 수 있을 때만 BFS - 벡터에 저장
  모두다 들를때까지 시행
*/
const int MAX =  51;
vector<vector<int>> map(MAX,vector <int>(MAX,0)); 
vector<vector<int>> unions(MAX, vector<int>(MAX,-1));
vector<tuple<int,int,int>> union_info[2501];
int N,L,R;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool chk_boundary(int a,int N)
{
  //0과 N-1 사이 쳌
  if(a>=0 && a<N)
    return true;
  return false;
}
void calc(int x,int y, int index)
{
  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  unions[x][y] = index;
  union_info[index].push_back(make_tuple(map[x][y],x,y));
  while(!q.empty())
    {
      int tmp_x = q.front().first;
      int tmp_y = q.front().second;
      q.pop();      
      for(int i=0;i<4;i++)
        {
          //0,0 - 0,1 , 1,0
          //1,0 - 0,0 1,1 2,0 1,-1
          int mov_x = tmp_x+dx[i];
          int mov_y = tmp_y+dy[i];
          if(chk_boundary(mov_x,N) && chk_boundary(mov_y,N) && unions[mov_x][mov_y] == -1)
          {//바운더리 내부
            int diff = abs(map[tmp_x][tmp_y] - map[mov_x][mov_y]);
            //cout<<endl<<map[x][y]<<' '<<map[mov_x][mov_y]<<endl<<endl;
            //cout<<endl<<"차이"<<diff<<endl<<tmp_x<<' '<<tmp_y<<' '<<mov_x<<' '<<mov_y<<endl;
            if(diff>=L && diff<=R)
            {
              
              unions[mov_x][mov_y] = index;
              union_info[index].push_back(make_tuple(map[mov_x][mov_y],mov_x,mov_y));
               q.push(make_pair(mov_x,mov_y));
            }
           
          }
        }
    }
}
int main()
{
  int result = 0;
  cin>>N>>L>>R;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cin>>map[i][j];
        }
    }
  while(true)
    {
      for(int i=0;i<2501;i++)
        union_info[i].clear();
      int index = 0;
      for(int i=0;i<N;i++)
        {
        for(int j=0;j<N;j++)
          {
          unions[i][j] = -1;
          }
        }
      for(int i=0;i<N;i++)
        {
          for(int j=0;j<N;j++)
            {
              //cout<<map[i][j]<<' ';
              if(unions[i][j] == -1)
              {
                calc(i,j,index);
                index+=1;
              }
            }
        }
        if(index == N*N)
        {
          break;
        }
        else
        {
          result +=1;
          for(int i=0;i<index;i++)
            {
              int size = union_info[i].size();
              if(size>=2)
              {
                int sum = 0;
                for(int j=0;j<size;j++)
                  {
                    sum+=get<0>(union_info[i][j]);
                  }
                for(int j=0;j<size;j++)
                  {
                    int tmp_x = get<1>(union_info[i][j]);
                    int tmp_y = get<2>(union_info[i][j]);
                    map[tmp_x][tmp_y] = sum/size;
                  }
              }
            }
        }
    }
  cout<<result<<endl;
  //거리 L이상 R이하는 연합으로
}