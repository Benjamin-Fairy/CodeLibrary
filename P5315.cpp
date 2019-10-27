#include <bits/stdc++.h>
using namespace std;
int n, L, G;
void calc(int, int);
signed main()
{
    cin >> n >> L >> G;
    while (n--)
    {
        int W, H;
        cin >> W >> H;
        calc(W, H);
    }
    system("pause");
    return false;
}
void calc(int W, int H)
{
    if (W < L || H < L)
    {
        cout << "Too Young" << endl;
        return;
    }
    if (W > G || H > G)
        calc(W / 2, H / 2);
    else
    {
        if (W != H)
            cout << "Too Simple" << endl;
        else
            cout << "Sometimes Naive" << endl;
        return;
    }
}