#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

//bool arr[100001][100001] = {0,};
struct info{
long long a;
long long b;
};
bool operator <(info x,info y)
{
  //가장 짧은거부터 하기
  long long x_time = x.b-x.a;
  long long y_time = y.b-y.a;
  if(x_time>y_time)
    return true;
  return false;
}

//불가능 시작시간을 갱신
//bool alreadyed[2147649] = {0,};
const long long INF = 2147483649;
long long end_impossible_time = -INF;
long long start_impossible_time = INF;
int n,m;
int main() {
  cin>>n;
  priority_queue<info, vector<info>>pq;
  for(int i=0;i<n;i++)
    {
      long long a,b;
      cin>>a>>b;
      pq.push({a,b});
    }
    int cnt = 0;
    while(!pq.empty())
      {
        info good = pq.top();
        
        pq.pop();
        long long start,end;
        start = good.a;
        end = good.b;
        if(end_impossible_time == -INF && start_impossible_time == INF)
        {
          end_impossible_time = end;
          start_impossible_time =start;
          cnt++;
        }
        else if(start<= start_impossible_time && end<=start_impossible_time)
        {
          start_impossible_time = start;
          cnt++;
        }
        else if(start>=end_impossible_time)
        {
          end_impossible_time = end;
          cnt++;
        }
      }
      cout<<cnt;

  
}