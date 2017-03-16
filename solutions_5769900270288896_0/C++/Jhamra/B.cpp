#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second

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

int main()
{
    freopen ("B-small-attempt5.in","r",stdin);
    freopen ("B-small-attempt5.out","w",stdout);

    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        int x=getnum(),y=getnum(),n=getnum(),ans=0;

        if(x==1||y==1)
        {
            int m=max(x,y);
            if(m/2+m%2>=n);
            else
            {
                int r=n-m/2-m%2;
                ans+=r*2;
                if(m%2==0)ans--;
            }
        }
        else if(x*y%2)
        {
            int a=x*y/2+1,b=(x-1)*(y-1)/2;
            if(n<=a);
            else
            {
                int c=(x-2)/2*2+(y-2)/2*2;
                n-=a;n++;
                if(n>=4)ans+=8;
                else ans+=n*2;
                n-=4;
                if(n>=c)ans+=c*3;
                else if(n>=0) ans+=n*3;
                n-=c;
                if(n>=0)ans+=n*4;
            }
        }
        else
        {
            int a=x*y/2,b=x+y-4;
            if(n<=a);
            else
            {
                n-=a;
                if(n>=2)ans+=4;
                else ans+=n*2;
                n-=2;
                if(n>=b)ans+=b*3;
                else if(n>=0)ans+=n*3;
                n-=b;
                if(n>=0)ans+=4*n;
            }
        }

        printf("Case #%d: %d\n",cases,ans);
    }
}
