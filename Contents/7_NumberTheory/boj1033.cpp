// boj g2 1033
// 칵테일
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

static vector<int64> result;
static vector < vector<tuple<int, int, int>>> v;
static int64 lcm=1;

int64 gcd(int64 a, int64 b);
void BFS(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    v = vector<vector<tuple<int, int, int>>>(N);
    result = vector<int64>(N, 0);

    for(int i=0; i<N-1; i++)
    {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        v[a].emplace_back(b, p, q);
        v[b].emplace_back(a, q, p);
        lcm *= p * q / gcd(p, q);
    }

    BFS(0);

    int64 mgcd = result[0];
    for (int i = 1; i < N; i++)
        mgcd = gcd(mgcd, result[i]);

    for (int i = 0; i < N; i++)
        cout << result[i]/mgcd << " ";

    return 0;
}

int64 gcd(int64 a, int64 b)
{
    if (b == 0)
        return a;
    else
		return gcd(b, a % b);
}

void BFS(int node)
{
    queue<int> q;

    q.push(node);
    result[node] = lcm;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto next : v[cur])
        {
            if (result[get<0>(next)]) continue;

        	result[get<0>(next)] = result[cur] * get<2>(next) / get<1>(next);
        	q.push(get<0>(next));
	        
        }

    }
}
