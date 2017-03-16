// karanaggarwal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
LL power(LL a, LL p, LL mod)
{LL ret = 1;while(p){if(p&1)ret = (ret*a)%mod;a=(a*a)%mod;p/=2;}return ret;}

int main()
{
    string a;
    int t; cin>>t; int T = t; while(t--)
    {
        int N; 
        VI X[100];
        VI C[100];
        cin>>N;
        repi(i,N)
        {
            cin>>a;
            int c=0;
            int l = SZ(a);
            repi(j,l-1)
            {
                c++;
                if(a[j]!=a[j+1])
                {
                   X[i].PB(a[j]);
                   C[i].PB(c);
                    c=0;
                }
            }
            X[i].PB(a[l-1]);
            C[i].PB(c+1);
        }
        int poss=1;
        repi(i,N-1)
            if(X[i]!=X[i+1])
            {
                poss=0; break;
            }
        if(poss==0)
        {    cout<<"Case #"<<T-t<<": Fegla Won\n";
            continue;
        }
        int M = SZ(X[0]);
        int ans=0;
        repi(i,M)
        {
            VI B;
            int minval = 10000000;
            repi(j,N)
                B.PB(C[j][i]);
            sort(B.begin(),B.end());
            for(int x=B[0]; x<=B[N-1]; x++)
            {
                int val=0;
                for(int j=0; j<N; j++)
                    val += abs(x-B[j]);
                if(val<minval)minval = val;
            }
            ans += minval;
        }
        cout<<"Case #"<<T-t<<": "<<ans<<endl;
    }
    return 0;
}

