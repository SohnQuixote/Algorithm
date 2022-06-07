#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  사다리 조작
  N개 세로선
  M개 가로선 
  브루트포스 알고리즘
  i번 결과 i번
  추가 해야하는 가로선 개수 최솟값
  정답이 3보다 크거나 불가능 하면 -1
  불가능 테스트케이스(이미 가로선 다 놓임)
  모두 다 놓지 말고 결과에 영향 주는 사다리만 놓기
  같은 결과 주는 구간을 구해야함
*/
//i에서 i+1 연결 ->
int N,M,H;
const int INF = 987654321;
vector<pair<int,int>> ladder_range(vector<vector<int>> ladder, int down)
{
  vector<pair<int,int>> result;
  vector<int> tmp;
  int first  =0;
  //tmp.push_back(-1);
  for(int a = 0;a<H;a++)
    {
      if((down-1)>= 0 && ladder[a][down-1]==1)
      {
        tmp.push_back(a);
      }
      else if(ladder[a][down] == 1)
      {
        tmp.push_back(a);
      }
      else if((down+1) < N-1 && ladder[a][down+1] == 1)
      {
        tmp.push_back(a);
      }
      
    }
    if(tmp.size() == 0)
    {
      result.push_back(make_pair(0,H));
      return result;
    }
    if(tmp.size() == 1)
    {
      if(tmp[0] != 0)
        result.push_back(make_pair(0,tmp[0]));
      if(tmp[0] != H-1)
        result.push_back(make_pair(tmp[0],H));
      return result;
    }
    //tmp.push_back(H-1);
    if(tmp[0] != 0)
    {
      result.push_back(make_pair(0,tmp[0]));
    }
    for(int i=1;i<tmp.size();i++)
      {
        if((tmp[i] - tmp[i-1]) >=2)
        {
          result.push_back(make_pair(tmp[i-1],tmp[i]));
        }
        
      }
    if(tmp[tmp.size()-1] != H-1)
    {
      result.push_back(make_pair(tmp[tmp.size()-1] , H));
    }
  return result;
}
inline bool chk_ladders(vector<vector<int>> ladder)
{
  bool result =true;
  //vector<pair<int,int>>p;
  for(int i=0;i<N;i++)
    {
      int down = i;
      for(int j = 0;j<H;j++)
        {
          if((down-1) >=0 && ladder[j][down-1])
          {
            down = down-1; 
          }
          else if((down) < N && ladder[j][down])
          {
            down = down+1;     
          }
          
        }
      //p.push_back(make_pair(i,down));
      if(i!=down)
        return false;
      
    }
  /*for(int i=0;i<p.size();i++)
    {
      cout<<p[i].first<<' '<<p[i].second<<endl;
    }*/
  return true;
}
inline bool chk_place(vector<vector<int>> ladder, int h,int d)
{
  bool result =true;
  if((d-1)>=0)
  {
    if(ladder[h][d-1])
      return false;
  }
  if((d+1) <N)
  {
    if(ladder[h][d+1])
      return false;  
  }
  return result;
}
int calc(vector<vector<int>> ladder, int number)
{
  vector<pair<int,int>> range;
  int result =INF;
  if(number >3)
    return result;
  if(chk_ladders(ladder))
    return number;
  for(int i=0;i<N-1;i++)
    {
      range = ladder_range(ladder,i);
      for(int k = 0;k<range.size();k++)
        {
          int height = (range[k].second + range[k].first)/2;
          //안되면 마지막 부분 
          ladder[height][i] = 1;
          result = min(result,calc(ladder,number+1));
          ladder[height][i] = 0;
          
        }
      
    }
  return result;
}
int main() {

cin>>N>>M>>H;

vector<vector<int>> ladder(30,vector<int>(9,0));
  for(int i=0;i<M;i++)
    {
      int a,b;
      cin>>a>>b;
      ladder[a-1][b-1] = 1; //b-1과 b연결

      
    }
  if(chk_ladders(ladder))
  {
    cout<<0<<endl;
    return 0;
  }
  if(M== (N-1) *H)
  {
    cout<<-1<<endl;
    return 0;
  }


  int chk = calc(ladder, 0);
  if(chk>3)
    cout<<-1<<endl;
  else
    cout<<chk<<endl;
}