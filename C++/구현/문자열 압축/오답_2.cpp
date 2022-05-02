#include <string>
#include <vector>

using namespace std;
/*
    문자열 압축
    실제 압축해야 함
    너무 어려움
    이런 유형 연습 필요
*/
int solution(string s) {
    int size = s.size();
    int answer = size;
    int max_comp_size = size/2;
    
    for(int i=1;i<max_comp_size+1;i++)
    {
        int compressing_size =0;
        string prev = s.substr(0,i); //비교할 첫째 문자열
        int count =1;
        int end_index;
        for(int j=i;j+i<size;j+=i)
        {
            string cur = s.substr(j,i);
            if(!prev.compare(cur))
            {
                count +=1;
            }
            else
            {
                if(count >=2)
                {
                    compressing_size+= i+1;
                }
                else
                {
                    compressing_size+=i;
                }
                count =1;
                prev = s.substr(j,i);
            }
            
        }
        compressing_size += (size %i);
        if(compressing_size)
            answer = min(answer,compressing_size);
        
    }
    return answer;
}