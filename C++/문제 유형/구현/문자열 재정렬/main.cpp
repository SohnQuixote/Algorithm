#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
  문자열 재정렬
  모든 알파벳 오름차순 이어서 출력
  모든 숫자 더한 값 이어서 출력
*/
int main() {
  string S;
  cin>>S;
  int number = 0;
  string alphabets;
  //vector<string> results;
  int size = S.size();
  for(int i=0;i<size;i++)
    {
      if(S[i]>='0' && S[i] <='9')
      {
       number += (S[i] - '0'); 
      }
      else{
        alphabets.push_back(S[i]);
      }
    }
  sort(alphabets.begin(), alphabets.end());
  for(int i=0;i<alphabets.size();i++)
    cout<<alphabets[i];
  cout<<number<<endl;
}