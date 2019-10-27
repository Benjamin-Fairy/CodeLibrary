#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
long long N,x;
long long a[maxn];
long long ans;
signed main()
{
    cin>>N>>x;
    cin>>a[0];
    for(long long i=1;i<N;i++)
    {
        cin>>a[i];
        if(a[i]+a[i-1]>x)
        ans+=a[i]+a[i-1]-x,a[i]=x-a[i-1];
    }
    cout<<ans;
    return false;
}