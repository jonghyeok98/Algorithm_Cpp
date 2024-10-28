// boj s3 2193
// 이친수

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

static int64 DP[91] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N;
    cin >> N;

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 2;

    for (int i = 4; i <= N; i++)
        DP[i] = DP[i - 1] + DP[i - 2];

    cout << DP[N];



    return 0;

}
