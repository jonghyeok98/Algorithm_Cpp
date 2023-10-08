// boj s4 2164
// 카드2

#include <iostream>
#include <queue>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int result;
	queue<int> q;
	cin >> N;

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size()>1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	
	cout << q.front();

	return 0;
}
