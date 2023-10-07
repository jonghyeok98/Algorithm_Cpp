// boj p5 11003
// 최솟값 찾기

#include <iostream>
#include <deque>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, L;
	deque<pair<int, int>> dq;
	cin >> N >> L;

	for (int k = 0; k < N; k++)
	{
		int tmp;
		cin >> tmp;
		
		while (dq.size() && dq.back().second > tmp)
			dq.pop_back();

		dq.push_back(make_pair(k, tmp));
		if (dq.front().first <= k - L)
			dq.pop_front();

		cout << dq.front().second << ' ' ;
	}
	

	return 0;
}
