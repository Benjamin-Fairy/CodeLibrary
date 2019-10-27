#include <bits/stdc++.h>
using namespace std;
int n, m, k, w, r, a[100100], d, ans, t[100100]; //t[x]是打死第x只蚂蚁所需要的总时间（注意这里是总时间）
int main()
{
    cin >> n >> m >> k >> w >> r;
    d = m / k, d *= w; //计算总伤害，注意这里要先计算塔数，再计算伤害
    for (int x = 1; x <= n; x++)
        cin >> a[x];
    sort(a + 1, a + n + 1);
    for (int x = 1; x <= n; x++)
    {
        t[x] = t[x - 1] + (a[x] - 1) / d + 1; //打死第x只蚂蚁需要的总时间=打死第x-1只蚂蚁需要的总时间+打死这只蚂蚁需要的时间
        if (t[x] > r)                         //如果t[x]大于r（没有时间打死这只蚂蚁）
            cout << n - x + 1, exit(0);       //还没有被打死的蚂蚁数（注意这只蚂蚁没有被打死，所以要+1），然后直接返回
    }
    cout << 0; //如果所有蚂蚁都被打死了，答案就是0
    return 0;
}