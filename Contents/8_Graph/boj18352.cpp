// boj s2 18352
// 특정 거리의 도시 찾기
#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

void BFS(int node);
static vector<vector<int>> A;
static vector<int> visited;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K, X;
	cin >> N >> M >> K >> X;
	A.resize(N + 1);

	for(int i=0; i<M; i++)
	{
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}

	visited.resize(N + 1);

	for (int i = 0; i <= N; i++)
		visited[i] = -1;

	BFS(X);

	bool flag=false;
	for(int i=0; i<=N; i++)
	{
		if (visited[i] == K)
		{
			cout << i << '\n';
			flag = true;
		}
	}
	if (!flag)
		cout << -1;

	return 0;
}

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visited[node]++;

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i : A[cur])
		{
			if(visited[i]==-1)
			{
				visited[i] = visited[cur] + 1;
				q.push(i);
			}
		}
	}
}


