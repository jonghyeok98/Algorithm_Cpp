// boj s1 1389
// 케빈 베이컨의 6단계 법칙
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

    vector<vector<int>> G = vector<vector<int>>(N+1, vector<int>(N+1, 10000001));

    for(int i=1; i<=N; i++)
    {
	    for(int j=1; j<=N; j++)
	    {
            if (i == j)
                G[i][j] = 0;
	    }
            
    }

    for(int i=0; i<M; i++)
    {
        int s, e;
        cin >> s >> e;
        G[s][e] = 1;
        G[e][s] = 1;
    }
   

    // floyd

    for(int k=1; k<=N; k++)
    {
	    for(int i=1; i<=N; i++)
	    {
		    for(int j=1; j<=N; j++)
		    {
                if (G[i][j] > G[i][k] + G[k][j])
                    G[i][j] = G[i][k] + G[k][j];
                    
		    }
	    }
    }

    int index = -1;
    int minimun = INT_MAX;
    for(int i=1; i<=N; i++)
    {
        int result = 0;
	    for(int j=1; j<=N; j++)
	    {
            result += G[i][j];
	    }
        if(minimun > result)
        {
            minimun = result;
            index = i;
        }
    }

    cout << index;

    return 0;
}
