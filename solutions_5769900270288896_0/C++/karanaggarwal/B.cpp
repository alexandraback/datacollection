#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define rTR(v,it) for( LET(it,v.rbegin()) ; it != v.rend() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int N,M,X;
int f()
{
    LL ro = M/2; LL re = M - ro;
    LL co = N/2; LL ce = N-co;
    return re*ce  +ro*co;
}



int main()
{
    int t; si(t); int T = t; while(t--)
    {
        cout<<"Case #"<<T-t<<": ";
        cin>>N>>M>>X;
        if(f()>=X)
        {cout<<0<<endl; continue;}
        int k = N*M;
        int ans   = 4*X;
        repi(i,1<<k)
        {
            int l = __builtin_popcount(i);
            if(l!=X)continue;
            int cr = 0;
            for(int j = 0; j<k-1; j++)
            {
                if((i>>j) % 2)
                {
                if( (j%M) < (M-1) and (i & (1<<(j+1)))){trace2(j,cr);cr++;}
                if(j+M<k and (i & (1<<(j+M)))){ trace2(j,cr);cr++;}
                }
            }
            trace2(i,cr);
            ans=min(ans,cr);
        }
        cout<<ans<<endl;
    }
    return 0;
}

