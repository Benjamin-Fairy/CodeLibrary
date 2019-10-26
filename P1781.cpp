#include <bits/stdc++.h>
using namespace std;
string maxn, minn;
int n, tmp;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> minn;
        int mins = minn.size(), maxs = maxn.size();
        if (mins > maxs || (mins >= maxs && minn > maxn))
            maxn = minn, tmp = i;
    }
    cout << tmp + 1 << endl
         << maxn << endl;
    return 0;
}