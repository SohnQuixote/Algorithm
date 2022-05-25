#include <iostream>
#include <vector>
using namespace std;
/*
  탑승구
  공항 G개 탑승구
  P개 비행기 차례대로 도착
  1부터 비행기 입력받은 값 탑승구까지 영구적으로 도킹
  최대한 많은 비행기 도킹하려함
  최대 몇대 출력
  서로소 집합?
  그냥 배열두고 그리디하게 해결 불가능? -> 가능해 보임
  그리디 한번 구현
*/
const int MAX = 100001;
int exits[MAX] = {0,};
int main() {
  int G,P; 
  cin>>G>>P;
  vector<int> plane;
  for(int i=0;i<P;i++)
    {
      int temp;
      cin>>temp;
      plane.push_back(temp);
    }
  int result = 0;
  bool flag = false;
  for(int i=0;i<P && !flag;i++)
    {
      int max = plane[i];
      //cout<<max<<' '<<exits[max]<<endl;
      //cout<<endl<<endl;
      for(int j = max;j>=0;j--)
        {
          //cout<<j<<' '<<exits[plane[j]]<<endl;
          if(j == 0)
          {
            flag = true;
            break;
            
          }
          if(exits[j] == 0)
          {
            //cout<<j<<endl;
            exits[j] =1;
            result++;
            break;
          }
        }
      
    }
  cout<<result<<endl;
}