// boj s3 11659
// 구간 합 구하기4

// 구간 합 배열만 있으면 풀 수 있기 때문에
// 따로 입력받은 배열을 가지고 있을 필요가 없다

#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;;
	int S[100001] = {};
	
	for (int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		S[i] = S[i - 1] + tmp;
	}

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << S[end] - S[start - 1] << '\n';
	}

	return 0;
}