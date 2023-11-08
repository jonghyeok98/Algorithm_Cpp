// boj s4 11047
// 동전 0
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for(int i=0; i<N; i++)
    {
        cin >> v[i];
    }
    
    int count=0;
    for(int i=N-1; i>=0; i--)
    {
        if(K==0)
            break;

        if(K>=v[i])
        {
            count+=(K/v[i]);
            K=K%v[i];
        }
    }

    cout << count;

    return 0;
}

