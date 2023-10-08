// boj s2 1874
// 스택 수열

#include <iostream>
#include<vector>
#include <stack>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int num = 1;
	stack<int> s;
	vector<char> v;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		while (num <= tmp)
		{
			s.push(num);
			v.push_back('+');
			num++;
		}
		if (s.top() == tmp)
		{
			s.pop();
			v.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
		
	}
	
	for (auto it : v)
		cout << it << '\n';

	return 0;
}
