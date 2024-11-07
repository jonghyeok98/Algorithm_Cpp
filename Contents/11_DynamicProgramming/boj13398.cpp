// boj g5 13398
// 연속합 2
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

static vector<int> A, L, R;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    A.resize(N);
    L.resize(N);
    R.resize(N);


    for (int i = 0; i < N; i++)
        cin >> A[i];

    L[0] = A[0];
    int result = L[0];
    for(int i=1; i<N; i++)
    {
        L[i] = max(A[i], L[i - 1] + A[i]);
        result = max(L[i], result);
    }

    R[N-1] = A[N - 1];
    for(int i=N-2; i>=0; i--)
    {
        R[i] = max(A[i], R[i + 1] + A[i]);
    }


    for(int i=1; i<N-1; i++)
    {
        result = max(result, L[i - 1] + R[i + 1]);
    }

    cout << result;
    

    return 0;
}

