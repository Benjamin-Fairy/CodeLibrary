#include <bits/stdc++.h>
using namespace std;
int n,ans;
int num[100005];
bool mark[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>num[i];
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	for(int k=0;k<n;k++)
	if(num[i]+num[j]==num[k]&&!mark[k])
	ans++,mark[k]=!mark[k];
	cout<<ans;
	return 0;
}
