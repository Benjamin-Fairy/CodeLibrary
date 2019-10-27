#include <bits/stdc++.h>
using namespace std;
long double ans, temp;
signed main()
{
    //ios_base::sync_with_stdio(false);
    while (scanf("%Lf", &temp) != EOF)
        ans += temp * 10e6;
    cout<<fixed<<setprecision(5)<<ans/10e6<<endl;
    system("pause");
    return false;
}