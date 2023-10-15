// boj s4 11399
// ATM

// 아무 정렬이나 이용해 모든 값을 더하면 되는 문제
// 시간 복잡도가 O(n^2)이 허용되기 때문에 삽입 정렬 이용

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int count = 0;
	cin >> N;

	vector<int> v(N, 0);
	vector<int> s(N, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 1; i < N; i++)
	{
		int tmp = v[i];
		int j = i;
		while (j>=1 && v[j - 1] > tmp)
		{
			v[j] = v[j - 1];
			j--;
		}
		v[j] = tmp;
	}

	// 합 배열 만들기
	s[0] = v[0];
	for (int i = 1; i < N; i++)
	{
		s[i] = s[i-1] + v[i];
	}

	for (int i = 0; i < N; i++)
	{
		count += s[i];
	}

	cout << count;

	return 0;
}
