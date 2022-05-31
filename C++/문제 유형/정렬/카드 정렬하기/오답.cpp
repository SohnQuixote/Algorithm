#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  카드 정렬하기
  정렬된 두 묶음 숫자카드 각 묶음 카드 수 A,B -> 합치려면 A+B 비교 필요
  조합 사용? or 정렬해서 작은것 부터 합치면 효율적? - 맞음
  최소 비교 범위 - int 내에 존재 - 21억
*/
int main() {
  int N;
  cin>>N;
  vector<int> cont;
  for (int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      cont.push_back(temp);
    }
  sort(cont.begin(),cont.end());
  int result = 0;
  if(N==1)
  {
    cout<<cont[0]<<endl;
    return 0;
    //하나면 묶을 필요가 없음
  }
  int first_mook = cont[0]+cont[1];
  for(int i=2;i<cont.size();i++)
    {
      first_mook+=first_mook+cont[i];
      
    }
  cout<<first_mook<<endl;
}