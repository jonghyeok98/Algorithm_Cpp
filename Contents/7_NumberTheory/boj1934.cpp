// boj b1 1934
// 최소공배수

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <string>

using namespace std;

int gcd(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        int result = a * b / gcd(a, b);
        cout << result << '\n';
    }

    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
