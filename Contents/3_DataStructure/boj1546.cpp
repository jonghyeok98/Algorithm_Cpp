// boj b1 1546 
// 평균

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, tmp;
	double res = 0;
	vector<int> v;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	M = v.back();

	for (auto it : v)
		res += it;

	res = (res * 100) / (M * N);

	cout << res;
	
	return 0;
}