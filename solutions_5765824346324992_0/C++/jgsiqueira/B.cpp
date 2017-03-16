#include <bits/stdc++.h>

using namespace std;

inline long long gcd (long long a, long long b)
{
    return b ? gcd(b, a % b) : abs(a);
}

inline long long lcm(long long a, long long b)
{
    if (a && b)
        return abs(a) / gcd(a, b) * (long long) abs(b);
    else
        return (long long) abs(a | b);
}

long long sum[10000000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int caso=1; caso<=t; caso++)
    {
        long long p,n;
        scanf("%lld%lld",&n,&p);

        long long vet[n], mdc;
        for(int i=0; i<n; i++) scanf("%lld",&vet[i]);

        mdc = vet[0];
        for(int i=1; i<n; i++) mdc = lcm(mdc, vet[i]);

        memset(sum, 0, sizeof(sum));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<mdc; j+=vet[i]) sum[j]++;
        }

        long long sumTotal=0;
        for(int i=0; i<mdc; i++) sumTotal+=sum[i];

        p %= sumTotal;

        if(p == 0)
        {
            long long ans=1;
            long long pos=mdc-1;
            while(sum[pos] == 0) pos--;
            for(int i=0; i<n; i++)
            {
                if(pos%vet[i] == 0) ans=i+1;
            }
            printf("Case #%d: %lld\n",caso,ans);
            continue;
        }

        long long pos=0;

        for(int i=0; p>0 && i<mdc; i++)
        {
            if(p - sum[i] <= 0)
            {
                pos=i;
                break;
            }
            p -= sum[i];
        }

        //printf("p=%lld\n",p);
        //printf("pos=%lld\n",pos);

        if(pos == 0)
        {
            printf("Case #%d: %lld\n",caso,p);
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(pos%vet[i] == 0) p--;
                if(p == 0)
                {
                    printf("Case #%d: %d\n",caso,i+1);
                    break;
                }
            }
        }
    }
    return 0;
}
