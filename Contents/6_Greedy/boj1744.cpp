// boj g4 1744
// 수 묶기

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

    priority_queue<int> Pluspq;     // 1보다 큰 양수 내림차순
    priority_queue<int, vector<int>, greater<int>> Minuspq;    // 음수 오름차순
    int one=0;      // 1의 개수
    int zero=0;     // 0의 개수

    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp>1)
            Pluspq.push(tmp);
        else if(tmp==1)
            one++;
        else if(tmp==0)
            zero++;
        else
            Minuspq.push(tmp);
    }

    int sum=one;

    while(Pluspq.size()>1)
    {
        int data1=Pluspq.top();
        Pluspq.pop();
        int data2=Pluspq.top();
        Pluspq.pop();
        sum+=data1*data2;
    }

    if(!Pluspq.empty())
        sum+=Pluspq.top();


    while(Minuspq.size()>1)
    {
        int data1=Minuspq.top();
        Minuspq.pop();
        int data2=Minuspq.top();
        Minuspq.pop();
        sum+=data1*data2;
    }

    if(!Minuspq.empty() && zero==0)
        sum+=Minuspq.top();

    cout << sum;

    return 0;
}
