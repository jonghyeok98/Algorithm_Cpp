// boj s2 11724
// 연결 요소의 개수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> G;
static vector<bool> visited;

void DFS(int v);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;			// N: 정점, M: 간선
	int count = 0;
	cin >> N >> M;

	G.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int v, e;
		cin >> v >> e;
		G[v].push_back(e);
		G[e].push_back(v);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			count++;
			DFS(i);
		}
	}

	cout << count;

	return 0;
}

void DFS(int v)
{
	if (visited[v])
		return;

	visited[v] = true;

	for (int i : G[v])
	{
		if (!visited[i])
			DFS(i);
	}
}
