#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,mx=INT_MAX,my,temp,ans=INT_MAX;
int x[maxn],y[maxn];
signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>x[i]>>y[i],mx=min(mx,y[i]),my=max(my,y[i]);
    for(int j=mx;j<=my;j++)
    {
        for(int i=0;i<n;i++)
        temp+=abs(j-y[i]);
        ans=min(ans,temp),temp=0;
    }
    cout<<ans;
    return false;
}