#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int N, l, r;
int ans, H[maxn];
signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> H[i];
    for (int i = 1; i <= N; i++)
    {
        l = i, r = i;
        while (H[l - 1] <= H[l] && l - 1)
            l--;
        while (H[r + 1] <= H[r] && r < N)
            r++;
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return false;
}