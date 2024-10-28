// boj s3 1463
// 1로 만들기

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

static int DP[1000001] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;


    for(int i=4; i<=N; i++)
    {
        DP[i] = DP[i - 1] + 1;

        if(i%2==0)
        {
            DP[i] = min(DP[i], DP[i / 2]+1);
        }

        if(i%3==0)
        {
            DP[i] = min(DP[i], DP[i / 3] + 1);
        }
    }

    cout << DP[N];
    


    return 0;
}
