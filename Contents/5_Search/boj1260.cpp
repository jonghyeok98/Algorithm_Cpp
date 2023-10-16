// boj s2 1260
// DFS와 BFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<vector<int>> G;
static vector<bool> visited;

void BFS(int v);
void DFS(int v);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, start;
	cin >> N >> M >> start;

	G.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for(int i=1; i<=M; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	for (int i = 1; i <= N; i++)
		sort(G[i].begin(), G[i].end());

	DFS(start);
	cout << '\n';
	::fill(visited.begin(), visited.end(), false);
	BFS(start);


	return 0;
}


void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i : G[now])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
				
		}
			
	}


}

void DFS(int v)
{
	if (visited[v])
		return;

	visited[v] = true;
	cout << v << " ";

	for(int i: G[v])
	{
		if (!visited[i])
			DFS(i);
	}
}