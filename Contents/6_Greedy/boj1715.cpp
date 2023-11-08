// boj g4 1715
// 카드 정렬하기
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
        
    int sum=0;
    while(pq.size()>1)
    {
        int data1=pq.top();
        pq.pop();
        int data2=pq.top();
        pq.pop();
        sum+=data1+data2;
        pq.push(data1+data2);
    }

    cout << sum;

    return 0;
}
