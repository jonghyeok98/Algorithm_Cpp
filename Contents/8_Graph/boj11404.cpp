// boj g4 11404
// 플로이드
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int32>> G;
    G.resize(N + 1, vector<int32>(N + 1, 10000001));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                G[i][j] = 0;
        }
    }

    for(int i=0; i<M; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;

        // 시작 도시와 도착 도시를 연결하는 노선이 여러 개 일 수도 있으므로
        // 노선의 비용 중 가장 작은 노선으로 업데이트
        if(G[s][e] > w)
			G[s][e] = w;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (G[i][j] > G[i][k] + G[k][j])
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }

    for(int i=1; i<=N; i++)
    {
	    for(int j=1; j<=N; j++)
	    {
            if (G[i][j] == 10000001)
                cout << 0 << ' ';
            else
                cout << G[i][j] << ' ';
	    }
        cout << '\n';
    }


    return 0;
}