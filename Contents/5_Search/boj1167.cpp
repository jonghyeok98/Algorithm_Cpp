// boj g2 1167
// 트리의 지름

#include <iostream>
#include <vector>

using namespace std;

static vector<vector<pair<int, int>>> v;
static vector<bool> visited;
static int maxDistance = 0;
static int firstEdge = 0;

void DFS(const int node, const int dist);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	v.resize(N+1);
	visited = vector<bool>(N+1, false);

	for(int i=1; i<=N; i++)
	{
		int vertex, edge, weight;
		cin >> vertex;
		while (true)
		{
			cin >> edge;
			if (edge == -1)
				break;
			cin >> weight;
			v[vertex].push_back(make_pair(edge, weight));
		}
	}

	DFS(1, 0);
	maxDistance = 0;
	fill(visited.begin(), visited.end(), false);
	DFS(firstEdge, 0);
	cout << maxDistance;
	return 0;
}


void DFS(const int node, const int dist)
{
	if (visited[node])
		return;

	if(dist>maxDistance)
	{
		firstEdge = node;
		maxDistance = dist;
	}
	visited[node] = true;

	for(const pair<int, int> i : v[node])
	{
		if (i.first>0 && !visited[i.first])
		{
			DFS(i.first, i.second+dist);
		}
	}
	
}