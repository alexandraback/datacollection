//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

long long ar[1000009],N,B;
string aa;

long long check(long long curr)
{
    long long temp=0,i;

    for(i=1;i<=B;i++) temp+=(curr/ar[i])+1;

    if(temp>=N) return 1;
    return 0;
}

long long BS(long long low,long long high)
{
    if(low==high) return low;
    if(low==high-1)
    {
        if(check(low)) return low;
        return high;
    }

    long long mid;
    mid=low+high;
    mid/=2;

    if(check(mid)) return BS(low,mid);
    return BS(mid,high);
}

int  main()
{
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    long long i,j,k,T,S,ans,temp,cas=0,ans1,now;
    cin>>T;
    while(T--)
    {
        cas++;

        cin>>B>>N;

        for(i=1;i<=B;i++) cin>>ar[i];

        ans=BS(0,100000*N);



        temp=0;

        for(i=1;i<=B;i++)
        {
            if(ans%ar[i]) temp+=(ans/ar[i]+1);
            else temp+=(ans/ar[i]);
        }



        for(i=1;i<=B;i++)
        {
            if(ans%ar[i]==0) temp++;
            if(temp>=N)
            {
                ans1=i;
                break;
            }
        }

        printf("Case #%lld: %lld\n",cas,ans1);

    }

}
