// boj s5 1427
// 소트인사이드

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string input;
	cin >> input;

	vector<int> v(input.length(), 0);

	for (int i = 0; i < input.length(); i++)
	{
		v[i] = stoi(input.substr(i, 1));
	}

	for (int i = 0; i < v.size(); i++)
	{
		int max = i;
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[j] > v[max])
				max = j;
		}
		::swap(v[i], v[max]);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i];

	return 0;
}
