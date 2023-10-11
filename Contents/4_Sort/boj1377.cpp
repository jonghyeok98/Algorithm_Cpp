// boj g2 1377
// 버블 소트

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int count = 0;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		if (v[i].second - i > count)
			count = v[i].second-i;
	}

	cout << count + 1;
	return 0;
}
