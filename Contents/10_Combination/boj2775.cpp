// boj b1 2775
// 부녀회장이 될테야
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

// main에 선언하면 스택 오버플로우 발생
static int DP[15][15] = { {0} };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;


    for(int i=1; i<15; i++)
    {
        DP[0][i] = i;
        DP[i][1] = 1;
    }

    for(int i=1; i<15; i++)
    {
        for (int j = 2; j < 15; j++)
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
    }

    for(int i=0; i<T; i++)
    {
        int k, n;
        cin >> k >> n;

        cout << DP[k][n] << '\n';
    }

    
    return 0;
}
