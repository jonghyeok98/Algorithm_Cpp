// boj g4 17298
// 오큰수

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	stack<int> s;
	vector<int> v(N, 0);
	vector<int> result(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	result[N - 1] = -1;
	s.push(v[N - 1]);

	for (int i=N-2; i>=0; i--)
	{
		int value = v[i];
		while (!s.empty() && s.top() <= value)
			s.pop();

		if (s.empty())
			result[i] = -1;
		else
			result[i] = s.top();

		s.push(value);
	}

	for (auto it : result)
		cout << it << " ";

	return 0;
}
