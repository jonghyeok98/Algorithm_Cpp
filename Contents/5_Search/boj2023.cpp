// boj g5 2023
// 신기한 소수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<int> G = { 1,3,5,7,9 };
//static vector<bool> visited;

void DFS(int v, int n);
bool isPrime(int n);
static int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}

void DFS(int v, int n)
{
	if(n==N)
	{
		if(isPrime(v))
		{
			cout << v << '\n';
		}
		return;
	}
	for(int i : G)
	{
		if (isPrime(v * 10 + i))
			DFS(v * 10 + i, n + 1);
	}
}

bool isPrime(int n)
{
	for(int i=2; i<n/2; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
