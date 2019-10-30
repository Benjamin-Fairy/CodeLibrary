#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int N,M,B,G,ans1,ans2;
int x,y;
bool X[5003],Y[5003];
int main(){
    cin>>N>>M>>B>>G;
    for(int i=1;i<=B;i++){
     cin>>x>>y;
     for(int i=x;i<=y;i++)Y[i]=1;
    }
    for(int i=1;i<=G;i++){
     cin>>x>>y;
     for(int i=x;i<=y;i++)X[i]=1;
    }
    for(int i=1;i<=N;i++)
     if(Y[i])ans1++;
    for(int i=1;i<=M;i++)
     if(X[i])ans2++;
    cout<<ans1*M+ans2*N-ans1*ans2;
}
