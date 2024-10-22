// boj g3 1947
// 선물 전달
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

static int64 DP[1000001] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    DP[1] = 0;
    DP[2] = 1;

    for(int i=3; i<=N; i++)
    {
        DP[i] = (i-1) * (DP[i - 1] + DP[i - 2]) % 1000000000;
    }

    cout << DP[N];


    return 0;
}
