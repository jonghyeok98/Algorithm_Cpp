// boj s2 1541
// 잃어버린 괄호

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input;
	cin >> input;

	int result = 0;
	string num;
	bool flag = false;

	for(int i=0; i<=input.size(); i++)
	{
		if(input[i]=='-' || input[i]=='+' || i==input.size())
		{
			if(flag)
			{
				result -= stoi(num);
				num = "";
			}
			else
			{
				result += stoi(num);
				num = "";
			}
		}
		else
		{
			num += input[i];
		}

		if (input[i] == '-' )
			flag = true;
	}

	cout << result;
	
	return 0;
}