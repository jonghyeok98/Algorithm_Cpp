// boj s1 10844
// 쉬운 계단 수
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

static int DP[101][10] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int MOD = 1000000000;

    for (int i = 1; i < 10; i++)
        DP[1][i] = 1;

    for(int i=2; i<=N; i++)
    {
        DP[i][0] = DP[i - 1][1] % MOD;
        DP[i][9] = DP[i - 1][8] % MOD;
	    for(int j=1; j<9; j++)
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1])%MOD;
    }


    int64 result = 0;

    for (int i = 0; i < 10; i++)
        result = (result + DP[N][i])%MOD;

    cout << result;

    return 0;
}

