// boj s1 1931
// 회의실 배정

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second < b.second;

    return a.first < b.first;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for(int i=0; i<N; i++)
    {
        cin >> v[i].second;
        cin >> v[i].first;
    }

    sort(v.begin(), v.end(), compare);

    int endtime=0;
    int count=0;
    
    for(pair<int, int> i : v)
    {
        if(i.second>=endtime)
        {
            endtime=i.first;
            count++;
        }
    }

    cout << count;

    return 0;
}
