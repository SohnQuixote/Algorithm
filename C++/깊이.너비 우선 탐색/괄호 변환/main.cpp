#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
/*
    괄호 변환
    괄호 - 개수는 맞지만 짝이 안맞음
    모든 괄호 - 올바른 순서대로 배치
    ( == ) 균형잡힌
    짝 맞음 - 올바른
    입력 - 균형/올바른
    출력 - 올바른
    ( == 40 ->0
    ) == 41 ->1
    stack 사용해서 문법 검사
    스택 클리어 안해서 계속 헤맴 - 전역변수 사용하면 언제나 인지
*/
stack<int>s;
queue<int> q;
bool grammar_correct(vector<int> save , int size)
{
    bool result = false;
    int prev;
    while( !s.empty() ) s.pop();
    //s.push(save[0]);
    for(int i=0;i<size;i++)
    {
        if(s.size() > 0 && s.top() == 0 && save[i] == 1)
        {
            s.pop();
        }
        else
        {
        s.push(save[i]);
        }
    }
    result = s.empty();
    return result;
}
int boonri(vector<int> save)
{
    int left = 0;
    int right = 0;
    for(int i= 0;i<save.size();i++)
    {
        if(save[i] == 0)
            left++;
        else if(save[i] == 1)
            right++;
        if(left == right)
            break;
    }
    return (left+right);
    //인덱스 반환
}
vector <int> calc(vector<int> save)
{
    vector<int> u;
    vector<int> v;
    vector<int>result;
    if(save.size() == 0)
        return save; //비어있을 때
    else
    {
        int index= boonri(save);
        for(int i=0;i<index;i++)
        {
            u.push_back(save[i]);
            //result.push_back(save[i]);
        }
        for(int i=index;i<save.size();i++)
        {
            v.push_back(save[i]);
        }
        if(grammar_correct(u , u.size()))
        {
            for(int i=0;i<index;i++)
                result.push_back(u[i]);
            v = calc(v);
            for(int i=0;i<v.size();i++)
                result.push_back(v[i]);
            return result;
        }
        else
        {
            v= calc(v);
            result.push_back(0);
            for(int i=0;i<v.size();i++)
            {
                result.push_back(v[i]);
            }
            result.push_back(1);
            for(int i=1;i<u.size()-1;i++)
            {
                if(u[i] == 1)
                {
                    result.push_back(0);
                }
                else
                {
                    result.push_back(1);
                }
            }
            return result;
        }
    }
}
string solution(string p) {
    string answer = "";
    vector<int> save;
    for(int i=0;i<p.size();i++)
    {
        save.push_back(p[i] - '(');
    }
    if(grammar_correct(save,save.size())) //처음부터 올바른
        return p;
    save= calc(save);
    for(int i=0;i<save.size();i++)
    {
        answer.push_back(save[i] +'(');
    }
    return answer;
}
int main() {
  //std::cout << "Hello World!\n";
  string p = "()))((()";
  //string p = "()";
    vector<int> save;
    for(int i=0;i<p.size();i++)
    {
        save.push_back(p[i] - '(');
    }
  cout<<solution(p);
  //cout<<grammar_correct(save,save.size())<<endl;
}