// boj g5 13023
// ABCDE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> G;
static vector<bool> visited;

static bool arrived = false;
void DFS(int v, int depth);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	G.resize(N);
	visited = vector<bool>(N, false);

	for(int i=0; i<M; i++)
	{
		int v, e;
		cin >> v >> e;
		G[v].push_back(e);
		G[e].push_back(v);
	}

	for (int i = 0; i < N; i++)
	{
		DFS(i, 1);
		if (arrived)
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}

void DFS(int v, int depth)
{
	if(depth==5 || arrived)
	{
		arrived = true;
		return;
	}
	visited[v] = true;

	for(int i: G[v])
	{
		if (!visited[i])
			DFS(i, depth + 1);
	}
	visited[v] = false;
}
