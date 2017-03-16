#include<bits/stdc++.h>
#define ll long long int
#define PB push_back
#define F first
#define S second
#define tr(c,i) for(typeof((c).begin())i = (c).begin(); i != (c).end(); i++) 
#define sint(n); scanf("%d",&n);
#define sll(n); scanf("%lld",&n);
#define pint(n); printf ("%d\n",n);
#define pll(n); printf ("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define set(a,b) memset(a, b, sizeof(a))


using namespace std;

ll n;
ll p[30], mn=LLONG_MAX;

ll okay()
{
    ll mx = -1, sum=0, mi;
    f(i, 0, n)
    {
        sum+=p[i];
        if (p[i]>mx)
        {
            mx = p[i];
            mi = i;
        }
    }
    if (sum==0)
        return -1;
    if (2*mx > sum)
        return mi;
    return -1;

}

char func ( ll x )
{
    return 'A'+x;
}

int main()
{
    ll t;
    cin>>t;
    f(tst, 1, t+1)
    {
        cin>>n;
        f(i,0,n)
        {
            sll(p[i]);
            mn = min(mn, p[i]);
        }
        printf("Case #%lld: ", tst);
        /*f(i,0, n)
        {
            if (p[i]-min >=2 )
                cout<<'A'+i<<'A'+i<<" ";
            else if (p[i]-min == 1)
                cout<<'A'+i<<" ";
        }*/

        f(i, 0, n)
        {
            ll num = p[i];
            f(j, 0, num)
            {
                p[i]--;
                ll tmp = okay();
                if (tmp==-1)
                    cout<<func(i)<<" ";
                else
                {
                    cout<<func(i)<<func(tmp)<<" ";
                    p[tmp]--;
                }
            }
        }
        cout<<endl;






    }

    return 0;
}
