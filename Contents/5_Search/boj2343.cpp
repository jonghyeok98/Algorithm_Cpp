// boj s1 2343
// 기타 레슨
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static vector<int> v;
int binary_search(int l, int r, int num);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    v.resize(N);
    int left=0;
    int right=0;
    for(int i=0; i<N; i++)
    {
        cin >> v[i];
        if(left<v[i])
            left=v[i];
        right+=v[i];
    }
    
    int result = binary_search(left, right, M);
    cout << result;

    return 0;
}

int binary_search(int l, int r, int num)
{
    while(r>=l)
    {
        int count=1;
        int size=0;
        int mid=(l+r)/2;

        for(int i=0; i<v.size(); i++)
        {
            if(size+v[i]>mid)
            {
                count++;
                size=0;
            }
            size+=v[i];
        }
        if(num>=count)
            r=mid-1;
        else
            l=mid+1;

    }
    return l;
}