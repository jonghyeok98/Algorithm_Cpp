// boj s2 11725
// 트리의 부모 찾기
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <climits>

using namespace std;

using int32 = long;
using int64 = long long;

static vector<vector<int>> G;
static vector<int> visited;
static vector<int> answer;

void DFS(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    G.resize(N + 1);
    visited.resize(N + 1, false);
    answer.resize(N + 1);

    for(int i=0; i<N-1; i++)
    {
        int v, e;
        cin >> v >> e;
        G[v].push_back(e);
        G[e].push_back(v);
    }

    // root 부터 탐색 시작
    DFS(1);

    for (int i = 2; i <= N; i++)
        cout << answer[i] << '\n';


    return 0;
}


void DFS(int node)
{
    visited[node] = true;

    for(const int next : G[node])
    {
	    if(!visited[next])
	    {
            visited[next] = true;
            answer[next] = node;
            DFS(next);
	    }
    }
}
