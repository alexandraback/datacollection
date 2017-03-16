/**
  *	@author mzr_c0der
  *	Believe you can and you are halfway there
  */
#include<bits/stdc++.h>
#ifdef mzr
//#include<debug.h>
#else
#define db(...) {}
#define dbt(...) {}
#define pprintf(...) {}
#endif

using namespace std;

//#define assert(f) {if(!(f)){fprintf(stderr,"Line-->%d  Assertion failed: %s\n",__LINE__,#f);exit(1);}}
#define MOD 	 1000000007LL
#define ABS(x)   ((x)<0?-(x):(x))
#define SQR(x) 	 ((x)*(x))
#define CUBE(x)  ((x)*(x)*(x))
#define pnl      printf("\n")
#define REP(i,n)        for(__typeof(n) i=0;i<(n);i++)
#define FOR(i,a,b)      for(__typeof(b) i=(a);i<(b);++i)
#define FORE(i,a,b)     for(__typeof(b) i=(a);i<=(b);++i)
#define FORD(i,a,b,d)   for(__typeof(b) i=(a);i<(b);i+=(d))
#define FORR(i,n,e)     for(__typeof(n) i=(n);i>=(e);--i)
#define FORRD(i,n,e,d)  for(__typeof(n) i=(n);i>=(e);i-=(d))
#define REP_IT(it,m)    for(it=m.begin();it!=m.end();it++)
#define FORI(it,s) 	    for(__typeof((s).begin()) (it)=(s).begin();(it)!=(s).end();(it)++)
#define FOREACH(it, X)  for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define UNIQUE(v)       sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(a,b)       memset(a,b,sizeof(a))
#define ALL(v)          (v).begin(), (v).end()
#define RALL(v)         (v).rbegin(), (v).rend()
#define checkbit(n,b)   (((n)>>(b))&1)
#define PB push_back
#define MP make_pair
#define XX first
#define YY second
#define lln long long int
#define gc getchar_unlocked
#define pc putchar_unlocked
inline void fr(lln *a)
{
    char c=0;
    *a=0;
    while(c<33)
        c=getchar();
    while(c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}

int main()
{
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    lln t,n,i,j,k,l;
    string p[105],q[105];
    cin>>t;
    FOR(l,1,t+1)
    {
        vector<lln > r[105];
        cin>>n;
        REP(i,n)
            cin>>p[i];
        REP(i,n)
        {
            q[i]="";
            q[i]+=p[i][0];
            r[i].PB(1);
            for(j=1; j<p[i].size(); j++)
            {
                if(p[i][j]!=q[i][q[i].size()-1])
                {
                    q[i]+=p[i][j];
                    r[i].PB(1);
                }
                else r[i][r[i].size()-1]++;
            }
        }


        for(i=1; i<n; i++)
        {
            if(q[i]!=q[0])
            {
                cout<<"Case #"<<l<<": ";
                cout<<"Fegla Won\n";
                break;
            }
        }
        if(i==n)
        {
            int ans=0;
            for(i=0; i<r[0].size(); i++)
            {
                int mn=MOD;
                REP(j,n)
                {
                    int sum=0;
                    REP(k,n)
                    {
                        sum=sum+abs(r[k][i]-r[j][i]);
                    }
                    if(sum<mn) mn=sum;
                }
                ans += mn;
            }
            cout<<"Case #"<<l<<": ";
            cout<<ans<<endl;
        }
    }
    return 0;
}
