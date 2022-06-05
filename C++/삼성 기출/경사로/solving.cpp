#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
  경사로
  N*N맵 길 2N개
  길 갈수 있으려면 모두 같은 높이
  낮은칸 -> L개 바닥 접함
  낮은칸 높은칸 차이 1
  낮은칸 높이 같고 연속적 
  지나갈 수 있는 길 개수
  경사로 개수 무제한
  모든 길로 쭉 가다가 못가면 경사로 놓아보고 못놓으면 못감
*/
vector<vector<int>> map(100,vector<int>(100,0));
int walk(vector<int> r,int L)
{
  int walking_height = r[0];
  int distance = r.size();
  for(int i=1;i<distance;i++)
    {
      if(abs(walking_height - r[i]) > 1)
      {
        //경사로 못놓음
        return 0;
        
      }
        //낮은데 높은데 두개다 고려해야함
      else if((walking_height - r[i]) == -1)
      {
        for(int k=i;k<i+L;k++)
          {
            if(r[k] != r[i])
            {
              return 0;
              
            }
            
          }
          i+=L-1;
          walking_height = r[i];
      }
      else if((walking_height - r[i]) == 1)
      {
          for(int k=i-1;k>i-L;k--)
          {
            if(k<0 || r[k] != r[i])
            {
              return 0;
              
            }
            
          }
        
      }
      
    }
  return 1;
}
int main() {
  int result = 0;
  int N,L;
  cin>>N>>L;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cin>>map[i][j];
          
        }
      
    }
  for(int r= 0;r<N;r++)
    {
      vector<int>road;
      for(int c=0;c<N;c++)
        {
          road.push_back(map[r][c]);
          
        }
      result+=walk(road,L);
      
    }
  for(int c = 0;c<N;c++)
    {
      vector<int> road;
      for(int r=0;r<N;r++)
        {
          road.push_back(map[r][c]);
        }
      result+=walk(road,L);
    }
  cout<<result<<endl;
}