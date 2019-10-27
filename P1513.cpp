#include <bits/stdc++.h>
#define maxn 1005
#define Pi 3.1415926535897932384626433832795028841971693993751
using namespace std;
double x[maxn], y[maxn];
double r, ans;
int n;
signed main()
{
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
        ans += sqrt(pow(x[i] - x[(i + 1) % n], 2) + pow(y[i] - y[(i + 1) % n], 2));
    cout << fixed << setprecision(2) << ans + 2 * Pi * r;
    return 0;
}