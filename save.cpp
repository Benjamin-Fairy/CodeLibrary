#include <bits/stdc++.h>
using namespace std;
int temp, ans, ret;
signed main()
{
    cin >> temp;
    ans += 300 - temp;
    if (300 - temp >= 100)
        ret += ans / 100, ans %= 100;
    for (int i = 1; i < 12; i++)
    {
        cin >> temp;
        ans += 300;
        if (ans - temp < 0)
        {
            cout << "-" << i + 1;
            return false;
        }
        else
            ans -= temp, ret += ans / 100, ans %= 100;
    }
    cout << ans + ret * 120;
    return false;
}