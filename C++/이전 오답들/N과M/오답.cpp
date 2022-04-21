/*
  N과M
  1부터 N까지 중복없이 M개를 고른 수열
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  vector <int> array;  
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;i++)
    {
      array.push_back(i+1);
    }
  do{
    int i=0;

        for(auto it = array.begin();it != array.end(); it++ )
          {
            cout<<*it<<' ';
            ++i;
            if(i>M-1)
              break;
          }
        cout<<endl;

    
  } while(next_permutation(array.begin(),array.end()));
}