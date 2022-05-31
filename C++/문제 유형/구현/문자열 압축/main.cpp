#include <string>
#include <vector>

using namespace std;
/*
    문자열 압축
    실제 압축해야 함
    너무 어려움
    이런 유형 연습 필요
*/
int jarisoo(int n)
{
    int result = 0;
    while(n>0)
    {
        n/=10;
        result++;
    }
    return result;
}
int solution(string s) {
    int size = s.size();
    int answer = size;
    int max_comp_size = size/2;
    
    for(int i=1;i<max_comp_size+1;i++)
    {
        int compressing_size =size;
        string prev = s.substr(0,i); //비교할 첫째 문자열
        int count =1;
        for(int j=i;j<size;j+=i)
        {
            string cur = s.substr(j,i);
            if(prev == cur)
            {
                count +=1;
            }
            else
            {
                if(count >=2)
                {
                    int k = jarisoo(count);
                    compressing_size -= ((count*i) - (k+i));
                }
                
                count =1;
                prev = s.substr(j,i);
            }
            
            
        }
        if(count >=2)
        {
            int k = jarisoo(count);
            compressing_size -= ((count*i) - (k+i));
        }
        answer = min(answer,compressing_size);
        
    }
    return answer;
}