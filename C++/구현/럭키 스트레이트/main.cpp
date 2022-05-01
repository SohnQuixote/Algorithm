#include <iostream>
#include <string>
using namespace std;
/*
  럭키 스트레이트
  점수 N 점수 N반으로 나누어 같으면 가능  
*/
int main() {
  //std::cout << "Hello World!\n";
  string N;
  cin>>N;
  int left =0;
  int right =0;
	int size = N.size();
  for(int i=0;i<(size/2);i++)
    {
      left+= N[i] - '0';
    }
  for(int i=(size/2);i<size;i++)
    {
      right += N[i] - '0';
    }
  if(left == right)
    cout<<"LUCKY"<<endl;
  else
    cout<<"READY"<<endl;
}