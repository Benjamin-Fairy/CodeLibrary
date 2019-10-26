#include <bits/stdc++.h>
#define maxn 10000005
using namespace std;
int N, B, s, t;
int h[maxn];
int dp[maxn];
signed main()
{
    cin >> N >> B;
    for (int i = 1; i <= N; i++)
        cin >> h[i], s += h[i];
    t = s - B;
    for (int i = 1; i <= N; i++)
        for (int j = t; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + h[i]);
    cout << s - B - dp[t] << endl;
    return false;
}