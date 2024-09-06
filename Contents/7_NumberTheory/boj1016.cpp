// boj g1 1016
// 제곱 ㄴㄴ 수

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long min, max;
    cin >> min >> max;

    bool isPrime[1000001] = { false };
    long long result = max - min + 1;

    for(long long i=2; i*i<=max; i++)
    {
        long long temp = min / (i * i);
        if (min % (i*i) != 0)
            temp++;

        while(temp*i*i<=max)
        {
            if(isPrime[temp*i*i - min]==false)
            {
                isPrime[temp * i * i - min] = true;
                result--;
            }

            temp++;
        }

    }

    cout << result;

    return 0;
}
