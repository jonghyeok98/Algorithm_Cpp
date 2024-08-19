// boj g4 2374
// 같은 수 만들기

#include <iostream>
#include<stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    long long result = 0;
    int max_num = 0;
    cin >> N;

    stack<int> s;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;;
        max_num = max(max_num, temp);
        if (s.empty()) {
            s.push(temp);
        }
        else {
            if (s.top() < temp) {
                result += temp - s.top();
                s.pop(); s.push(temp);
            }
            else if (s.top() > temp) {
                s.pop(); s.push(temp);
            }
        }
    }
   
	int num = s.top(); s.pop();
	result += max_num - num;
    
    cout << result;

    return 0;
}
