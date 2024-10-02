// boj g3 2252
// 줄 세우기
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <string>

using namespace std;

using int32 = long;
using int64 = long long;

static vector<vector<int>> G;
static vector<int> inDegree;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    G.resize(N + 1);
    inDegree.resize(N + 1);

    for(int i=0; i<M; i++)
    {
        int v, e;
        cin >> v >> e;

        G[v].push_back(e);
        inDegree[e]++;
    }

    queue<int> q;

    for(int i=1; i<=N; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        cout << now << " ";

        for(int next : G[now])
        {
            inDegree[next]--;
            if (inDegree[next] == 0)
                q.push(next);
        }
    }


    return 0;
}


