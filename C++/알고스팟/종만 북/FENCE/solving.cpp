#include <iostream>
#include <vector>
using namespace std;
/*
  FENCE

*/
vector<int> arr(20000,0);
int C;
int N;
int rect(int s,int e)
{
  int min_height = 987654321;
  for(int i=s;i<e;i++)
    {
      min_height = min(min_height , arr[i]);
    }


  return (min_height * (e-s));
  
}


int find(int start, int end)
{
  if(start>end)
    return 0;
  int result = 0;
  int mid = (start+end)/2;
  result = max(find(start,mid),find( mid,end));
  result = max(result ,rect(start,end));
  //해당 넓이
  //+ 가운데 걸친 넓이도
  
  return result;
}
int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>N;
      for(int i=0;i<N;i++)
        cin>>arr[i];
      cout<<find(0,N);
      


      
    }

}