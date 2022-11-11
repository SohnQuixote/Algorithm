#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
/*
  PACKING
  물건 부피/절박도 주어짐
  가져갈 수 있는 물건들의 부피의 합은 캐리어의 용량 w이하여야 함
  절박도를 최대화 하는 프로그램
*/
int C,N,W;

struct info{
  int vol;
  int urg;
  string name;
};
info informations[101];
vector <string> lists;




int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>N>>W;
      for(int i=0;i<N;i++)
        {
          //cin>>names[i]>>vol[i]>>urg[i];
          cin>>informations[i].name>>informations[i].vol>>informations[i].urg;
        }



      
    }
}