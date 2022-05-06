#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    int weak_size = weak.size();
    for(int i=0;i<weak_size;i++)
    {
        weak.push_back(weak[i]+n);
    }
    //0~2w-1까지의 배열 생성
    sort(dist.begin(),dist.end());
    do
    {
        for(int i=0;i<weak_size;i++)
        {
            int start = weak[i];
            int finish = weak[i+weak_size-1];
            for(int j=0;j<dist.size();j++)
            {
                start+=dist[j];
                if(start>= finish)
                {
                    answer = min(answer,j+1);
                }
                int next = upper_bound(weak.begin(),weak.end(),start) - weak.begin();
                start = weak[next];
            }
        }
        
    }while(next_permutation(dist.begin(),dist.end()));
    if(answer == 987654321)
        return -1;
    return answer;
}