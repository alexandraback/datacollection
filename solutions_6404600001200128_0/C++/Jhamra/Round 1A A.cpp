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

int A[10005];

int main()
{
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt0.out","w",stdout);

    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        int n=getnum(),a1=0,a2=0,a3=0;

        for(int i=1;i<=n;i++)A[i]=getnum();

        for(int i=2;i<=n;i++)
        {
            if(A[i]<A[i-1])
            {
                a1+=A[i-1]-A[i];
                if(a2<A[i-1]-A[i])a2=A[i-1]-A[i];
            }
        }
        for(int i=1;i<=n-1;i++)
        {
            if(A[i]<a2)a3+=A[i];
            else a3+=a2;
        }
        printf("Case #%d: %d %d\n",cases,a1,a3);
    }
}
