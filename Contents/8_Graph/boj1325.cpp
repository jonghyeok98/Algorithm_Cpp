// boj s1 1325
// 효율적인 해킹
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

static vector<vector<int>> V;
static vector<bool> visited;

int BFS(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, E;
    cin >> N >> E;

    V = vector<vector<int>>(N+1);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i <= N; i++)
        visited[i] = true;


    for(int i=0; i<E; i++)
    {
        int v, e;
        cin >> v >> e;
        V[e].push_back(v);
    }

    int maxCount = 0;
    vector<int> result(N + 1);
    for(int i=1; i<=N; i++)
    {
        fill(visited.begin(), visited.end(), false);
        int count = BFS(i);
        result[i] = count;
        maxCount = max(maxCount, count);
    }

    for(int i=1; i<=N; i++)
    {
        if (result[i] == maxCount)
            cout << i << ' ';
    }

    return 0;
}


int BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int count = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i : V[cur])
        {
	        if(!visited[i])
	        {
                visited[i] = true;
                q.push(i);
                count++;
	        }
        }
    }
    
    return count;
}
