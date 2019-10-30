#include <bits/stdc++.h>
using namespace std;
int a,b,ans;
int main()
{
	ios::sync_with_stdio(0);
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    if(!(i%4)||i%2)
	ans++;
    cout<<ans;
    return 0;
}
