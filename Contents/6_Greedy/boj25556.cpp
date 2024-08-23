// boj g5 25556
// 포스택

#include <iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(4, 0);


    for(int i=0; i<N; i++)
    {
        int count = 0;
        int temp;
        cin >> temp;

        for(int& j : v)
        {
            if (temp > j)
            {
                j = temp;
                break;
            }
        	count++;
        }

        if (count >= 4)
        {
            cout << "NO";
            return 0;
        }

    }

    cout << "YES";
   
    return 0;
}
