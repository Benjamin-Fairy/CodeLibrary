#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int n, m, k;
int a[maxn][maxn], ans[maxn * maxn];
bool flag[maxn][maxn];
signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!flag[j][a[i][j]])
                flag[j][a[i][j]] = true, ans[a[i][j]]++;
    for (int i = 1; i <= k; i++)
        cout << ans[i] << " ";
    return false;
}