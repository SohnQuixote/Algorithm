#include <iostream>
#include <string>
using namespace std;
/*
  FANMEETING
  모든 멤버들이 동시에 포옹
  멤버의 수 항상 팬수 이하
  남성 1 여성 -
  여성 멤버 언제나 포옹
  남성 멤버 남성과만 포옹 안함
  남성과 남성이 겹치면
  1 1 0
  0 1 1
  1 0 1
  0 0 1
  앤드연산 부정
  투포인터
*/
int C;
string idol;
string fans;
bool hug(string ido, string fa) {
  int i_size = ido.size();
  for (int i = 0; i < i_size; i++) {
    if (ido[i] == 'M' && fa[i] == 'M')
      return false;
  }
  return true;
}

int main() {
  cin >> C;
  for (int tc = 0; tc < C; tc++) {
    cin >> idol;
    cin >> fans;
    int start = 0;
    int end = idol.size();
    string window = "";
    for (int idx = start; idx < end - 1; idx++) {
      window += fans[idx];
    }
    int result = 0;
    int f_size = fans.size();
    for (int idx = end - 1; idx < f_size; idx++) {
      window += fans[idx];
      if (hug(idol, window)) {
        result += 1;
      }
      window.erase(0, 1);
    }

    cout << result << '\n';
  }
}