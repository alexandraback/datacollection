#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<climits>
using namespace std;
#define FOR(i,n) for(i=0;i<n;i++)
#define sint(i) scanf("%d",&i)
#define ss(s) scanf("%s",s)
#define pii pair<int,int>
#define ll long long
#define MAX 1000000000
#define MOD 1000000007
int main()
{
    // freopen("test.in", "r", stdin);
//freopen("file.out", "w", stdout);
 freopen("test.in", "r", stdin);
freopen("file.out", "w", stdout);
    int test;
    sint(test);
    int n,b,i;
    for(int t=1;t<=test;t++)
    {
        cout<<"Case #"<<t<<": ";
        sint(b);
        ll m[b];
        ll n;
        ll count1;
        ll maxi=0;
        scanf("%lld",&n);
        FOR(i,b)
        {
         scanf("%lld",&m[i]);
         maxi=max(maxi,m[i]);
        }
        if(n<=b)
        cout<<n<<"\n";
        else
        {
        n=n-b;
        ll low=1;
        ll high=n*maxi;
        ll mid;
        while(high>=low)
        {
           // cout<<high<<" "<<low<<"\n";
            ll x=0,y=0;
            mid=(high+low)/2;
            FOR(i,b)
            {
                if(mid%m[i]==0)
                {
                    y++;
                    x=x+(mid/m[i])-1;
                }
                else
                x=x+(mid/m[i]);
            }
            if(x>=n)
            {
                high=mid-1;
            }
            else if((x+y)<n)
            {
                low=mid+1;
            }
            else
            {
                count1=0;
                n=n-x;
                FOR(i,b)
                {
                    if(mid%m[i]==0)
                    {
                        count1++;
                    }
                    if(count1==n)
                    {
                        cout<<i+1<<"\n";
                        goto out;
                    }
                }
            }
        }
        }
        out:
        ;
    }
    return 0;
}
