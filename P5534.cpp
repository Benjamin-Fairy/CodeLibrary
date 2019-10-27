#include <bits/stdc++.h>
using namespace std;
long long a0,a1,k,ans,q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>a0>>a1>>k;
    q=a1-a0;
    cout<<a0*k+k*(k-1)*q/2<<endl;
    system("pause");
    return false;
}