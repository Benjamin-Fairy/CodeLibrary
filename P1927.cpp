#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct dot
{
    int x;
    int y;
} dot[maxn];
int N;
int calc(int x, int y, int a, int b)
{
    return pow(x - a, 2) + pow(y - b, 2);
}
int maxx, maxy;
signed main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> dot[i].x >> dot[i].y;
    int ans = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        int step = 0;
        for (int j = 0; j < N; j++)
        {
            if (i != j)
                step = max(step, calc(dot[i].x, dot[i].y, dot[j].x, dot[j].y));
        }
        ans = min(ans, step);
    }
    cout << fixed << setprecision(4) << (double)ans * 3.1415926535 << endl;
    return false;
}