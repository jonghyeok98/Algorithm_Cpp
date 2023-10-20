// boj g4 1197
// 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Edge
{
	int start, end, weight;
	bool operator > (const Edge& temp) const
	{
		return weight > temp.weight;
	}
};

static priority_queue<Edge, vector<Edge>, greater<>> pq;
static vector<int> parent;
static int V, E;

void Union(int a, int b);
int Find(int a);
int MST();

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	parent.resize(V+1);
	for (int i = 0; i <= V; i++)
		parent[i] = i;

	for(int i=0; i<E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({u, v, w});
	}

	cout << MST();

	return 0;
}


void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		parent[b] = a;
}

int Find(int a)
{
	if (parent[a] == a)
		return a;

	return parent[a] = Find(parent[a]);}

int MST()
{
	int useEdge = 0;;
	int result = 0;

	while(useEdge < V-1)
	{
		Edge now = pq.top();
		pq.pop();

		if(Find(now.start) != Find(now.end))
		{
			Union(now.start, now.end);
			result += now.weight;
			useEdge++;
		}
	}

	return result;
}

