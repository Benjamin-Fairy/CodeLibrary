#include <bits/stdc++.h>
using namespace std;
string a; 
int calc(string a)
{
    string b;
    int lena=a.size();
    if(lena%2) return lena;
    for(int i=0;i<lena/2;i++)
    {
        if(a[i]==a[lena-i-1])
        b+=a[i];
        else return lena;
    }
    return calc(b);
}
signed main()
{
    cin>>a;
    cout<<calc(a);
    return false;
}