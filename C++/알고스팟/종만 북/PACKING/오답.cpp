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
info caches[1000];


static bool operator < (info a, info b)
{
  if(a.urg<b.urg)
    return true;
  return false;
  
}
//연산자 오버로딩을 통해 가장 절박도가 큰 것을 리턴할 수 있음
info calc(int idx,int volume)
{
  if(volume<0 || idx>=N)
    return {0,0,""};

  
  info &ret = caches[volume];//해당 볼륨의 절박도
  if(ret.urg || volume ==0) return ret;
  if( (volume- informations[idx].vol) >=0)
  {
    info tmp= calc(idx+1,volume - informations[idx].vol);
    tmp.urg += informations[idx].urg;
    tmp.name += informations[idx].name;
    tmp.name += "\n";
    info tmp_2 = calc(idx+1,volume);
    
    tmp = max(tmp,tmp_2);
    ret = max(ret,tmp);
  }
  

  return ret;  
}

int main() {
  cin>>C;

  
  for(int tc=0;tc<C;tc++)
    {
      for(int idx=0;idx<W;idx++)
        {
          caches[idx].urg = 0;
          caches[idx].vol = 0;
          caches[idx].name = "";  
        }
      cin>>N>>W;
      for(int i=0;i<N;i++)
        {
          //cin>>names[i]>>vol[i]>>urg[i];
          cin>>informations[i].name>>informations[i].vol>>informations[i].urg;
        }
        info ret = calc(0,W);
        cout<<ret.urg<<'\n';
        cout<<ret.name;
        



      
    }
}