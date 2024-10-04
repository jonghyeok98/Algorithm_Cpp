// boj g3 1516
// 게임 개발
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <string>

using namespace std;

using int32 = long;
using int64 = long long;

static vector<vector<int>> G;
static vector<int> inDegree;
static vector<int> buildTime;
static vector<int> result;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    G.resize(N+1);
    inDegree.resize(N+1);
    buildTime.resize(N+1);
    result.resize(N+1);

    for(int i=1; i<=N; i++)
    {
        cin >> buildTime[i];

        while (true)
        {
            int temp;
            cin >> temp;

            if (temp == -1)
                break;

            G[temp].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> q;

    for(int i=0; i<=N; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int next : G[now])
        {
            inDegree[next]--;
            
            result[next] = max(result[next], result[now] + buildTime[now]);

            if (inDegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << result[i] + buildTime[i] << '\n';


    return 0;
}


