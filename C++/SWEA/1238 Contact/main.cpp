#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
  contact
  연락 받은 마지막 사람 
*/
int connect(vector<vector<bool>> connection, int start)
{
  queue<pair<int,int>>q;
  int result = start;
  vector<bool>visited(101,false);
  int total_ma = 0;
  vector<pair<int,int>>log;
  visited[start] = true;
  for(int i=1;i<101;i++)
    {
      if(connection[start][i])
      {
        q.push(make_pair(i,0));
        
      }
    }
  while(!q.empty())
    {
      int people = q.front().first;
      int how_ma = q.front().second;
      log.push_back(make_pair(people,how_ma));
      total_ma = max(total_ma, how_ma);
      q.pop();
      for(int p=1;p<101;p++)
        {
          if(connection[people][p] && !visited[p])
          {
            visited[p] = true;
            q.push(make_pair(p,how_ma+1));
          }
          
        }
      
    }
  vector<int>chosen;
  for(int i=0;i<log.size();i++)
    {
      if(log[i].second == total_ma)
      {
        chosen.push_back(log[i].first);
      }

      
    }
  result = *max_element(chosen.begin(),chosen.end());
  return result;
}
int main() {
  for(int i=0;i<10;i++)
    {
      vector<vector<bool>> connection(101,vector<bool>(101,false));
      int c_num,start;
      cin>>c_num>>start;
      for(int j=0;j<c_num/2;j++)
        {
          int a,b;
          cin>>a>>b;
          connection[a][b] = true;
        }
      cout<<"#"<<i+1<<' '<<connect(connection,start)<<endl;
      
    }
  
}