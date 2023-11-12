// boj s3 1929
// 소수 구하기

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

static vector<bool> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int M, N;
    cin >> M >> N;

    v.resize(N+1);
    v[1]=true;

    for(int i=2; i<=sqrt(N); i++)
    {
        for(int j=2; i*j<=N; j++)
        {
            v[i*j]=true;
        }
    }

    for(int i=M; i<=N; i++)
    {
        if(!v[i])
            cout << i << '\n';
    }


    return 0;
}
