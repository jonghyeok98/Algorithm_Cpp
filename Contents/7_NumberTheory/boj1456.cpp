// boj g5 1456
// 거의 소수
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

static vector<bool> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    v.resize(sqrt(B)+1);

    v[1]=true;
    for(int i=2; i<=sqrt(B); i++)
    {
        for(int j=2; i*j<=sqrt(B); j++)
            v[i*j]=true;
    }
    
    int count=0;
    for(long long i=2; i<=sqrt(B); i++)
    {
        int k=2;
        if(!v[i])
        {
            while(pow(i,k)<=B)
            {
                if(pow(i,k)>=A)
                    count++;
                k++;
            }   
        }
    }


    cout << count;

    return 0;
}
