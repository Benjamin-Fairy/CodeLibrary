#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int M, N;
int w[maxn], c[maxn], f[maxn];
signed main()
{
    cin >> M >> N;
    for (int i = 1; i <= N; i++)
        cin >> c[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = w[i]; j <= M; j++)
            f[j] = max(f[j], f[j - w[i]] + c[i]);
    cout << f[M];
    return 0;
}