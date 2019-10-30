#include <bits/stdc++.h>
using namespace std;
int m=1,n;
int main()
{
	while(true)
	{
		cin>>m;
		if(!m) break;
	n=pow(m,2);
	if(n&1) puts("Bob");
	else puts("Alice");
	}
	return 0;
}
