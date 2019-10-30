#include <bits/stdc++.h>
using namespace std;
long long a,c,p,q,r,x,tem,ans;
int main()
{
    cin>>a>>c>>p>>q>>r>>x;
    tem=p*(c-a);
    if (tem>0)
    if (tem>=x) 
	ans=a+floor((x*1.0)/p);
    else if (tem+q>=x) 
	ans=c;
    else 
	ans=c+floor(((x-tem-q)*1.0)/r);
    if (!tem)
	if (x<=q)
	ans=c;
    else 
	ans=c+floor(((x-q)*1.0)/r);
    if (tem<0)
    ans=a+floor((x*1.0)/r);
    cout<<ans;
    return 0;
}
