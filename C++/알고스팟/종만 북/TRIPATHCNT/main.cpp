#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <queue>
#include <string>
#include <map>
using namespace std;
/*
  TRIPATHCNT
  최대 경로의 수를 세는 프로그램
  맨 밑에 존재
  두개의 다른 동적 계획법 문제를 해결
  
*/
int C;
int n;
int arr[100][100];
int dx[2] = {1,1};
int dy[2] = {0,1};
int path_cache [100][100];
int count_cache[100][100];
int path(int x,int y)
{
  int &ret = path_cache[x][y];
  if(ret) return ret;
  if(x==n-1) return ret = arr[x][y];

  ret = arr[x][y];
  ret = max(ret+path(x+1,y) , ret+path(x+1,y+1));
  return ret;
  //잘나옴
}
int count(int x,int y)
{
  //여기서 점화식을 모르겠음
  int &ret = count_cache[x][y];
  if(ret)return ret;
  if(x==n-1) return ret = 1;
  //언제나 큰부분으로 향해야함
  if(path(x+1,y) >= path(x+1,y+1))
    ret+=count(x+1,y);
  if(path(x+1,y+1) >= path(x+1,y))
    ret+=count(x+1,y+1);
  return ret;


  


  
}



int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>n;
      memset(path_cache,0,sizeof(path_cache));
      memset(count_cache,0,sizeof(count_cache));
      for(int i=0;i<n;i++)
        for(int c=0;c<i+1;c++)
          cin>>arr[i][c];

      cout<<count(0,0)<<'\n';
    }
}