#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
deque<int> line;
int n,digit[maxn];
signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>digit[i];
    sort(digit,digit+n,greater<int>());
    for(int i=0;i<n/2;i++)
    cout<<digit[i]<<endl<<digit[n-i-1]<<endl;
    if(n%2) cout<<digit[n/2];
    return false;
}