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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  //하이퍼 드라이브로 연결된 곳 전부 다 연결
  int k;
  cin>>n>>k>>m;
  for(int i=1;i<=m;i++)
    {
      for(int j=0;j<k;j++)
        {
          int tmp;
          cin>>tmp;
          arr[i].push_back(tmp);
          stations[tmp].push_back(i);
        }
        //전부 다 연결
      

      
    }
    q.push(1);
    visited[1] = 1;
    dist[1] = 1;
    while(!q.empty())
      {
        int now = q.front();
        q.pop();
        for(int i=0;i<stations[now].size();i++)
          {
            int next_hyper = stations[now][i];
            for(int j=0;j<arr[next_hyper].size();j++)
              {
                int next_station  =arr[next_hyper][j];
                if(!visited[next_station])
                {
                  visited[next_station] = 1;
                  dist[next_station] = dist[now] +1;
                  q.push(next_station);
                }
                
              }
            
          }

        
      }
      if(dist[n])
        cout<<dist[n];
      else
        cout<<-1;
  
}