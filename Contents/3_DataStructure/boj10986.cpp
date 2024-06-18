// boj g3 10986
// 나머지 합

// (A+B)%C는 ((A%C)+(B%C))%C와 같다
// N개중 2개를 선택하는 방법의 수는 N*(N-1)/2 이다
#include <iostream>
#include<vector>

using namespace std;

static int N, M;
static vector<long> s;
static vector<long> m;
static long result = 0;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	s.resize(N+1, 0);
	m.resize(M, 0);

	for(int i=1; i<=N; i++)
	{
		int tmp;
		cin >> tmp;
		s[i] = s[i - 1] + tmp;
	}

	for(int i=1; i<=N; i++)
	{
		int remain = s[i] % M;
		// 나머지가 0인 합 배열의 원소 더해주기
		if (remain == 0)
			result++;

		// 나머지가 같은 원소의 개수 더해주기
		m[remain]++;
	}

	for(int i=0; i<M; i++)
	{
		// 나머지가 같은 원소가 2개 이상 있다면
		// nC2  구하기
		if(m[i]>1)
		{
			result += (m[i] * (m[i]-1) / 2);
		}
	}

	cout << result;

	return 0;
}

