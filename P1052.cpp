#include<bits/stdc++.h>
#define maxn 10005
using namespace std; 
int f[maxn],far[maxn],a[maxn],flag[maxn],p,s,t,n; 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin>>p>>s>>t>>n;
    if(s==t)
    { 
        int cont=0,qaq; 
        for(int i=1;i<=n;++i)
        cin>>qaq,cont+=((qaq%s)==0); 
        cout<<cont<<endl;
        //system("pause");
        return 0; 
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=0,f[0]=0,far[n+1]=min(p-a[n],100),p=0;
    for(int i=1;i<=n;i++)
    far[i]=min(a[i]-a[i-1],90),p+=far[i],flag[p]=1;
    p+=far[n+1];
    for(int i=1;i<=p+9;i++) 
    { 
        f[i]=INT_MAX-1; 
        for(int j=s;j<=t;j++)
        if(i>=j)
        f[i]=min(f[i],f[i-j]+flag[i]); 
    } 
    int minn=INT_MAX-1; 
    for(int i=p;i<=p+9;i++)
    minn=min(minn,f[i]); 
    cout<<minn;
    //system("pause");
    return false;
} 
