#include <iostream>
#define maxn 10005
using namespace std;
bool map[maxn][maxn];
int ans, x1, y1, x2, y2;
signed main()
{
    for (int k = 0; k < 2; k++)
    {
        cin >> x1 >> y1 >> x2 >> y2, x1 += 2005, y1 += 2005, x2 += 2005, y2 += 2005;
        for (int i = x1; i < x2; i++)
            for (int j = y1; j < y2; j++)
                map[i][j] = true, ans++;
    }
    cin >> x1 >> y1 >> x2 >> y2, x1 += 2005, y1 += 2005, x2 += 2005, y2 += 2005;
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            if (map[i][j])
                ans--;
    cout << ans;
    return false;
}
