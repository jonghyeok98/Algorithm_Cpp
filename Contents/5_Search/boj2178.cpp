// boj s1 2178
// 미로 탐색

// 큐에 삽입할 때 방문 체크를 해주어야 현재 큐에 들어있는 다른 노드에서 중복 체크를 하지 않는다

#include <iostream>
#include <queue>

using namespace std;

static int dx[] = { 0, 0, -1, 1 };
static int dy[] = { -1, 1, 0, 0 };

static int N, M;
static vector<vector<int>> v;
static vector<vector<bool>> visited;

void BFS(int x, int y);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	v.resize(N , vector<int>(M));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			v[i][j] = input[j]-'0';
		}
	}

	BFS(0, 0);
	cout << v[N - 1][M - 1];

	return 0;
}


void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({y,x});
	visited[y][x] = true;

	while(!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for(int k=0; k<4; k++)
		{
			int i = curY + dy[k];
			int j = curX + dx[k];

			if (i >= 0 && j >= 0 && i < N && j < M)     // 좌표 유효성 검사
			{
				if(v[i][j]!=0 && !visited[i][j])        // 비방문 노드 및 갈 수 있는 노드 검사 
				{
					q.push({i,j});
					v[i][j] = v[curY][curX] + 1;
                    // 여기서 방문체크를 하지 않으면 큐에 들어있는 다른 노드에서 중복 방문을 하게된다
					visited[i][j] = true;
				}
			}
		}
	}
}