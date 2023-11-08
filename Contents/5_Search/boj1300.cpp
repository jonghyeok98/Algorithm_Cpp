// boj g1 1300
// K번째 수

// 아이디어가 굉장히 어려웠던 문제
// K번째 수보다 작거나 같은 값이 최소 K개 존재한다
// 각 행렬을 T로 나눈 몫과 N의 최솟값이 T보다 작은 수의 개수이다

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

    int left=1;
    int right=K;
    int mid;

    while(right>=left)
    {
        int sum=0;
        mid=(left+right)/2;
        for(int i=1; i<=N; i++)
        {
            sum+=min(N, mid/i);
        }

        if(K>sum)
            left=mid+1;
        else
            right=mid-1;
    }

    cout<<left;

    return 0;
}
