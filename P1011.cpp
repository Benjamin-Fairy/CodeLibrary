#include <bits/stdc++.h>
#define maxn 2005
using namespace std;
int bus[maxn],up[maxn],down[maxn];
int main()
{
	int a,n,m,x;
	cin>>a>>n>>m>>x;
	bus[2]=a;
	bus[1]=bus[2];
	up[1]=a,down[1]=0;
	for(int num=0;;num++)
	{
		up[2]=num,down[num]=2;
		for(int i=3;i<n;i++)
		{
			up[i]=up[i-1]+up[i-2];
			down[i]=up[i-1];
			bus[i]=bus[i-1]+up[i]-down[i];
		}
		bus[n]=0;
		if(bus[n-1]==m)
		{
			cout<<bus[x];
			system("pause");
			return 0;
		}
	}
}
