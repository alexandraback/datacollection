//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
int vis[20][20];
int R[]={0,1},C[]={1,0};
int rec(int p,int n,int m,int k)
{
    if(p>=n*m)
    {
        if(k==0)return 0;
        else return 100000;
    }
    if(k==0)return 0;
    int x=p/m,y=p%m;
    int u=100000;
    if(n*m-p>k)
    u=rec(p+1,n,m,k);
    for(int i=0;i<2;i++)
    {
        if(x+R[i]<n&&y+C[i]<m)
            vis[x+R[i]][y+C[i]]++;
    }
    u=min(u,vis[x][y]+rec(p+1,n,m,k-1));
    for(int i=0;i<2;i++)
    {
        if(x+R[i]<n&&y+C[i]<m)
            vis[x+R[i]][y+C[i]]--;
    }
    return u;
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
     freopen("B.in","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
     sn("%d",&t);
     while(t--)
     {
         sn("%d %d %d",&n,&m,&k);
         memset(vis,0,sizeof(vis));
         pf("Case #%d: %d\n",cs++,rec(0,n,m,k));
     }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
