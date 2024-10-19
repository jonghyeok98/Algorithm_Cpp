// boj s3 13251
// 조약돌 꺼내기
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, K;
    cin >> M;

    vector<int> colors;

    int sum = 0;

    for(int i=0; i<M; i++)
    {
        int temp;
        cin >> temp;
        colors.push_back(temp);
        sum += temp;
    }

    cin >> K;

    double result = 0;

    for(int count : colors)
    {
        double p = 1;
        for (int i = 0; i < K; i++)
        {
            p *= static_cast<double>(count - i) / (sum-i);
        }
        result += p;
    }

    cout << fixed;
    cout.precision(9);
    cout << result;

    return 0;
}
