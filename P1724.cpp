#include <bits/stdc++.h>
#define int long
using namespace std;
int drct1[4]={1,0,-1,0};
int drct2[4]={0,-1,0,1};
int redc[500];
string order;
int T;
int x,y;
signed main()
{
    redc['E']=0,redc['S']=1,redc['W']=2,redc['N']=3;
    cin>>order>>T;
    if(T<order.length())
    for(int i=0;i<T;i++)
    x+=drct1[redc[(int)order[i]]],y+=drct2[redc[(int)order[i]]];
    else 
    {
        int sumx=0,sumy=0;
        for(int i=0;i<order.length();i++)
        sumx+=drct1[redc[(int)order[i]]],sumy+=drct2[redc[(int)order[i]]];
        int tot=order.length();
        x+=(T/tot)*sumx,y+=(T/tot)*sumy;
        for(int i=0;i<T%order.length();i++)
        x+=drct1[redc[(int)order[i]]],y+=drct2[redc[(int)order[i]]];
    }
    cout<<x<<" "<<y<<endl;
    system("pause");
    return false;
}