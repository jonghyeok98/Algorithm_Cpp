// boj g4 1197
// 최소 스패닝 트리

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

typedef struct Edge
{
    int start, end, weight;

    bool operator > (const Edge& edge) const
    {
        return weight > edge.weight;
    }
};

static int N, M;
static vector<int> parent;
static priority_queue<Edge, vector<Edge>, greater<>> pq;

int MST();
void Union(int a, int b);
int Find(int a);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for(int i=0; i<M; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        pq.push({ s, e, w });
    }

    cout << MST();

    return 0;
}

int MST()
{
    int result = 0;
    int usedEdge = 0;

    while(usedEdge < N-1)
    {
        Edge edge = pq.top();
        pq.pop();

        if(Find(edge.start) != Find(edge.end))
        {
            Union(edge.start, edge.end);
            usedEdge++;
            result += edge.weight;
        }
    }

    return result;
}


void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a!=b)
		parent[b] = a;
}

int Find(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = Find(parent[a]);
}


