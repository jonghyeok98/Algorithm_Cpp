// boj s5 11004
// k번째 수

// quickSort를 모두 진행하면 
// 최악의 경우에는 O(N^2) 이기 때문에
// 시간초과가 뜨므로 시간 복잡도를 줄여야한다
// STL Algorithm에 있는 sort는 quickSort의 개선 버전이기 때문에
// 해당 정렬 함수를 사용하면 시간초과가 안뜬다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> v(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	cout << v[K - 1];

	return 0;
}

// quickSort 구현

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int partition(vector<int> &A, int l, int r);
// void quickSort(vector<int> &A, int l, int r);

// int main(void)
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
	
// 	int N, K;
// 	cin >> N >> K;
	
// 	vector<int> v(N, 0);

// 	for (int i = 0; i < N; i++)
// 		cin >> v[i];

// 	quickSort(v, 0, v.size()-1);

// 	cout << v[K - 1];

// 	return 0;
// }

// int partition(vector<int>& A, int l, int r)
// {
// 	int i = l;
// 	int j = r-1;
// 	int pivot = A[r];
// 	while (true)
// 	{
// 		while (A[i] < pivot && i<A.size()-1)
// 			i++;
// 		while (A[j] > pivot && j>0)
// 			j--;
// 		if (i >= j)
// 			break;
// 		::swap(A[i], A[j]);
// 	}
// 	::swap(A[r], A[i]);

// 	return i;
// }

// void quickSort(vector<int>& A, int l, int r)
// {
// 	if(r>l)
// 	{
// 		int i = partition(A, l, r);
// 		quickSort(A, l, i-1);
// 		quickSort(A, i + 1, r);
// 	}
// }
