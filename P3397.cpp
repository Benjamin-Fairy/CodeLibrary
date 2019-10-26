#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int mapp[maxn][maxn];
int m,n;
signed main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        for(int i=x-1;i<a;i++)
        for(int j=y-1;j<b;j++)
        mapp[i][j]++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<mapp[i][j]<<" ";
        cout<<endl;
    }
    return false;
}