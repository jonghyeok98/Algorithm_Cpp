// boj g4 1976
// 여행 가자
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

static vector<int> parent;
void Union(int a, int b);
int Find(int a);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int G[201][201] = {};
    int route[1001] = {};
    parent.resize(N + 1);

    for(int i=1; i<=N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> G[i][j];
    }

    for (int i = 1; i <= M; i++)
        cin >> route[i];

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for(int i=1; i<=N; i++)
    {
	    for(int j=1; j<=N; j++)
	    {
		    if(G[i][j]==1)
		    {
                Union(i, j);
                G[j][i] = 0;
		    }
	    }
    }

    int start = Find(route[1]);
    bool flag = true;

    for(int i=2; i<=M; i++)
    {
	    if(start != Find(route[i]))
	    {
            cout << "NO";
            return 0;
	    }
    }
    cout << "YES";

    return 0;
}


void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
        parent[b] = a;
}

int Find(int a)
{
    if (parent[a] == a)
        return a;
    else
        return parent[a] = Find(parent[a]);
}

