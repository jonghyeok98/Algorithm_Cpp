// boj g1 17472
// 다리 만들기 2
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

static int dx[] = {0, 0, -1, 1};                    // 좌 우
static int dy[] = {-1, 1, 0, 0,};                   // 상 하

static vector<vector<int>> G;                       // 섬 그래프
static vector<vector<int>> visited;                 // 방문 배열

static vector<vector<pair<int, int>>> islandList;   // 모든 섬들의 좌표
static vector<pair<int, int>> islandPosList;        // 섬의 좌표
static int islandNumber = 1;                        // 섬의 번호
static int edgeCount = 0;                           // 간선 개수
 
int MST();
void Union(int a, int b);
int Find(int a);
void BFS(int y, int x);
void DFS(const pair<int, int>& startPos, pair<int, int> nowPos , int length, const pair<int, int>& nextPos);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    G.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<int>(M, false));

    for(int i=0; i<N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> G[i][j];
    }

    // 섬에 번호 매기기 BFS
    for(int i=0; i<N; i++)
    {
	    for(int j=0; j<M; j++)
	    {
            if(G[i][j]!=0 && !visited[i][j])
            {
                BFS(i, j);
                islandNumber++;
                islandList.push_back(islandPosList);       // 섬별로 좌표 추가
            }
	    }
    }

    parent.resize(islandNumber);

    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;

    // 섬에 다리 놓기 DFS
    for(const vector<pair<int, int>>& island : islandList)
    {
        for(const pair<int, int>& pos : island)
        {
            // 상하좌우로 다리 건설
            for(int i=0; i<4; i++)
            {
                DFS(pos, { pos.first, pos.second }, 0, { dy[i], dx[i] });
            }
        }
    }

    edgeCount = pq.size();          // 간선 개수 업데이트
    cout << MST();
    

    return 0;
}

int MST()
{
    int result = 0;
    int usedEdge = 0;

    while(!pq.empty())
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

    // 섬의 개수가 N개라면 현재 섬의 번호는 N+1인 상태
    // N-1개의 간선을 이용했다면 모두 연결된 상태
    if (usedEdge == islandNumber - 2)
        return result;

    return -1;
}

void BFS(int y, int x)
{
    queue<pair<int, int>> q;
    islandPosList.clear();             // 섬 좌표 배열 초기화

    islandPosList.emplace_back(y, x);
    G[y][x] = islandNumber;
    visited[y][x] = true;
    q.push({ y, x });

    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        int nowY = now.first;
        int nowX = now.second;

        for(int i=0; i<4; i++)
        {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M)
            {
                if (G[nextY][nextX] !=0 && !visited[nextY][nextX])
                {
                    q.push({ nextY, nextX });
                    visited[nextY][nextX] = true;
                    G[nextY][nextX] = islandNumber;

                    islandPosList.emplace_back(nextY, nextX);      // 섬에서 방문한 좌표 추가
                }
            }
        }
    }
}

void DFS(const pair<int, int>& startPos, pair<int,int> nowPos,int length, const pair<int, int>& nextPos)
{
    // 다음 좌표가 내 섬과 같다면 패스
    int nextY = nowPos.first + nextPos.first;
    int nextX = nowPos.second+ nextPos.second;
    if(nextY >= 0 && nextY<N && nextX >= 0 && nextX < M)
    {
        if (G[startPos.first][startPos.second] == G[nextY][nextX])
            return;

        // 바다면 DFS, length ++;
        if (G[nextY][nextX] == 0)
        {
            DFS(startPos, {nextY, nextX}, length + 1, nextPos);
        }
        else if (length > 1)
        {
            // 다음 좌표가 다른 섬이고 길이 > 2 면 pq.push
            pq.push({ G[startPos.first][startPos.second], G[nextY][nextX], length });
        }
    }
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


