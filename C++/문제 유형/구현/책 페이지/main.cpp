#include <iostream>
using namespace std;
/*
  책 페이지
  그냥 하는것으로는 무조건 시간 초과
  효율적인 방법이 필요
  답안 참고
*/
long long jari[10];

void calc(long long n, long long t)
{
	while (n > 0) {
		jari[n % 10] += t;
		n /= 10;
    //해당 자리수를 더하기
	}
}



void solve(long long A, long long B, long long t) 
{
  //A를 0의 자리수로 B를 9의 자리수로
	while (A % 10 != 0 && A <= B)
	{
		calc(A, t);
		A++;
	}
	if (A > B) return;
	while (B % 10 != 9 && B >= A)
	{
		calc(B, t);
		B--;
	}
	long long cnt = (B / 10 - A / 10 + 1);
	for (int i = 0; i < 10; ++i)
		jari[i] += cnt * t;
	solve(A / 10, B / 10, t * 10);
}

int main()
{
	long long n;
	cin >> n;
	solve(1, n, 1);
	for (int i = 0; i < 10; ++i)
		cout << jari[i] << " ";
	return 0;
}