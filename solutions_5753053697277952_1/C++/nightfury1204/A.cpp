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
#define mp make_pair

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
struct T{
int a;
};
struct vec{
double x,y;
 vec(double xx=0,double yy=0)
 {
     x=xx;y=yy;
 }
};
vec make_vac(vec p,vec q)
{
    return vec(q.x-p.x,q.y-p.y);
}
double dotproduct(vec p,vec q)
{
    return p.x*q.x+p.y*q.y;
}
double crossproduct(vec p,vec q)
{
    return p.x*q.y-q.x*p.y;
}
double vec_value(vec p)
{
    return sqrt(p.x*p.x + p.y*p.y);
}
vec unit_vec(vec p)
{
    double va=vec_value(p);
    return vec(p.x/va,p.y/va);
}
double dis(double px,double py,double qx,double qy)
{
    px=fabs(px-qx);
    py=fabs(py-qy);
    return sqrt(px*px+py*py);
}
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
int ar[10000];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen("A.in","r",stdin);
    //freopen("out.txt","w",stdout);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);s=0;
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
            s+=ar[i];
        }
        pf("Case #%d:",cs++);
        if(n==2)
        {
            while(ar[0]>0)
            {
                ar[0]--;
                pf(" AB");
            }
        }
        else
        {
            while(s>2)
            {
                u=0;
                for(i=0;i<n;i++)
                {
                    u=max(u,ar[i]);
                }
                for(i=0;i<n;i++)
                {
                    if(ar[i]==u&&s>2)
                    {
                        ar[i]--;s--;
                        pf(" %c",'A'+i);
                    }
                }
            }
            pf(" ");
            for(i=0;i<n;i++)
            {
                if(ar[i])pf("%c",i+'A');
            }
        }
        pf("\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
