#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int N, ans;
long long H[maxn];
signed main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> H[i];
    for (int i = 0; i < N; i++)
    {
        int l = i, r = i;
        while (H[l - 1] <= H[l] && l > 1)
            l--;
        while (H[r + 1] <= H[r] && r < N)
            r++;
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return false;
}