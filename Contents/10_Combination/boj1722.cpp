// boj g5 1722
// 순열의 순서
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

static bool visited[21]={false};
static int64 factorial[21];
static int result[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    factorial[0] = 1;

    for(int i=1; i<N; i++)
    {
        factorial[i] = factorial[i - 1] * i;
    }

    if(Q == 1)
    {
        int64 K;
        cin >> K;

        for(int i=1; i<=N; i++)
        {
            int cnt = 1;

            while(cnt * factorial[N - i] < K)
                cnt++;

            K -= (cnt - 1) * factorial[N - i];
            for(int j=1; j<=N; j++)
            {
                if (visited[j])
                    continue;

                cnt--;

                if (cnt == 0)
                {
                    result[i] = j;
                    visited[j] = true;
                    break;
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            cout << result[i] << ' ';
        }
    }
    else
    {
        int64 K = 1;
		for(int i=1; i<=N; i++)
		{
            int cnt = 0;
            int64 temp;
            cin >> temp;

            for(int j=1; j<temp; j++)
            {
                if (!visited[j])
                    cnt++;
            }

            K += cnt * factorial[N - i];
            visited[temp] = true;
		}

        cout << K;
    }


    return 0;
}
