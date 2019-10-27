#include <bits/stdc++.h>
using namespace std;
bool que[1024];
int res;
int main()
{
    cin>>res;
    int t=res;
    while(t--)
    {
        char temp;
        cin>>temp;
        if(!que[(int)temp]) memset(que,false,sizeof(que)),que[(int)temp]=true;
        else res--;
    }
    cout<<res+1<<endl;
    system("pause");
    return false;
}