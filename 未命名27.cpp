#include <bits/stdc++.h>
using namespace std;
unsigned long long num;
int main()
{
	ios::sync_with_stdio(false);
    cin>>num;
    cout<<((num&0x0000ffff)<<16|(num&0xffff0000)>>16)<<endl;
    return 0;
}
