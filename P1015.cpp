#include <bits/stdc++.h>
#define maxN 105
using namespace std;
int n;
string m;
bool check(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    return a == s;
}
string add(int, string);
int main()
{
    cin >> n >> m;
    for (int i = 0; i <= 30; i++)
        if (check(m))
        {
            cout << "STEP=" << i;
            //system("pause");
            exit(false);
        }
        else
            m = add(n, m);
    cout << "Impossible!";
    //system("pause");
    exit(false);
}
inline string add(int k, string b)
{ //�߾��ȼӷ����̣��ƹ㵽 k ����
    char sixt[20] = "0123456789ABCDEF";
    string a = b;
    reverse(a.begin(), a.end());
    int numa[maxN], numb[maxN], numc[maxN];
    int len = a.length(), lenc = 1;
    string ans;
    for (int i = 0; i < len; i++)
    {
        if (isdigit(a[i]))
            numa[len - i] = a[i] - '0'; //����ʮ�����Ƶ����У���������ּ�ȥ 0 ����ͬ
        else
            numa[len - i] = a[i] - 'A' + 10; //����������ּ�ȥ A �ټ��� 10
        if (isdigit(b[i]))
            numb[len - i] = b[i] - '0';
        else
            numb[len - i] = b[i] - 'A' + 10;
    }
    int x = 0;
    while (lenc <= len)
    {
        numc[lenc] = numa[lenc] + numb[lenc] + x;
        x = numc[lenc] / k; //�ѳ��� 10 �޸�Ϊ���� k
        numc[lenc] %= k;    //����Ѷ� 10 ȡģ�޸�Ϊ�� k ȡģ
        lenc++;
    }
    numc[lenc] = x;
    while (numc[lenc] == 0)
        lenc--;
    for (int i = lenc; i >= 1; i--)
        ans += sixt[numc[i]];
    return ans;
}