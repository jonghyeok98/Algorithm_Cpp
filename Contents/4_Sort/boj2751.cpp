// boj s5 2751
// 수 정렬하기 2
// 병합 정렬로 풀기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<int> A;
static vector<int> B;

void mergeSort(int l, int r);
void merge(int l, int m, int r);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	A = vector<int>(N, 0);
	B = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	mergeSort(0, N-1);
	for (auto it : A)
		cout << it << '\n';

	return 0;
}

void mergeSort(int l, int r)
{
	if (r > l)
	{
		int m = (l + r) / 2;
		mergeSort(l, m);
		mergeSort(m+1, r);
		merge(l, m, r);
	}
}

void merge(int l, int m, int r)
{
	int i = l;
	int k = l;
	int j = m + 1;
	while (i <= m && j <= r)
	{
		if (A[i] < A[j])
		{
			B[k] = A[i];
			i++; k++;
		}
		else
		{
			B[k] = A[j];
			j++; k++;
		}		
	}
	if (i > m)
	{
		for (int p = j; p <= r; p++)
		{
			B[k] = A[p];
			k++;
		}
	}
	else
	{
		for (int p = i; p <= m; p++)
		{
			B[k] = A[p];
			k++;
		}
	}
	for (int p = l; p <= r; p++)
	{
		A[p] = B[p];
	}
}
