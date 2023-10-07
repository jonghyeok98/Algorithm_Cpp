// boj s2 12891
// DNA 비밀번호

// 현재 문자에 대한 상태 배열을 구한 후
// 업데이트시에는 새로 추가되는 문자와 삭제되는 문자만
// 배열에 업데이트해서 체크하면 된다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checkArr[4] = {};
int curArr[4] = {};
int checkSecret = 0;
void Add(char c);
void Remove(char c);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int S, P;
	int result = 0;
	string input;
	cin >> S >> P;
	cin >> input;

	for (int i = 0; i < 4; i++)
	{
		cin >> checkArr[i];
		if (checkArr[i] == 0)
			checkSecret++;
	}

	for (int i = 0; i < P; i++)
	{
		Add(input[i]);
	}

	if (checkSecret == 4)
		result++;

	for (int i = P; i < S; i++)
	{
		Add(input[i]);
		Remove(input[i - P]);
		if (checkSecret == 4)
			result++;
	}

	cout << result;

	return 0;
}

void Add(char c)
{
	switch (c)
	{
	case 'A':
		curArr[0]++;
		if (checkArr[0] == curArr[0])
			checkSecret++;
		break;
	case 'C':
		curArr[1]++;
		if (checkArr[1] == curArr[1])
			checkSecret++;
		break;
	case 'G':
		curArr[2]++;
		if (checkArr[2] == curArr[2])
			checkSecret++;
		break;
	case 'T':
		curArr[3]++;
		if (checkArr[3] == curArr[3])
			checkSecret++;
		break;

	}
}

void Remove(char c)
{
	switch (c)
	{
	case 'A':
		if (checkArr[0] == curArr[0])
			checkSecret--;
		curArr[0]--;
		break;
	case 'C':
		if (checkArr[1] == curArr[1])
			checkSecret--;
		curArr[1]--;
		break;
	case 'G':
		if (checkArr[2] == curArr[2])
			checkSecret--;
		curArr[2]--;
		break;
	case 'T':
		if (checkArr[3] == curArr[3])
			checkSecret--;
		curArr[3]--;
		break;
	}
}