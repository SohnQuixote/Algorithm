#include <iostream>
#include <bitset>
using namespace std;
/*
  FANMEETING

*/
int C;
bitset<200000> IDOL;
bitset <200000> FANS;
bitset<200000> result;
int counting(int i_size, int f_size)
{
	int cnt = 0;
	//겹치는 수는 
	int app = f_size - i_size + 1;
	//매번 쉬프트연산 사용
	for (int i = 0; i < app; i++)
	{

		result = IDOL & FANS;
		if (result.none())
			cnt++;
		FANS >>= 1;


	}
	return cnt;
}
int main() {
	cin >> C;
	int cnt = 0;
	for (int tc = 0; tc < C; tc++)
	{
		string idol_s, fans_s;
		cin >> idol_s >> fans_s;
		IDOL.reset();
		FANS.reset();
		int i_size = idol_s.size();
		int f_size = fans_s.size();
		for (int i = 0; i < i_size; i++)
		{
			if (idol_s[i] == 'M')
				IDOL.set(i, true);
		}
		for (int i = 0; i < f_size; i++)
		{
			if (fans_s[i] == 'M')
				FANS.set(i, true);
		}
		cout << counting(i_size, f_size) << '\n';

	}
}