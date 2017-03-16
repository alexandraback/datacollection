/*Author:rednivrug15*/
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007

long long power(long long a,long long b,long long mod)
{
    long long ret=1;

    while(b)
    {
        if(b%2==1)
            ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}

long long int gcd(long long int a,long long int b)
{
    return b==0?a:gcd(b,a%b);
}


int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);
    int t;
    cin>>t;

    for(int cases=1; cases<=t; cases++)
    {
        printf("Case #%d: ",cases);
        int n;
        scanf("%d",&n);

        long long int a[n];
        for(int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        long long int ans[2]={0};

        long long int lastans=a[0],best=0;

        for(int i=1; i<n; i++)
        {
            if(a[i]>=lastans)
                lastans=a[i];
            else
            {
                ans[0]+=a[i-1]-a[i];
                best=max(best,a[i-1]-a[i]);
                lastans=a[i];
            }
        }
        for(int i=0; i<n-1; i++)
        {
            ans[1]+=min(best,a[i]);
        }

        printf("%lld %lld\n",ans[0],ans[1]);
    }

    return 0;
}
