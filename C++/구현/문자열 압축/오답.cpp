#include <string>
#include <vector>
/*
    문자열 압축
    1개 단위부터 1000개 단위까지 전부 보는게 맞음
    앞부터 잘라야함
*/
using namespace std;
//const int COMPRESS_MAX = 1001;
//string compressing_front; //500크기
//string compressing_back; //500크기
//앞축 여부를 확인하기 위해 앞과 뒤를 비교함
int solution(string s) {
    int answer = s.size();//answer 그냥 사이즈로 초기화
    int size = s.size();
    int tmp_size = size; //압축 시켰을때 임시로 길이
    int best_compress_size = (size)/2; //절반으로 나누어 압축하는게 가장 좋음
    //int length_front = 0;
    //int length_back = 0;
    for(int j=best_compress_size;j>1;j--)
    {
    //최대 압축 사이즈부터 압축 시도
    //무조건 앞부터 압축해야됨
    tmp_size = size;
    int compressing_number =1;
    for(int i=0;i+j<size;i+=j)
    {
        //string을 앞부터 순회해서 압축 여부를 전부 검사
        //압축 되면 size를 뺀 다음 압축 된 다음부터 
        
        bool compressed_or_not = true;
        int k = i+j;
            for(int p=0;p<j;p++)
            {
                //최대 압축 사이즈만큼 다 체크함
                if(s[i+p] != s[k+p])
                {
                    compressed_or_not = false;
                    break;
                }
                
            }
            if(compressed_or_not)
            {
                compressing_number++;
            }
            //압축 사이즈만큼 더해서 압축 되는지 확인 되면 뺌
            
            //원래 인덱스
        
        
        
    }
    if(compressing_number != 1)
        {
            tmp_size -= ((compressing_number * j) - (1+j));
            //size 계산
            //best_compress_size에서 
            //압축한게 두개 이상
        }
    //모든 압축 크기에 대해 확인
    //tmp_size가 원래 사이즈보다 작으면 answer 변경
    if(tmp_size<answer)
    {
        answer = tmp_size;
        //return answer;
    }
    
    }
    return answer;
}