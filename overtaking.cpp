#include <bits/stdc++.h>
#define maxn 3000005
using namespace std;
struct car
{
    int x;
    int y;
} c[maxn];
bool cmp(car a, car b)
{
    return a.x > b.x;
}
int n, ans;
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i].x >> c[i].y;
    sort(c, c + n, cmp);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (c[j].y > c[i].y)
                ans++;
    cout << ans;
    return false;
}