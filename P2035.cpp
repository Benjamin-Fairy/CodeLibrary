#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int n, t, sum;
int a[maxn];
signed main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (t--)
    {
        int maxx = 0, atomic_flag = 1;
        for (int i = 1; i <= n; i++)
            if (a[i] > maxx)
                maxx = a[i], atomic_flag = i;
        sum = a[atomic_flag] / (n - 1);
        cout << atomic_flag << endl;
        for (int i = 1; i <= n; i++)
            if (i != atomic_flag)
                a[i] += sum;
        if (a[atomic_flag] % (n - 1) != 0)
        {
            sum = a[atomic_flag] % (n - 1);
            for (int i = 1; i <= n && sum; i++)
                if (i != atomic_flag)
                    a[i]++, sum--;
        }
        a[atomic_flag] = 0;
    }
    return false;
}