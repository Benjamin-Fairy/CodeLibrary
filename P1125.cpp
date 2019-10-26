#include <bits/stdc++.h>
using namespace std;
int maxn = INT_MIN, minn = INT_MAX;
map<char, int> digit;
string a;
bool is_prime(unsigned long long n)
{
    unsigned long long stop = n / 6 + 1, Tstop = sqrt(n) + 5;
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
    {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1)
    {
        return 0;
    }
    for (unsigned long long i = 1; i <= stop; i++)
    {
        if (i * 6 >= Tstop)
        {
            break;
        }
        if ((n % (i * 6 + 1) == 0) || (n % (i * 6 + 5) == 0))
        {
            return 0;
        }
    }
    return 1;
}
signed main()
{
    cin >> a;
    for (int i = 0; i < a.size(); i++)
        digit[a[i]]++, maxn = max(maxn, digit[a[i]]);
    for (int i = 0; i < a.size(); i++)
        minn = min(minn, digit[a[i]]);
    if (is_prime(maxn - minn))
        cout << "Lucky Word" << endl
             << maxn - minn;
    else
        cout << "No Answer" << endl
             << "0";
    return false;
}