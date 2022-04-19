/*
상하좌우
공간의 크기 N (1<= N <= 100)
계획서 내용 (L,R,U,D)
도착 지점 좌표 (x,y)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
void calc(char* direction,int N)
{
  int X = 1,Y=1;
  int length = strlen(direction);
  //cout<<length<<endl;
  for (int i=0;i<length;i++)
    {
      if(direction[i] != ' ')
      {
        if(direction[i] == 'U')
        {
          if(Y!=1)
          {
            Y--;
          }
        }
        else if(direction[i] == 'L')
        {
          if(X!=1)
          {
            X--;
          }
        }
        else if (direction[i] == 'R')
        {
          if(X!=N)
          {
            X++;
          }
        }
        else if(direction[i] == 'D')
        {
          if(Y!=N)
          {
            Y++;
          }
        }
      }
    
    }
  cout<<Y<<' '<<X<<endl;
}
int main() {
  int N;
  char direction[100];
  cin>>N;
  cin.ignore(100,'\n');
  cin.getline(direction,100,'\n');
  calc(direction,N);
  //char *direction = new char[N];

  //calc(direction,N);
  //delete[] direction;
  
}