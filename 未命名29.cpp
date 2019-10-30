#include <bits/stdc++.h>
using namespace std;
bool mapp[10005][10005];
int a,b,x,y,ans;
int xx[2]={1,0};
int yy[2]={0,1};
void dfs(int x,int y)
{
	if(x==a&&y==b)
	{
		ans++;return;
	}
	else
	for(int i=0;i<2;i++)
	if(mapp[x+xx[i]][y+yy[i]])
	dfs(x+xx[i],y+yy[i]);
}
int main()
{
	memset(mapp,true,sizeof(mapp));
	cin>>a>>b;
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		mapp[x][y]=0;
	}
	for(int i=1;i<=a;i++)
	mapp[i][b+1]=0;
	for(int j=1;j<=b;j++)
	mapp[a+1][j]=0;
	dfs(1,1);
	cout<<ans;
	return 0;
}
