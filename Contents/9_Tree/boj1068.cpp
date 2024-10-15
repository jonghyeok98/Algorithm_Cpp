// boj g5 1068
// 트리
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
static vector<bool> visited;

static int deleteNode;
static int result = 0;

void DFS(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int rootNode=0;

    cin >> N;
    G.resize(N);
    visited.resize(N, false);

    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;

        if (temp == -1)
            rootNode = i;
        else
        {
            G[i].push_back(temp);
            G[temp].push_back(i);
        }
    }

	cin >> deleteNode;

    if (deleteNode == rootNode)
    {
        cout << 0;
        return 0;
    }

    visited[rootNode] = true;
	DFS(rootNode);

    cout << result;

    return 0;
}

void DFS(int node)
{
    int leafNode = 0;

    for(const int next : G[node])
    {
	    if(!visited[next] && next!=deleteNode)
	    {
            visited[next] = true;
            leafNode++;
            DFS(next);
	    }
    }

    if (leafNode == 0)
        result++;
}
