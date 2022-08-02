#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int m;
vector<int> arr[1001]; //하이퍼 튜브에서 역
vector<int> stations[100001]; //역에서 하이퍼튜브
int dist[200001] = {0,};
int visited[200001] = {0,};
queue<int>q;
int dx[3] = {1,-1,2};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  //하이퍼 드라이브로 연결된 곳 전부 다 연결
  int start, school;
  //int result = 987654321;
  cin>>start>>school;
  //바꾸면 안됨 x/2가 없음
  visited[start] = 1;
  q.push(start);
  if(school<=start)
  {
    cout<<abs(school-start);
    return 0;
  }
  while(!q.empty())
    {
      int now = q.front();
      //cout<<now<<endl;
      if(now == school)
      {
        cout<<dist[now];
        return 0;
      }
      q.pop();
        for(int d=0;d<3;d++)
        {
          int mov_x;
          if(d!=2)
          {
            mov_x = now+dx[d];
          }
          else
          {
            mov_x = now*dx[d];
          }
          //cout<<mov_x<<endl;
          if(mov_x>=0 )
          {
            if(!visited[mov_x] && mov_x <= 100000)
            {
              visited[mov_x] =1;
              dist[mov_x] = dist[now]+1;
              q.push(mov_x);
            }

            
          }

          


          
        }
        

      
    }
    //cout<<dist[10];
  
}