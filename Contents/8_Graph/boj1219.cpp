// boj p5 1219
// 오민식의 고민

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

using Edge = tuple<int, int, int>;

static vector<Edge> G;
static vector<int32> dist;
static vector<int32> cityMoney;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, S, E, M;
    cin >> N >> S >> E >> M;

    dist.resize(N, LONG_MIN);
    cityMoney.resize(N);

    for(int i=0; i<M; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        G.emplace_back(start, end, weight);
    }

    for(int i=0; i<N; i++)
    {
        int money;
        cin >> money;
        cityMoney[i] = money;
    }

    dist[S] = cityMoney[S];

    for(int i=0; i<N+50; i++)
    {
	    for(int j=0; j<M; j++)
	    {
            Edge edge = G[j];
            int start = get<0>(edge);
            int end = get<1>(edge);
            int weight = get<2>(edge);

            if(dist[start]==LONG_MIN)
            {
                // 시작노드가 방문하지 않았을 때
                // 해당 노드로의 경로가 없으므로 패스
                continue;
            }
            else if(dist[start]==LONG_MAX)
            {
                // 시작 노드가 양수 사이클에 포함되어 있으면
                // 도착 노드도 양수 사이클에 포함
                dist[end] = LONG_MAX;
            }
            else if(dist[end] < dist[start] + cityMoney[end] - weight)
            {
	            // 돈을 더 많이 벌 수 있는 경로가 있다면 해당 경로로 업데이트
                if(i>=N-1)
                {
                    // N-1 반복 이후 업데이트 되는 노드는 양수 사이클에 해당
                    dist[end] = LONG_MAX;
                }
                else
                {
                    dist[end] = dist[start] + cityMoney[end] - weight;
                }
            }
               
	    }
    }

    if(dist[E] == LONG_MIN)
    {
	    // 도착노드에 방문하지 못했다면
        cout << "gg";
    }
    else if(dist[E] == LONG_MAX)
    {
        // 도착노드에 방문했고 양수 사이클에 연결되어 있으면
        cout << "Gee";
    }
    else
    {
        // 그 외의 경우
        cout << dist[E];
    }
    


    return 0;
}