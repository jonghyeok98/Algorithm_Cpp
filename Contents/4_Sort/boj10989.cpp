// boj b1 10989
// 수 정렬하기 3
// 계수 정렬 풀이

// N이 10,000,000 으로 매우 크기 때문에
// O(nlogn) 보다 더 빠른 알고리즘이 필요하다
// 기수 정렬 및 계수 정렬은 O(Kn) 이기 때문에
// 계수정렬이 기수정렬보다 간단하기 때문에
// 계수 정렬을 사용해보자

// 1. N이 1~10000이기 때문에 10001개의 배열을 선언한다
// 2. 이후 각 인덱스에 해당되는 숫자가 들어오면 해당하는 배열에 counting을 해준다
// 3. 0이 아닌 인덱스에 해당하는 숫자를 개수만큼 출력한다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001] = {};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			cout << i << '\n';
	}

	return 0;
}