#include <bits/stdc++.h>
#define maxn 405
using namespace std;
int dc[2][12]=
{
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};
int week[7];
int wkdy=1,n;
bool rn(int);
signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<12;j++)
        {
            for (int k = 1; k <= dc[rn(i)][j]; k++)
            {
                if(k==13)
                week[wkdy-1]++;
                if(wkdy==7)
                wkdy=1;
                else wkdy++;
            }
        }
    }
    for(int i=5,j=0;j<7;i=(i+1)%7,j++)
    cout<<week[i]<<" ";
    system("pause");
    return false;
}
bool rn(int a)
{
    a+=1900;
    if(a%100==0)
    return a%400==0;
    else return a%4==0;
}