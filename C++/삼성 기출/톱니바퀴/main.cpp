#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
  톱니바퀴
  N = 0
  S = 1
  1번 톱니바퀴의 [0]이 1이면 0점, 0이면 1점
  2번 톱니바퀴의 [0]이 1이면 0점, 0이면 2점
  3번 톱니바퀴의 [0]이 1이면 0점, 0이면 4점
  4번 톱니바퀴의 [0]이 1이면 0점, 0이면 8점
*/

vector<vector<int>> gears(4,vector<int>(8,0));
vector<pair<int,int>> commands;
//first 회전 톱니바퀴 번호 second - 회전 방향 1 시계 -1 반시계
//2번과 6번으로 회전 여부 결정
int mod_eight(int a)
{
  if(a<0)
    return a+8;
  else
    return a%8;
}
void rotating_clock(int C, int R)
{
  vector<int> tmp = gears[C];
  if(R==1)
  {
    for(int i=0;i<8;i++)
    {
      gears[C][mod_eight(i+1)] = tmp[i];
    }
  }
  else
  {
    for(int i=0;i<8;i++)
    {
      gears[C][mod_eight(i-1)] = tmp[i];
    }
    
  }
}
int other_rot(int a)
{
  if(a == 1)
    return -1;
  else
    return 1;
}
void rotate(int K)
{
  for(int i=0;i<K;i++)
    {
      int gear = commands[i].first;
      int rot = commands[i].second;
      vector<pair<int,int>> rotating_gears;
      //경우의 수 적어서 그냥 하나씩 고려
      rotating_gears.push_back(make_pair(gear,rot));
      if(gear == 0)
      {
        if(gears[0][2] != gears[1][6])
        {
          rot = other_rot(rot);
          rotating_gears.push_back(make_pair(1,rot));
          if(gears[1][2] != gears[2][6])
          {
            rot = other_rot(rot);
            rotating_gears.push_back(make_pair(2,rot));
            if(gears[2][2] != gears[3][6])
            {
              rot = other_rot(rot);
              rotating_gears.push_back(make_pair(3,rot));
            }
          }
        }
        
      }
      else if(gear == 1)
      {
        if(gears[1][6] != gears[0][2])
        {
          int o_rot = other_rot(rot);
          rotating_gears.push_back(make_pair(0,o_rot));
        }
        if(gears[1][2] != gears[2][6])
        {
          rot = other_rot(rot);
          rotating_gears.push_back(make_pair(2,rot));
          if(gears[2][2] != gears[3][6])
          {
            rot = other_rot(rot);
            rotating_gears.push_back(make_pair(3,rot));
          }
        }
        
      }
      else if(gear == 2)
      {
        if(gears[2][2] != gears[3][6])
        {
          int o_rot = other_rot(rot);
          rotating_gears.push_back(make_pair(3,o_rot));
        }
        if(gears[2][6] != gears[1][2])
        {
          rot = other_rot(rot);
          rotating_gears.push_back(make_pair(1,rot));
          if(gears[1][6] != gears[0][2])
          {
            rot = other_rot(rot);
            rotating_gears.push_back(make_pair(0,rot));
          }
          
        }
      }
      else
      {
        if(gears[3][6] != gears[2][2])
        {
          rot = other_rot(rot);
          rotating_gears.push_back(make_pair(2,rot));
          if(gears[2][6] != gears[1][2])
          {
            rot = other_rot(rot);
            rotating_gears.push_back(make_pair(1,rot));
            if(gears[1][6] != gears[0][2])
            {
              rot = other_rot(rot);
              rotating_gears.push_back(make_pair(0,rot));
            }
          }
        }
      }
      for(int t = 0;t<rotating_gears.size();t++)
        {
          int gear = rotating_gears[t].first;
          int rot = rotating_gears[t].second;
          rotating_clock(gear,rot);
          
        }
    }
}
int main() {
  int result = 0;
  int K;
  for(int i=0;i<4;i++)
    {
      string tmp;
      getline(cin,tmp);
      for(int j=0;j<8;j++)
        {
          gears[i][j] = (tmp[j] == '1');
          //cin>>gears[i][j];
        }
    }
  cin>>K;
  for(int i=0;i<K;i++)
    {
      int gear,rot;
      cin>>gear>>rot;
      commands.push_back(make_pair(gear-1,rot));
    }
  rotate(K);
  result += (gears[0][0] == 1);
  result += 2 *(gears[1][0] == 1);
  result += 4 *(gears[2][0] == 1);
  result += 8 *(gears[3][0] == 1);
  cout<<result<<endl;
}