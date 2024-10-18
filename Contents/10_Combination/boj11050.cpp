// boj b1 11050
// 이항 계수 1
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    int DP[11][11] = {{0}};

    for(int i=1; i<=N; i++)
    {
        DP[i][1] = i;
        DP[i][0] = 1;
        DP[i][i] = 1;
    }

	for(int i=2; i<=N; i++)
	{
		for(int j=1; j<=K; j++)
		{
            DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
		}
	}

    cout << DP[N][K];
    
    return 0;
}
