// boj g1 11689
// GCD(n, k) = 1

#include <iostream>
#include <cmath>
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

    long N;             // 소인수 구성
    cin >> N;

    long result = N;    // 서로소의 개수

    for(long i=2; i<=sqrt(N); i++)
    {
        if(N%i == 0)    // 소인수라면
        {
            result = result - result / i;   // 결과값 업데이트
            while (N % i == 0)  
                N /= i;     // 소인수 지우기, 2^7*11 이라면 11만 남긴다.
        }
    }

    // 아직 소인수 구성이 남아있다면
    // 반복문에서 제곱근까지만 탐색하기 때문에 1개의 소인수가 누락되는 케이스
    if (N > 1)
        result = result - result / N;

    cout << result;

    return 0;
}
