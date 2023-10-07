// boj s4 1940
// 주몽

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	vector<int> v;
	int count = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int start_idx = 0;
	int end_idx = v.size()-1;

	while (start_idx < end_idx)
	{
		if (v[start_idx] + v[end_idx] == M)
		{
			count++;
			start_idx++;
			end_idx--;
		}
		else if (v[start_idx] + v[end_idx] < M)
		{
			start_idx++;
		}
		else
		{
			end_idx--;
		}
	}
	cout << count;

	return 0;
}
