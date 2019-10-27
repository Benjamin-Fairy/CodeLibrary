#include <bits/stdc++.h>
using namespace std;
double v, th, vy, vx, t;
const double g = 10;
signed main()
{
    cin >> v >> th;
    vy = v * cos(th);
    vx = v * sin(th);
    t = vy / g;
    cout << t * vx << " " << 0.5 * g * pow(t, 2);
    return false;
}