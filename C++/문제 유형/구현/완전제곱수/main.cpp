#include <iostream>
#include <cmath>
using namespace std;
void calc(int M,int N)
{
  int first = (int)(sqrt(M))+1;
  if(((first-1) * (first-1)) == M)
    first -=1;
    
  int last = (int)(sqrt(N));
  if(((last) * (last)) > N)
    last -=1;
  int result = 0;
  for(int i=first;i<=last;i++)
    result+= (i*i);
  if(result==0)
  {
    cout<<-1<<endl;
    return;
  }
  cout<<result<<endl;
  cout<<(first*first)<<endl;
}
int main() {
  int N,M;
  cin>>M>>N;
  calc(M,N);
}