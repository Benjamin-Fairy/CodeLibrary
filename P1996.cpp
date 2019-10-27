#include <bits/stdc++.h>
const int maxn = 1005;
using namespace std;
deque<int> cir;
int n, m;
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cir.push_back(i);
    int itrt = 1;
    while (!cir.empty())
    {
        if (itrt == m)
            cout << cir.front() << " ", itrt = 0;
        else
            cir.push_back(cir.front());
        cir.pop_front();
        itrt++;
    }
    system("pause");
    return false;
}