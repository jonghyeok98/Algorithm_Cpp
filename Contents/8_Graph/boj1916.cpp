// boj g5 1916
// 최소비용 구하기

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Node;
static vector<vector<Node>> graph;
static vector<int> _distance;
static priority_queue<Node, vector<Node>, greater<>> q;
static int N, M;

void djikstra(int node);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	graph.resize(N + 1);
	_distance = vector<int>(N + 1, INT_MAX);

	for(int i=1; i<=M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	int start, arrive;
	cin >> start >> arrive;

	djikstra(start);
	cout << _distance[arrive];

	return 0;
}

void djikstra(int node)
{
	q.push(make_pair(0, node));
	_distance[node] = 0;

	while(!q.empty())
	{
		Node cur = q.top();
		int curNode = cur.second;
		int curWeight = cur.first;
		q.pop();
		if(curWeight > _distance[curNode])
			continue;
		for(Node nextNode : graph[curNode])
		{
			int next = nextNode.first;
			int weight = nextNode.second;
			
			if(_distance[next] > _distance[curNode] + weight)
			{
				_distance[next] = _distance[curNode] + weight;
				q.push(make_pair(_distance[next], next));
			}
		}
	}
}
