/****************************************************************************
 *                                                                          *
 *                    ==>> BG_PeaceMind(BISHAL)                             *
 *                   try=0; while(!success) try++;                          *
 ****************************************************************************/
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
using namespace std;
typedef long long ll;
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/************************************************************************
 * /////////////////////////////////////////////////////////////////////*
 ************************************************************************/
/// [ Look at my code below, My code is so amazing !! :P ]
///  Digit    0123456789
#define MX    2005
#define inf   2000005

int r,c,n;

//int go(int p,int sm,int pv) {
//    if(p==r) {
//        if(sm==n) return 0;
//        else return inf;
//    }
//    int &ret=dp[p][pv][sm];
//    ret=inf;
//    if(p==0) {
//        ret=min(ret, pre[ c ] [ pv ] )
//    }
//
//}

int ar[20];

int Calc(int msk) {
    int cnt=0;
    for(int j=1; j<c; j++) {
        int x=(msk&(1<<(j-1)));
        int y=(msk&(1<<j));
        if(x&&y)cnt++;
    }
    return cnt;
}

int Calc2(int m1,int m2) {
    int cnt=0;
    for(int j=0; j<c; j++) {
        int x=(m1&(1<<j));
        int y=(m2&(1<<j));
        if(x&&y)cnt++;
    }
    return cnt;
}

int main() {
    int tc,cs=1,i,j,k;
     freopen("B-small-attempt0.in", "r", stdin);
     freopen("Out_B.txt", "w", stdout);
    S(tc);
    while(tc--) {
        S2(r,c);
        // if(r*c==0)
        S(n);
        int m=(r*c);
        int lim=(1<<m)-1,mn=inf;
        // cout<<r<< " "<<c<< " "<<m<< " "<<lim<<endl;
        for(int i=0; i<=lim; i++) {

            // if(i==495 )cout<< " WOW\n";
            if( __builtin_popcount(i)!=n )continue;

            int k=-1,bp=0,msk=0;
            // if(i==495)cout<<m<<endl;
            for(int j=0; j<m; j++) {
                int x=(i&(1<<j));

                if(j%c==0) {
                    ++k;
                    // if(i==495)cout<<ar[k-1]<<endl;
                    bp=0;
                    ar[k]=0;
                }

                if(x!=0)ar[k]=(ar[k]|(1<<bp) );
                bp++;
            }

           // cout<<k<< " ? \n";
            int tot=0;
            for(j=0; j<=k; j++) {
                //cout<<ar[j]<<endl;
                tot+=Calc( ar[j] );
            }

            for(j=1; j<=k; j++) {
                tot+=Calc2(ar[j-1],ar[j]);
            }

            mn=min(mn, tot);

        }
        printf("Case #%d: %d\n",cs++,mn);

    }

    return 0;
}
