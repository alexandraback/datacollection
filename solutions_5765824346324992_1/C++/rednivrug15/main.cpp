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
        int B,n;
        scanf("%d%d",&B,&n);

        long long barber[B];

        for(int i=0; i<B; i++)
            scanf("%lld",&barber[i]);

        if(n<=B)
        {
            printf("%d\n",B);
            continue;
        }

        long long low=0,high=(1e16),mid,ans=-1;

        while( low<=high )
        {
            mid=(low+high)/2;

            long long customers=0;

            for(int i=0; i<B; i++)
            {
                customers+=(mid)/barber[i]+1;
            }

            if(customers>=(n))
            {
                //printf("%lld--%lld %lld\n",mid,low,high);
                high=mid-1;
                ans=mid;
            }
            else
                low=mid+1;
        }

        long long peoplegone=0;

        for(int i=0; i<B ; i++)
        {
            if(ans%barber[i]==0)
                peoplegone+=ans/(barber[i]);
            else
                peoplegone+=ans/barber[i]+1;
        }

        for(int i=0; i<B; i++)
        {
            if(ans%barber[i]==0)
            {
                peoplegone++;
                if(peoplegone>=n)
                {
                    printf("%d\n",i+1);
                    break;
                }
            }
        }
    }

    return 0;
}
