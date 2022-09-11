#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
  PICNIC

*/
int main() {
  string sentence;
  getline(cin,sentence);
  int result = 0;
  //cout<<sentence;
  for(int i=0;i<sentence.size();i++)
    {
      if(sentence[i] != ' ')
      {
        result++;
        while(i<sentence.size()&&sentence[i] !=' ')
          {
            i++;
          }
      }
    }
    cout<<result;
}