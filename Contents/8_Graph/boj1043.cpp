// boj g4 1043
// 거짓말
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
static vector<int> truePerson;
static vector<vector<int>> party;
void Union(int a, int b);
int Find(int a);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, T;
    int result = 0;
    cin >> N >> M >> T;

    parent.resize(N + 1);
    truePerson.resize(T);
    party.resize(M);

    for (int i = 0; i < T; i++)
        cin >> truePerson[i];

    for(int i=0; i<M; i++)
    {
        int partySize;
        cin >> partySize;

        for(int j=0; j<partySize; j++)
        {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    for (int i = 0; i <= N; i++)
        parent[i] = i;

    for(int i=0; i<M; i++)
    {
        int first = party[i][0];
        for (int j = 1; j < party[i].size(); j++)
            Union(first, party[i][j]);
    }

    for(int i=0; i<M; i++)
    {
        bool isPossible = true;
        int cur = party[i][0];
        for(int j=0; j<T; j++)
        {
	        if(Find(cur)==Find(truePerson[j]))
	        {
                isPossible = false;
                break;
	        }
        }
        if (isPossible)
            result++;
    }
    cout << result;

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

