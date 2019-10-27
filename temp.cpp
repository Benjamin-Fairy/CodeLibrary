#include <bits/stdc++.h>
using namespace std;
struct square
{
    int x1, x2, y1, y2;
} sq[3];
sigend main()
{
    int o = 3;
    while(--o)
        cin >> sq[o].x1 >> sq[o].y1 >> sq[o].x2 >> sq[o].y2;
    cout << calc(1) + calc(2);
    return false;
}
calc(int i)
{
    
}