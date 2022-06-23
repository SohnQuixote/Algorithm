#include <iostream>
#include <vector>
#include <queue>
/*
  원판 돌리기
  반지름i 1~N 원판 크기 작아지는 순 바당게 놓임
  반지름i - i번째 원판
  각각 원판 M개 정수
  i번째 원판 j번째 수
  (i,j)
  (i,0) - (i,1) , (i,M-1) 인접
  (i,M) - (i,M-1),(i,1)
  인접
  시계 방향 -1 %
  반시계 방향 +1 %
  총 T번 회전
  xi(번호 xi배수 원판) ,di(0시계 1반시계) , ki(회전하는 칸)
  회전 뒤 원판에 수 있으면
  인접하면서 수가 같은것을 찾음
  1. 있을 경우 다 지움
  2. 없을 경우 - 평균 초과 -1 미만 +1
  회전 뒤 원판 합
*/
using namespace std;
const int IMPOSSIBLE = -1;
int N,M;
vector<vector<int>>circles(51,vector<int>(51,0));
void print_circles()
{
  cout<<endl<<"printing::"<<endl;
  for(int i=1;i<=N;i++)
    {
      cout<<endl<<i<<"th circle::"<<endl;
      for(int j=0;j<M;j++)
        {
          cout<<circles[i][j]<<' ';
        }
      
    }
  
}
int accum()
{
  int result = 0;
  for(int i=1;i<=N;i++)
    {
      for(int j=0;j<M;j++)
        {
          if(circles[i][j] != IMPOSSIBLE)
            result+=circles[i][j];
          
        }
    }
  return result;
}
int dist(int a, int b)
{
  if((a+b)<0)
    return (a+b+M);
  return (a+b) % M;  
}
void rmve(int a, int b, int c, int d)
{
  circles[a][b] = IMPOSSIBLE;
  circles[c][d] = IMPOSSIBLE;
}
void near()
{
  bool exist = false;
  //dfs 사용
  vector<vector<bool>>chk(N+1,vector<bool>(M,false));
  for(int i=1;i<=N;i++)
    {
      for(int j=0;j<M;j++)
        {
          vector<pair<int,int>> rmv;
          queue<pair<int,int>>q;
          if(circles[i][j] != IMPOSSIBLE && !chk[i][j])
          {
            rmv.push_back(make_pair(i,j));
            q.push(make_pair(i,j));
            chk[i][j] = true;
            while(!q.empty())
              {
                pair<int,int> pos = q.front();
                int x = pos.first;
                int y = pos.second;
                q.pop();
                
                int mov_x = x;
                int mov_y = dist(y,1);
                if(chk[mov_x][mov_y] == false && circles[mov_x][mov_y] == circles[x][y])
                {
                  q.push(make_pair(mov_x,mov_y));
                  rmv.push_back(make_pair(mov_x,mov_y));
                  chk[mov_x][mov_y] = true;
                  exist = true;
                }
                mov_y = dist(y,-1);
                if(chk[mov_x][mov_y] == false && circles[mov_x][mov_y] == circles[x][y])
                {
                  q.push(make_pair(mov_x,mov_y));
                  rmv.push_back(make_pair(mov_x,mov_y));
                  chk[mov_x][mov_y] = true;
                  exist = true;
                }
                if(x>=1 && x<N)
                {
                  mov_x = x+1;
                  mov_y = y;
                  if(chk[mov_x][mov_y] == false && circles[mov_x][mov_y] == circles[x][y])
                {
                  q.push(make_pair(mov_x,mov_y));
                  rmv.push_back(make_pair(mov_x,mov_y));
                  chk[mov_x][mov_y] = true;
                  exist = true;
                }
                  
                }
                if(x>1 &&x <= N)
                {
                  mov_x = x-1;
                  mov_y = y;
                  if(chk[mov_x][mov_y] == false && circles[mov_x][mov_y] == circles[x][y])
                {
                  q.push(make_pair(mov_x,mov_y));
                  rmv.push_back(make_pair(mov_x,mov_y));
                  chk[mov_x][mov_y] = true;
                  exist = true;
                }
                  
                }
              }
            if(rmv.size()>1)
            {
              for(int k=0;k<rmv.size();k++)
                {
                  int x = rmv[k].first;
                  int y = rmv[k].second;
                  circles[x][y] = IMPOSSIBLE;
                  
                }
              
            }
            
          }
        }
    }
  if(!exist)
  {
    int h= 0;
    int ac = 0;
    for(int i=1;i<=N;i++)
      {
        for(int j=0;j<M;j++)
          {
            if(circles[i][j] != IMPOSSIBLE)
            {
              ac+= circles[i][j];
              h++;
            }
            
          }
      }
    //cout<<ac<<' '<<h<<endl;
    if(h!=0)
    {
    int rem = ac%h;
    ac/=h;
    
    for(int i=1;i<=N;i++)
      {
        for(int j=0;j<M;j++)
          {
            if(circles[i][j] != IMPOSSIBLE )
            {
              if(rem!= 0)
              {
                if(circles[i][j]<=ac)
                  circles[i][j]++;
                else
                  circles[i][j]--;
              }
              else if(rem == 0)
              {
                if(circles[i][j]<ac)
                  circles[i][j]++;
                else if(circles[i][j]>ac)
                  circles[i][j]--;
              }
            }
            
          }
      }

    
    }
  }
}

void spin(int a,int r, int d)
{
  //시계 -1 반시계 +1
  if(r==1)
    d*=-1;
  vector<int>tmp = circles[a];
  for(int i=0;i<M;i++)
    {
      int index = dist(i,d);
      tmp[index] = circles[a][i];
      
    }
  circles[a] = tmp;
}

int main() 
{
  int T;
  cin>>N>>M>>T;
  for(int i=1;i<=N;i++)
    {
    for(int j=0;j<M;j++)
      {
        cin>>circles[i][j];
        //i번째 원의 j번째 숫자
      }
    }
  //print_circles();
  for(int i=0;i<T;i++)
    {
      int x,d,k;
      cin>>x>>d>>k;
      for(int j=x;j<=N;j+=x)
        {
          spin(j,d,k);
          
          
        }
      //print_circles();
      near();
      //print_circles();
    }
  cout<<accum()<<endl;
}