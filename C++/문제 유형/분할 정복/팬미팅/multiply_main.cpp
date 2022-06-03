#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

/*
  팬미팅
  M명 팬들 맨 오른쪽 멤버에서 한명씩 왼쪽 이동하며 포옹
  모든 팬 동시에 한명
  남성 멤버 -> 악수
  모든 멤버 동시 포옹 몇번
  브루트 포스 -> 직접 포옹 시뮬레이션 -> 비효율
  배열간 곰셈으로 구현
  팬수 20만
  최대 연산 횟수 20만
  여자 0
  남자 1
  
  허그 경우의 수 멤버 여자 (남자, 여자)/ 멤버 남자 (여자)
  and연산 0일 경우 안음    
  개선된 알고리즘
  - 카라츠바 알고리즘 사용
  21억 진수 곱하기 -> 해당 자리수 곱 -> 해당 위치에서 모든 팬 지나간 결과
*/
vector<int> members_vec;
vector<int> fans_vec;
bool all_hug(vector<int> tmp_members,int start,int members_num)
{  
  int hug = 0;
  for(int i=start;i<start+members_num;i++)
    {
      if((tmp_members[i] && fans_vec[i]) == 0)
      {
        hug+=1;
      }
    }
  if(hug == members_num)
    return true;
  else
    return false;
}
int calc()
{
  int result =0;
  int members_num = members_vec.size();
  int fans_num = fans_vec.size();
  
    for(int i=0;i<=fans_num - members_num;i++)
    {
      vector<int> tmp_members(fans_vec.size(),0);
      for(int j=0;j<members_num;j++)
        {
          tmp_members[i+j] = members_vec[j];
        }
      if(all_hug(tmp_members,i,members_num))
        result++;
    }
  return result;
}
//num[]의 자릿수를 올림을 처리한다.
void normalize(vector<int>& num) 
{
	num.push_back(0);

	//자릿수 올림을 처리한다.
	int size = num.size();
	for (int i = 0; i < size - 1; i++)
	{
		if (num[i] < 0)
		{
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	//앞에 남은 0을 제거한다.
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

//초등학교식 정수 곱셈
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);

	int aSize = a.size();
	int bSize = b.size();

	for (int i = 0; i < aSize; i++)
		for (int j = 0; j < bSize; j++)
			c[i + j] += a[i] * b[j];
	//normalize(c);
	return c;
}

//a += b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	int originalASize = a.size();
	if (a.size() < b.size() + k)
		a.resize(b.size() + k);
	a.push_back(0);

	int aSize = a.size();
	for (int i = originalASize; i < aSize; i++)
		a[i] = 0;

	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i + k] += b[i];

	normalize(a);
}

// a -= b
// a>= b인 경우에만 사용 가능하다.
void subFrom(vector<int>& a, const vector<int>& b)
{
	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i] -= b[i];
	normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();

	//a가 b보다 짧을 경우 둘을 바꾼다.
	if (an < bn)
		return karatsuba(b, a);
	//기저 사례 : a나 b가 비어있는 경우
	if (an == 0 || bn == 0)
		return vector<int>();
	//기저 사례 : a가 비교적 짧은 경우, O(n^2) 곱셈으로 변경한다.(성능을 위함)
	if (an <= 50)
		return multiply(a, b);
	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	//z2 = a1 * b1
	vector<int> z2 = karatsuba(a1, b1);

	//z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	
	//z1 = ((a0 + a1) * (b0 + b1)) - z0 - z2
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	//병합 과정
	//ret = z0+z1*10^half + z2 * 10(half*2)
	vector<int> ret(z2.size() + half * 2, 0);
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half * 2);
	return ret;
}
int hugs(const string& members, const string& fans)
{
  int N = members.size();
  int M = fans.size();
  vector<int> A(N),B(M);
  for(int i=0;i<N;i++) 
    A[i] = (members[i] == 'M');
  for(int i=0;i<M;i++)
    B[i] = (fans[M-1 - i] == 'M');
  vector<int>C = multiply(A,B);
  int all_hug = 0;
  for(int i = N-1;i<M;i++)
    {
      if(C[i] == 0)
        all_hug++;
      
    }
  return all_hug;
}
int main() {
  string members;
  string fans;
  getline(cin,members);
  getline(cin,fans);
  double start,end;
  start = clock();
  hugs(members,fans);
  end = clock();
  cout<<end-start<<endl;
  start = clock();
  for(int i=0;i<members.size();i++)
    {
      if(members[i] == 'F')
        members_vec.push_back(0);
      else
        members_vec.push_back(1);
    }
  for(int i=0;i<fans.size();i++)
    {
      if(fans[i] == 'F')
        fans_vec.push_back(0);
      else
        fans_vec.push_back(1);
    }

  
  calc();
  end= clock();
  cout<<end-start<<endl;
  //cout<<calc()<<endl;
  //cout<<hugs(members,fans)<<endl;
}