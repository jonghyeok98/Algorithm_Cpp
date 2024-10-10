// boj g4 11657
// 타임머신

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
static vector<int64> dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    dist.resize(N + 1, INT64_MAX);

    for(int i=0; i<M; i++)
    {
        int start, arrive, weight;
        cin >> start >> arrive >> weight;

        G.emplace_back(start, arrive, weight);
    }

    dist[1] = 0;        // satrt node

    for(int i=1; i<N; i++)
    {
		for(int j=0; j<M; j++)
		{
            Edge edge = G[j];
			int start = get<0>(edge);
			int arrive = get<1>(edge);
			int weight = get<2>(edge);
			if (dist[start] != INT64_MAX && dist[arrive] > dist[start] + weight)
			{
				dist[arrive] = dist[start] + weight;
			}
		}
    }
    

    bool bCycle = false;
    // 음수 사이클 확인
    for (int i=0; i<M; i++)
    {

    	Edge edge = G[i];
    	int start = get<0>(edge);
    	int arrive = get<1>(edge);
    	int weight = get<2>(edge);

        if (dist[start] != INT64_MAX && dist[arrive] > dist[start] + weight)
        {
            // 음수 사이클 발생
            bCycle = true;
            break;
        }
            
    }

    if(bCycle)
    {
        cout << -1;
    }
    else
    {
        for (int i = 2; i<=N; i++)
        {
            if (dist[i] == INT64_MAX)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
            
    }


    return 0;
}