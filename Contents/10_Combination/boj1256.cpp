// boj g2 1256
// 사전 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <climits>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

using int32 = long;
using int64 = long long;

static int DP[201][201] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    int N, M, K;
    cin >> N >> M >> K;

    // Init DP table
    for(int i=0; i<=N+M; i++)
    {
	    for(int j=0; j<=i; j++)
	    {
            if (j==0 || i == j)
                DP[i][j] = 1;
            else
            {
                DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
                if (DP[i][j] > 1000000000)
                    DP[i][j] = 1000000001;
            }
	    }
    }

    if (DP[N + M][M] < K)
    {
        cout << -1;
    }
    else
    {
        while(!(N==0 && M==0))
        {
            if (DP[N-1 + M][M] >= K)
            {
                cout << 'a';
                N--;
            }
            else
            {
                K -= DP[N-1 + M][M];
                cout << 'z';
                M--;
            }
        }
    }



    return 0;
}
