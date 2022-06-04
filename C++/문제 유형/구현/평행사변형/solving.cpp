#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const double MAX = 0.0000000001;
/*
  평행사변형

*/
double calc_dist(pair<int,int> a, pair<int,int>b)
{
  return sqrt((a.first - b.first) * (a.first-b.first) + (a.second-b.second) * (a.second - b.second));
}
bool chk_possible(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
  double gioolgi = static_cast<double>(a.second - b.second)/static_cast<double>(a.first - b.first);
  double julpyeon = static_cast<double>(a.second) - static_cast<double>(gioolgi * a.first);
  cout<<gioolgi<<' '<<julpyeon<<endl;
  cout<<(gioolgi*c.first)+julpyeon<<endl;
  if ((abs((gioolgi*c.first)+julpyeon) - static_cast<double>(c.second)) <= MAX)
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

 cout.precision(16); cin>>a.first>>a.second>>b.first>>b.second>> c.first>>c.second;
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