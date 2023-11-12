// boj s1 1747
// 소수 & 팰린드롬
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

static bool v[10000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N;
    cin >> N;

    v[0]=true;
    v[1]=true;

    for(int i=2; i<=10000; i++)
    {
        for(int j=2; i*j<=10000000; j++)
        {
            // 백만보다 큰 첫번째 소수이면서 팰린드롬 수 찾기
            v[i*j]=true;
        }
    }

    for(int i=N; i<=10000000; i++)
    {
        if(!v[i])
        {
            string temp=to_string(i);
            reverse(temp.begin(), temp.end());
            if(stoi(temp)==i)
            {
                cout << i;
                return 0;
            }
        }
    }


    return 0;
}
