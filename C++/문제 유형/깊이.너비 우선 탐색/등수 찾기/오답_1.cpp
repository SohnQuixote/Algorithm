#include <iostream>
#include <vector>
using namespace std;
int n,m,x;
//정방향 그래프, 반대방향 그래프
vector<int> graphs[2][100000];
int highest = 0,lowest = 0;
int visited[100000] = {0,};
void find_lowest(int now)
{
  if(graphs[0][now].size() ==0)
  {
    return;
  }
  for(int i=0;i<graphs[0][now].size();i++)
    {
      if(!visited[graphs[0][now][i]])
      {
        visited[graphs[0][now][i]] = 1;
        lowest++;
        find_lowest(graphs[0][now][i]);
        
      }
      
    }
  
}
void find_highest(int now)
{
  if(graphs[1][now].size() == 0)
  {
    return;
  }
    for(int i=0;i<graphs[1][now].size();i++)
    {
      if(!visited[graphs[1][now][i]])
      {
        visited[graphs[1][now][i]] = 1;
        highest++;
        find_lowest(graphs[1][now][i]);
        
      }
      
    }

  
}


int main() {
    cin>>n>>m>>x;
    for(int i=0;i<m;i++)
      {
        int high,low;
        cin>>high>>low;
        graphs[0][high].push_back(low);
        graphs[1][low].push_back(high);
      }
  //순환그래프 아님
  find_highest(x);
  for(int i=0;i<n;i++)
    visited[i] = 0;
  find_lowest(x);
  cout<<highest+1<<' ';
  cout<<n-lowest<<endl;
  // low->high 멤버수 + 1  가능한 가장 높은 등수
  //인원수 - high-> low => 가능한 가장 낮은 등수
}