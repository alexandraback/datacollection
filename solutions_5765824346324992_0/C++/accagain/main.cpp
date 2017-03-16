#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

#define ll long long
#define Maxn 1100

ll sa[Maxn];
int n,m;

ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

ll cal(ll ti)
{
    ll res =0;

    for(int i=1;i<=m;i++)
    {
        res+=ti/sa[i];
    }
    return res;
}

ll Cal(ll ti)
{
    ll res =0;
    for(int i=1;i<=m;i++)
    {
        if(ti%sa[i]==0)
            res++;
    }
    return res;
}

int main()
{
    //printf("%lld %lld\n",gcd(12,20),lcm(12,20));
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B-small-attempt3.out","w",stdout);

    int T;

    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%d%d",&m,&n);
        ll Lcm=1;
        for(int i=1;i<=m;i++)
        {
            scanf("%lld",&sa[i]);
            Lcm=lcm(Lcm,sa[i]);
        }
        ll sum=cal(Lcm); //
        n=n%sum;

        if(n==0)
            n=sum;

        ll ans,last=0;
        bool flag=false;
        for(int i=0;i<=Lcm&&!flag;i++)
        {
            ll temp2=Cal(i);
            //last+=temp2;
            //printf("temp2:%lld n:%lld i:%d",temp2,n,i);

            if(n<=temp2)
            {
                ll cnt=0;
                for(int j=1;j<=m&&!flag;j++)
                {
                    if(i%sa[j]==0)
                    {
                        cnt++;
                        if(cnt==n)
                        {
                            ans=j;
                            flag=true;
                            break;
                        }
                    }
                }

            }
            else
                n-=temp2;
        }

        printf("Case #%d: %lld\n",ca,ans);



    }

    return 0;
}
