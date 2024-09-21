// boj s1 1850
// 최대공약수
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <string>

using namespace std;

using int32 = long;
using int64 = long long;

int gcd(int64 a, int64 b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int64 a, b;
    cin >> a >> b;

    int result = gcd(a, b);

    while(result>0)
    {
        cout << 1;
        result--;
    }

    return 0;
}

int gcd(int64 a, int64 b)
{
    if (b == 0)
        return a;
    else
		return gcd(b, a % b);
}
