// boj s3 11726
// 2xn 타일링
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

static long long DP[1001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    DP[1]=1;
    DP[2]=2;

    for(int i=3; i<1001; i++)
        DP[i]=(DP[i-1]+DP[i-2])%10007;
    
    cout << DP[N];


    return 0;
}

