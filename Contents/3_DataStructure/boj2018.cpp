// boj s5 2018
// 수들의 합 5

#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int start_idx=1, end_idx=1;
	int sum = 1, count = 1;

	cin >> N;

	while (end_idx != N)
	{
		if (sum == N)
		{
			count++;
			end_idx++;
			sum += end_idx;
		}
		else if (sum < N)
		{
			end_idx++;
			sum += end_idx;
		}
		else
		{
			sum-=start_idx;
			start_idx++;
		}
	}

	cout << count;

	return 0;
}
