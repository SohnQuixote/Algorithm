#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
  평행사변형

*/
const double MAX = 0.000000001;
double calc_dist(pair<int,int> a, pair<int,int>b)
{
  return sqrt((a.first - b.first) * (a.first-b.first) + (a.second-b.second) * (a.second - b.second));
}
bool chk_possible(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
  if(a.first == b.first && b.first == c.first)
    return false;
  else if(a.second == b.second && b.second == c.second)
    return false;
  //x축 평행 or y축 평행
  double gioolgi;
  if(a.first != b.first)
    gioolgi = static_cast<double>(a.second - b.second)/static_cast<double>(a.first - b.first);
  else
    gioolgi = static_cast<double>(b.second - c.second)/static_cast<double>(b.first - c.first);
  double julpyeon = static_cast<double>(a.second) - static_cast<double>(gioolgi * a.first);
  if(abs((static_cast<double>((gioolgi*c.first)+julpyeon)) - c.second)< MAX)
  {
    return false;
  }
  return true;
}
int main() {
  //std::cout << "Hello World!\n";
  double mini = 987654321;
  double maxi = -1;
  pair<int,int> a;
  pair<int,int> b;
  pair<int,int> c;

 cout.precision(17); cin>>a.first>>a.second>>b.first>>b.second>> c.first>>c.second;
  if(!chk_possible(a,b,c))
  {
    cout<<-1<<endl;
    return 0;
    
  }
  double ab = calc_dist(a,b);
  double ac = calc_dist(a,c);
  double bc = calc_dist(b,c);
  //a-b a-c *2
  mini = min(mini, (ab+ac)*2);
  maxi = max(maxi , (ab+ac) *2);
  //b-a b-c *2
  mini = min(mini,(ab+bc)*2);
  maxi = max(maxi,(ab+bc)*2);
  //c-a c-b *2
  mini = min(mini,(ac+bc)*2);
  maxi = max(maxi,(ac+bc)*2);
  cout<<(maxi-mini)<<endl;
}