// boj s3 14501
// 퇴사
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

static int DP[17] = {};
static int T[16] = {};
static int P[16] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> T[i] >> P[i];

    for(int i=N; i>0; i--)
    {
        if (i + T[i] > N+1)
            DP[i] = DP[i + 1];
        else
            DP[i] = max(DP[i + 1], DP[i + T[i]] + P[i]);
    }
    
    cout << DP[1];

    return 0;
}
