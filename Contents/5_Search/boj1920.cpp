// boj s4 1920
// 수 찾기
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static vector<int> v;

bool binary_search(int l, int r, int num);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N;
    cin >> N;

    v.resize(N);

    for(int i=0; i<N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int M;
    cin >> M;
    for(int i=0; i<M; i++)
    {
        int tmp;
        cin >> tmp;
        if(binary_search(0, v.size()-1, tmp))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
        
    return 0;
}

bool binary_search(int l, int r, int num)
{
    if(r>=l)
    {
        int mid=(l+r)/2;
        if(num==v[mid])
            return true;
        else if(num > v[mid])
            return binary_search(mid+1, r, num);
        else
            return binary_search(l, mid-1, num);
    }
    return false;
}