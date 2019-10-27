#include <bits/stdc++.h>
using namespace std;
void calc(char, int, int);
int n;
char oprt;
signed main()
{
    cin >> n;
    while (n--)
    {
        int a, b;
        string temp;
        cin >> temp;
        if (temp != "a" && temp != "b" && temp != "c")
        {
            char *ch = (char *)temp.c_str();
            a = atoi(ch), cin >> b;
        }
        else
            oprt = temp[0], cin >> a >> b;
        calc(oprt, a, b);
    }
    system("pause");
    return false;
}
void calc(char op, int a, int b)
{
    int c;
    if (op == 'a')
        cout << a << "+" << b << "=" << a + b << endl, c = a + b;
    if (op == 'b')
        cout << a << "-" << b << "=" << a - b << endl, c = a - b;
    if (op == 'c')
        cout << a << "*" << b << "=" << a * b << endl, c = a * b;
    string aa = to_string(a);
    string bb = to_string(b);
    string cc = to_string(c);
    cout << aa.length() + bb.length() + cc.length() + 2 << endl;
}