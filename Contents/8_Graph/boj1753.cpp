// boj g4 1753
// 최단 경로

// 다익스트라의 경우 방문 경로를 체크해주면
// 더 짧은 경로가 있음에도 확인하지 못할 수도 있다
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Node;
static vector<vector<Node>> graph;
static vector<bool> visited;
static vector<int> _distance;
static priority_queue < Node, vector<Node>, greater<Node>> q;
static int V, E, K;

void djikstra(int node);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E >> K;

	graph.resize(V + 1);
	visited = vector<bool>(V + 1, false);
	_distance = vector<int>(V + 1, INT_MAX);

	for(int i=1; i<=E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	djikstra(K);

	for(int i=1; i<=V; i++)
	{
		if (visited[i])
			cout << _distance[i] << '\n';
		else
			cout << "INF" << '\n';
	}

	return 0;
}

void djikstra(int node)
{
	q.push(make_pair(0, K));
	_distance[K] = 0;
	visited[K] = true;

	while(!q.empty())
	{
		Node cur = q.top();
		int curNode = cur.second;
		
		q.pop();

		for(Node nextNode : graph[curNode])
		{
			int next = nextNode.first;
			int weight = nextNode.second;

			if(_distance[curNode] + weight < _distance[next])
			{
				_distance[next] = _distance[curNode] + weight;
				q.push(make_pair(_distance[next], next));
				visited[next] = true;
			}
		}
	}


}
