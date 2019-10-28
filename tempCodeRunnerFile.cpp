#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int m, n, k, w, r, dm;
int a[maxn];
signed main()
{
    cin >> n >> m >> k >> w >> r, dm = m / k * w;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1, j = 1; i <= r; i++)
    {
        a[j] -= dm;
        if (a[j] < 0)
            j++;
    }
    for (int i = n; i > 0; i--)
        if (a[i] <= 0)
            n--;
    cout << n;
    return false;
}