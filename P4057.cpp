#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
signed main()
{
    cin>>a>>b>>c;
    long long temp1,temp2;
    temp1=a*b/__gcd(a,b);
    temp2=temp1*c/__gcd(temp1,c);
    cout<<temp2<<endl;
    system("pause");
    return false;
}