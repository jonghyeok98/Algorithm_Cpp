// boj b2 2750
// 수 정렬하기

#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int arr[1001]={};
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = N-1; i >0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
				::swap(arr[j], arr[j+1]);
		}
	}
    // 또 다른 방법
    // for(int i=0; i<N-1; i++)
    // {
    //     for(int j=0; j<N-1-i, j++)
    //     {
    //         if(arr[j]>arr[j+1])
    //             swap(arr[j], arr[j+1]);
    //     }
    // }

	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';

	return 0;
}
