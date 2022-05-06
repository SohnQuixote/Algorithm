#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;
    int W = weak.size();

    // 원형에 대한 weak 배열 가공
    weak.resize(2*W);
    for(int i=W;i<weak.size();i++)
        weak[i] = weak[i-W]+n;

    sort(dist.begin(),dist.end()); // 순열 계산을 위한 정렬

    do{
        for(int i=0;i<W;i++){
            int start = weak[i]; // 검사 시작 지점
            int finish = weak[i+W-1]; // 검사 종료 예상 지점
            for(int j=0;j<dist.size();j++){
                start += dist[j];
                if(start >= finish){ // 모든 지점 방문 완료 시 탈출
                    answer = min(answer,j+1);
                    break;
                }
                // 다음 검사 시작 지점 구하기
                // => 마지막에 방문한 지점보다 큰 weak 지점 중 가장 작은 지점
                int next = upper_bound(weak.begin(),weak.end(),start)-weak.begin();
                start = weak[next];
            }
        }
    }while(next_permutation(dist.begin(),dist.end())); // 모든 순열에 대한 탐색

    if(answer == 1e9) return -1;

    return answer;
}