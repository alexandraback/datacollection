#include<bits/stdc++.h>
#define ll long long

using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

int A[1005];

int main()
{
    freopen ("B-large.in","r",stdin);
    freopen ("B-large.out","w",stdout);

    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        ll b=getnum(),n=getnum(),l=0,r=10e10,ans,mx=0;

        for(int i=1;i<=b;i++){A[i]=getnum();if(mx<A[i])mx=A[i];}

        while(l<r)
        {
            ll x=0,m=(l+r)/2;
            for(int i=1;i<=b;i++)x+=(m/A[i]+1);
            if(x>=n)r=m;
            else l=m+1;
        }
        l-=1;
        //cout<<l<<' '<<r<<endl;
        if(l<0)ans=n;
        else
        {
            ll x=0,e=1;
            for(int i=1;i<=b;i++)x+=(l/A[i]+1);
            l++;
            while(x<n)
            {
                if(l%A[e]==0)x++;
                if(x==n)break;
                e++;
                if(e>b)e=1,l++;
            }
            ans=e;
        }
        printf("Case #%d: %d\n",cases,ans);
    }
}
