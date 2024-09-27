// boj g5 1717
// 집합의 표현
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
bool check(int a, int b);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    parent.resize(n+1);

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for(int i=0; i<m; i++)
    {
        int q, a, b;
        cin >> q >> a >> b;

        if(q==0)
        {
            Union(a, b);
        }
        else
        {
            if (check(a, b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }


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

bool check(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return true;

    return false;
}
