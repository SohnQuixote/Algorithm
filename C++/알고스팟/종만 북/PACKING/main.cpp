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
int volume[100],need[100];
int cache[1001][100];
string name[100];

int pack(int cap,int idx)
{
  if(idx == N) return 0;
  int &ret = cache[cap][idx];
  if(ret != -1) return ret;
  ret = pack(cap,idx+1);
  if(cap>=volume[idx])
  {
    ret = max(ret, pack(cap-volume[idx] , idx+1) + need[idx]);

    
  }
  return ret;

  
}
//와우....
void reconst(int capa,int idx,vector<string> &lst)
{
  if(idx == N) return;
  if(pack(capa,idx) == pack(capa,idx+1))
  {
    reconst(capa,idx+1,lst);
  }
  else{
    lst.push_back(name[idx]);
    reconst(capa-volume[idx],idx+1,lst);
  }

  
}


int main() {
  cin>>C;

  
  for(int tc=0;tc<C;tc++)
    {
      cin>>N>>W;
      memset(cache,-1,sizeof(cache));
      for(int i=0;i<N;i++)
        {
          cin>>name[i]>>volume[i]>>need[i];
          
        }
      vector<string>lsts;
      reconst(W,0,lsts);
      cout<<pack(W,0)<<' '<<lsts.size()<<'\n';
      for(int i=0;i<lsts.size();i++)
        {
          cout<<lsts[i]<<'\n';
        }



      
    }
}