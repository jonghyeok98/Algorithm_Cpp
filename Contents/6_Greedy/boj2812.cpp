// boj g3 2812
// 크게 만들기

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

    int N, K;
    cin >> N >> K;

    deque<int> dq;
    string answer = "";

    string input;
    cin >> input;

    for(int i=0; i<N; i++)
    {
        int temp = input[i]-'0';

        if (dq.empty() || K<=0)
            dq.push_back(temp);
        else
        {
            if (dq.back() > temp)
                dq.push_back(temp);
            else
            {
	            while(!dq.empty() && dq.back()<temp && K>0)
	            {
                    dq.pop_back();
                    K--;
	            }
                dq.push_back(temp);
            }
        }
    }

    for(int i=0; i<dq.size()-K; i++)
    {
        cout << dq[i];
    }

    return 0;
}