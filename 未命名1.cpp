#include <bits/stdc++.h>
using namespace std;
int N,M,S,L,ans1,ans2,x,y;
bool X[5005],Y[5005];
int main()
{
	ios::sync_with_stdio(0);
    cin>>N>>M>>S>>L;
    for(int i=0;i<S;i++)
	{
     cin>>x>>y;
     for(int i=x;i<=y;i++)
	 Y[i]=1;
    }
    for(int i=0;i<L;i++)
	{
     cin>>x>>y;
     for(int i=x;i<=y;i++)
	 X[i]=1;
    }
    for(int i=0;i<N;i++)
     if(Y[i]) ans1++;
    for(int i=0;i<M;i++)
     if(X[i]) ans2++;
    cout<<ans1*M+ans2*N-ans1*ans2;
    return 0;
}
