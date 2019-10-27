#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int n;
struct per
{
    string name;
    int bear;
}p[maxn];
int dc[2][13]=
{
    {0,31,59,90,120,151,181,212,243,273,304,334,365},
    {0,31,60,91,121,152,182,213,244,274,305,335,366}
};
bool rn(int a)
{
    if(a%100==0)
    return a%400==0;
    else return a%4==0;
}
int year,month,day;
bool cmp(const per &x, const per &y)
{
	return x.bear<y.bear;//从小到大排<，若要从大到小排则>
}
signed main()
{
    cin>>n;
    for(int i=n-1;i>=0;i--)
    cin>>p[i].name>>year>>month>>day,p[i].bear=year*1000000+dc[rn(year)][month-1]+day;
    stable_sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    cout<<p[i].name<<endl;
    system("pause");
    return false;
}