// boj s1 11286
// 절댓값 힙

#include <iostream>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(int o1, int o2)
	{
		int first_abs = abs(o1);
		int second_abs = abs(o2);

		if (first_abs == second_abs)
			return o1 > o2;
		else
			return first_abs > second_abs;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	priority_queue<int, vector<int>, compare> pq;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(input);
		}
	}

	return 0;
}
