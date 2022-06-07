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

*/
//i에서 i+1 연결 ->
int N,M,H;
const int INF = 987654321;
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
  int result =INF;
  if(number >3)
    return result;
  if(chk_ladders(ladder))
    return number;
  for(int i=0;i<N-1;i++)
    {
      for(int j=0;j<H;j++)
        {
          if(!ladder[j][i] &&chk_place(ladder,j,i))
          {
            //양옆에 사다리 없으면
            ladder[j][i] = 1;
            result = min(result,calc(ladder,number+1));
            ladder[j][i] = 0;
          }
        }
      
    }
  return result;
}
int main() {

cin>>N>>M>>H;

vector<vector<int>> ladder(30,vector<int>(9,0));
  //vector<bool>ladder_placed(H,false);
  for(int i=0;i<M;i++)
    {
      int a,b;
      cin>>a>>b;
      //ladder_placed[a-1] = true;
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
  /*


  int chk = calc(ladder, 0);
  if(chk>3)
    cout<<-1<<endl;
  else
    cout<<chk<<endl;

  */
  //조합 사용?
  int number = 0;
  vector<int>comb((N-1) * H , 0);
  vector<vector<int>> orig_ladder = ladder;
  while(number<3)
    {
      comb[number] = 1;
      sort(comb.begin(),comb.end());
      do{
        ladder = orig_ladder;
        for(int i=0;i<(N-1) * H;i++)
          {
            if(comb[i] == 1)
            {
              int h = i/(N-1);
              int d = i%(N-1);
              if(chk_place(ladder,h,d))
              {
                ladder[h][d] = 1;
              }

              
            }
          }
          if(chk_ladders(ladder))
          {
            cout<<(number+1)<<endl;
            return 0;
          }
      }while(next_permutation(comb.begin(),comb.end()));
      number +=1;      
    }
  cout<<-1<<endl;
  //처음에 체크 사다리 내려가보기 or 사다리 전부 세팅
  
}