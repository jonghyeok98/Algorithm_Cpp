// boj b4 11720 
// 숫자의 합

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, res=0;
	string num;
	cin >> N;

	cin.ignore();
	cin >> num;

	for (int i = 0; i < num.length(); i++)
	{
        // 문자의 정수형 값을 얻고 싶다면 문자 0을 빼면 된다
		res += num[i] - '0';
	}
	
	cout << res;
	return 0;
}

