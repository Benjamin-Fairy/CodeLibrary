#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int N;
int cow[maxn];
signed main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    cin>>cow[i];
    sort(cow,cow+N,greater<int>());
    for(int i=0;i<N;i++)
    {
        if(cow[i]<i)
        {
            cout<<i<<endl;
            return false;
        }
    }
    cout<<N<<endl;
    return false;
}