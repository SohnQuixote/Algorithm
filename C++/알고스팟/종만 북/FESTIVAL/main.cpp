#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  
  FESTIVAL
  L개 팀 이미 섭외
  N일간 대여 비용 
  L일 이상 연속 대여 하루 빌리는 평균 비용 최소화
  N일부터 연속 L일 선택 최소 평균
*/
double calc(vector<int> prices, int n, int l)
{
  //cout<<"calc"<<endl;
  double result = 987654321;
  for(int length = n;length>=l;length--)
    {
      for(int start = 0;start<=n-length;start++)
        {
          int sum = 0;
          for(int i=start;i<start+length;i++)
            {
              sum+= prices[i];

              
            }
          result = min(result, static_cast<double>(sum)/static_cast<double>(length));

          
        }

      
    }
  return result;
  
}
int main() {
  int c;
  cin>>c;
  vector<double>results;
  for(int i=0;i<c;i++)
    {
      int n,l;
      cin>>n>>l;
      vector<int>prices(n,0);
      for(int j=0;j<n;j++)
        cin>>prices[j];
      results.push_back(calc(prices,n,l));
      
    }
  cout.precision(7);  
  for(int i=0;i<c;i++)
    {
      printf("%.9f\n",results[i]);
      
    }
}