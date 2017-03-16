///     Raihan Ruhin
///     CSE, Jahangirnagar University.
///     Dhaka-Bangladesh.
///     id: raihanruhin (topcoder / codeforces / codechef / hackerrank / uva / uvalive / spoj), 3235 (lightoj)
///     mail: raihanruhin@ (yahoo / gmail / facebook)
///     blog: ruhinraihan.blogspot.com

#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 100010

#define READ freopen("B-small-attempt1.in", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)

int main()
{
    READ;
    WRITE;
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc,kk=1, n, mk[1010], b;

    cin>>tc;
    while(tc--)
    {
        cin>>b>>n;
        for(int i=0;i<b;i++) cin>>mk[i];
        int ans;
        if(b==1)
        {
            ans=1;
            cout<<"Case #"<<kk++<<": "<<ans<<"\n";
            continue;
        }
        int lcm=(mk[0]*mk[1])/__gcd(mk[0], mk[1]);
        for(int i=2;i<b;i++)
            lcm=(lcm*mk[i])/__gcd(lcm, mk[i]);
        int tot=0;
        for(int i=0;i<b;i++)
            tot+=lcm/mk[i];
        //cout<<tot<<endl;
        int me=n%tot;
        if(!me)
        {
            //ans=b;
            int mn=mk[b-1];
            ans=b;
            for(int i=b-1;i>=0;i--)
                if(mk[i]<mn)
                {
                    mn=mk[i];
                    ans=i+1;
                }
            cout<<"Case #"<<kk++<<": "<<ans<<"\n";
            continue;
        }

        int q=1;
        //int tm=1;
        int mkRem[1010];
        for(int i=0;i<b;i++) mkRem[i]=0;

        while(q<=me)
        {
            for(int i=0;i<b;i++)
                if(mkRem[i]==0)
                {
                    if(q==me) ans=i+1;
                    mkRem[i]=mk[i];
                    q++;
                }
            for(int i=0;i<b;i++)
                mkRem[i]--;
        }
        cout<<"Case #"<<kk++<<": "<<ans<<"\n";
    }
    return 0;
}

