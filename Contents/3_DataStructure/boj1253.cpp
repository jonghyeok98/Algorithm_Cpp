// boj g4 1253
// 좋다

// 양의 정수만을 생각하고 풀었더니 실수를 했다
// 1. 가장 작은 수 2개로는 못만들거라는 생각으로 반복문의
// 2번째부터 시작한 것
// 2. 0 0 3, -4 -2 -2 같은 경우를 만족하기 위해
// end_idx가 i-1이 아닌 N-1이 되어야한다
// i보다 큰 인덱스를 제외시켜버리는 큰 실수를 했다
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
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		int start_idx = 0;
		int end_idx =N-1;
		while (start_idx < end_idx)
		{
			if (v[start_idx] + v[end_idx] == v[i])
			{
				if (start_idx!=i && end_idx!=i)
				{
					count++;
					break;
				}
				else if (start_idx ==i)
					start_idx++;
				else if (end_idx == i)
					end_idx--;
			}
			else if (v[start_idx] + v[end_idx] < v[i])
				start_idx++;
			else
				end_idx--;
		}
	}

	cout << count;

	return 0;
}
