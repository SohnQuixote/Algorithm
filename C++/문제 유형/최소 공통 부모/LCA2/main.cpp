#include <iostream>
#include <vector>
using namespace std;
/*
  LCA2
  N과 M의 범위가 많이 큼
  자신의 부모를 갖고있는 배열 parents
  루트는 무조건 1
  두개의 공통 부모를 찾는 find_same
  트리구조를 만드는 make(child,parent)
  연결 정보를 나타내는 vector<int>graph[MAX_INF]
  선행 시간이면 많이 길수 있나?
  기억을 되새기며 구현해보기
  level이 필요하다
  parent를 2차원으로 두기
  parent[x][k] = x번 정점의 2^k번째 조상 노드의 번호

*/
int N, M;
const int MAX_INF = 100001;
int parents[MAX_INF][20] = {
    0,
};
//해당 노드의 2^i승의 부모를 저장한다.
int levels[MAX_INF] = {
    0,
};
vector<int> graph[MAX_INF];
int max_lvl = 16; // 10000개 트리의 최대 높이
int find_parent(int a, int b) {
  if (a == 1 || b == 1)
    return 1;
  if (levels[a] < levels[b])
    swap(a, b);
  if (levels[a] != levels[b]) {
    for (int i = max_lvl; i >= 0; i--) {
      if (levels[parents[a][i]] >= levels[b])
        a = parents[a][i];
    }
  }
  int ret = a;
  if (a != b) {
    for (int i = max_lvl; i >= 0; i--) {
      if (parents[a][i] != parents[b][i]) {
        a = parents[a][i];
        b = parents[b][i];
      }
      //같은 시점임
      ret = parents[a][i];
    }
  }
  return ret;
}

//잘 됨
void make_parent(int child, int parent) {
  parents[child][0] = parent;
  //첫번째 부모를 정한다
  levels[child] = levels[parent] + 1;
  for (int i = 1; i <= max_lvl; i++) {
    parents[child][i] = parents[parents[child][i - 1]][i - 1];
    //부모의 부모를 체킹한다
    //두개를 건너뛰는 전부분
  }
  for (int i = 0; i < graph[child].size(); i++) {

    if (graph[child][i] == parent)
      continue;
    //이미 부모가 정해져 있다.
    make_parent(graph[child][i], child);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int p, c;
    cin >> p >> c;
    graph[p].push_back(c);
    graph[c].push_back(p);
  }
  make_parent(1, 0);
  cin >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    cout << find_parent(a, b) << '\n';
  }
}