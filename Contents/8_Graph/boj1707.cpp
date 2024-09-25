// boj g4 1707
// 이분 그래프
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
static vector<bool> visited;
static vector<int> check;
static bool flag;

void DFS(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int V, E;
        cin >> V >> E;

        G.resize(V + 1);
        visited.resize(V + 1);
        check.resize(V + 1);
        flag = true;

        for (int j = 0; j < E; j++)
        {
            int v, e;
            cin >> v >> e;
            G[v].push_back(e);
            G[e].push_back(v);
        }

        // 주어진 그래프가 하나로 연결된다는 보장이 없기 때문에
        // 모든 노드에 대해 탐색
        for(int i=1; i<=V; i++)
        {
            if (flag)
                DFS(i);
            else
                break;
        }

        if (flag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        for(int i=0; i<=V; i++)
        {
            G[i].clear();
            visited[i] = false;
            check[i] = 0;
        }

    }
    

    return 0;
}

void DFS(int node)
{
    visited[node] = true;

    for(int i : G[node])
    {
	    if(!visited[i])
	    {
            // 인접한 노드는 현재 노드와 다른 그룹으로 분리
            // 0과 1의 그룹
            check[i] = (check[node] + 1) % 2;
            DFS(i);
	    }
        else if(check[node] == check[i])
        {
            // 방문한 노드중에 현재 노드와 그룹이 같다면
            // 이분 그래프가 아님 
            flag = false;
        }
    }
}
