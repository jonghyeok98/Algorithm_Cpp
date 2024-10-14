// boj s1 11403
// 경로 찾기

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <climits>

using namespace std;

using int32 = long;
using int64 = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> G = vector<vector<int>>(N, vector<int>(N, 0));

    for(int i=0; i<N; i++)
    {
	    for(int j=0; j<N; j++)
            cin >> G[i][j];
    }

    // floyd

    for(int k=0; k<N; k++)
    {
	    for(int i=0; i<N; i++)
	    {
		    for(int j=0; j<N; j++)
		    {
                if (G[i][k] == 1 && G[k][j] == 1)
                    G[i][j] = 1;
		    }
	    }
    }

    for(int i=0; i<N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << G[i][j] << ' ';
        cout << '\n';
    }


    return 0;
}
