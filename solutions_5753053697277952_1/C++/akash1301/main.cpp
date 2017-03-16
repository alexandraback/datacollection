/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
#define dd double
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define pf printf
#define sf scanf
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define CASE(n) printf("Case #%d:",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define inf 1000000000
#define EPS 1e-9

using namespace std;

//8 way moves
//int fx[]={0,0,1,-1,1,1,-1,-1};
//int fy[]={1,-1,0,0,1,-1,1,-1};

//knight moves
//int fx[]={-2,-2,-1,-1,1,1,2,2};
//int fy[]={-1,1,-2,2,-2,2,-1,1};

//Bit operation
int SET(int n,int pos){ return n=n | (1<<pos);}
int RESET(int n,int pos){ return n=n & ~(1<<pos);}
int CHECK(int n,int pos){ return (bool) (n & (1<<pos));}


int bigMod(int n,int power,int MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        int ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

int modInverse(int n,int MOD)
{
    return bigMod(n,MOD-2,MOD);
}

int POW(int x, int y)
{
    int res= 1;
    for ( ; y ; ) {
        if ( (y&1) ) {
            res*= x;
        }
        x*=x;
        y>>=1;
    }
    return res;
}

int inverse(int x)
{
    dd p=((dd)1.0)/x;
    return (p)+EPS;
}

int gcd(int a, int b)
{
    while(b) b^=a^=b^=a%=b;
    return a;
}

int nC2(int n)
{
    return n*(n-1)/2;
}

int MOD(int n,int mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}


int main()
{
//    read();
//    write();
	int t,cas=0;
	getint(t);
	while(t--)
    {
        vector< paii >vv;
        vector<string>ans;
        int n;
        getint(n);
        loop(i,n)
        {
            int p;
            getint(p);
            vv.pb(mp(p,i));
        }
        int sz=vv.size();
        while(1)
        {
            sort(all(vv));
            reverse(all(vv));
            if(vv[0].fr==0)
                break;
            if(vv[1].fr==0)
            {
                if(vv[0].fr==1)
                {
                    string ss="";
                    ss+='A'+vv[0].sc;
                    ans.pb(ss);
                    vv[0].fr--;
                }
                else
                {
                    string ss1="";
                    ss1+='A'+vv[0].sc;
                    ss1+='A'+vv[0].sc;
                    ans.pb(ss1);
                    vv[0].fr-=2;
                }
            }
            else
            {
                string s1="";
                s1+='A'+vv[0].sc;
                s1+='A'+vv[1].sc;
                ans.pb(s1);
                vv[0].fr--;
                vv[1].fr--;
            }
        }
        CASE(cas);
        for(int i=ans.size()-1;i>=0;i--)
        {
            cout<<" "<<ans[i];
        }
        cout<<endl;

    }
	return  0;

}
