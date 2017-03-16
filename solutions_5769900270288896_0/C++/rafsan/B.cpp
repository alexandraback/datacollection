/*
online judge :
author       : rafsan
algorithm    :
*/

#include<iostream>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<climits>
#include<functional>
#include<fstream>
#include<istream>
#include<iterator>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>


using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b-1);i>=(a);i--)
#define FOREACH(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)

#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define PCC pair<char,char>
#define PIC pair<int,char>
#define PCI pair<char,int>
#define FST first
#define SEC second
#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)
#define RADIANS(x) (((1.0 * x * PI) / 180.0))
#define DEGREES(x) (((x * 180.0) / (1.0 * PI)))
#define SINE(x) (sin(RADIANS(x)))
#define COSINE(x) (cos(RADIANS(x)))
#define SETBIT(x, i) (x |= (1 << i))
#define TANGENT(x) (tan(RADIANS(x)))
#define ARCSINE(x) (DEGREES((asin(x))))
#define RESETBIT(x, i) (x &= (~(1 << i)))
#define ARCCOSINE(x) (DEGREES((acos(x))))
#define ARCTANGENT(x) (DEGREES((atan(x))))
#define FASTIO ios_base::sync_with_stdio(0);cin.tie();
#define IN scanf
#define OUT printf
#define SI(a) scanf("%d",&a)
#define SL(a) scanf("%lld",&a)
#define SD(a) scanf("%lf",&a)
#define OI(a) printf("%d",a)
#define OL(a) printf("%lld",a)
#define OD(a) printf("%lf",a)
#define LL long long
#define ULL unsigned long long
#define EPS 1e-9
#define MOD 1000000007
#define LIM 4

//TYPE CONVERSION
template<typename T>inline string toString(T a){ostringstream os("");os<<a;return os.str();}
template<typename T>inline LL toLong(T a){LL res;istringstream os(a);os>>res;return res;}
template<typename T>inline int toInt(T a){int res;istringstream os(a);os>>res;return res;}
template<typename T>inline double toDouble(T a){double res;istringstream os(a);os>>res;return res;}
//MATHEMATICS
template<typename T>inline T  SQ(T a){return a*a;}
template<typename T>inline T GCD(T a, T b){if (b == 0)return a;else return GCD(b, a % b);}
template<typename T>inline T LCM(T a, T b){LL res=a*b; res/=GCD(a,b);return res;}
template<typename T>inline ULL BIGMOD(T a, T b, T m){if (b == 0)return 1;else if (b % 2 == 0)return SQ(BIGMOD(a, b / 2, m)) % m;else return (a % m*BIGMOD(a, b - 1, m)) % m;}
template<typename T>inline VS PARSE(T str){VS res;string s;istringstream os(str);while(os>>s)res.PB(s);return res;}
template<typename T>inline ULL  DIST(T A,T B){ULL res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);return res;}
template<typename T>inline LL  CROSS(T A,T B,T C){return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);}
template<typename T>inline double cosAngle(T a,T b,T c){double res=a*a+b*b-c*c;res=res/(2*a*b);res=acos(res);return res;}
template<typename T>inline T POWER(T base,int po){T res=1;if(base==0)return 0;FOR(i,0,po)res*=base;return res;}
//BIT
template<typename T>inline bool IS_ON(T mask,T pos){return mask&(1<<pos);}
template<typename T>inline int OFF(T mask,T pos){return mask^(1<<pos);}
template<typename T>inline int ON(T mask,T pos){return mask|(1<<pos);}
//MOVEMENT INSIDE GRID
//template<typename T>inline bool INSIDE_GRID(int R,int C,int ro,int clm){if(R>=0&&C>=0&&R<ro&&C<clm)return 1;return 0;}
template<typename T>inline void PRINT_GRID(T GRID,int ro,int clm){DEBUG(GRID);FOR(i,0,ro){FOR(j,0,clm)cout<<GRID[i][j]<<" ";puts("");}}

int dx4[]= {0,0,1,-1};
int dy4[]= {-1,1,0,0};
//int dx8[]={0,0,1,1,1,-1,-1,-1};
//int dy8[]={1,-1,-1,0,1,-1,0,1};
int g[100][100];
bool INSIDE_GRID(int R,int C,int ro,int clm){if(R>=0&&C>=0&&R<ro&&C<clm)return 1;return 0;}
bool check(int r,int c,int R,int C)
{
    //cout<<r<<" "<<c<<" "<<R<<" ad "<<C<<endl;
    if(INSIDE_GRID(r,c,R,C)&&g[r][c]==1)
    {
       return 1;
    }
    return 0;
}
int simulate(int mask,int r,int c)
{

    int bit,res=0;
    FOR(i,0,r)FOR(j,0,c)g[i][j]=0;
    FOR(i,0,r)
    FOR(j,0,c)
    {
        bit=i*c+j;
        if(mask&(1<<bit))
        {
           g[i][j]=1;
        }
    }

    FOR(i,0,r)
    {
        FOR(j,0,c)
        if(g[i][j])
        {
            FOR(k,0,4)
            if(check(i+dx4[k],j+dy4[k],r,c))
            {
                res++;
            }
            g[i][j]=0;
        }
    }
    return res;
}
int  get(int r,int c,int n)
{
    int lim=(1<<(r*c));
    int res=INF;
    FOR(i,0,lim)
    {
        if(__builtin_popcount(i)==n)
        {
            res=min(res,simulate(i,r,c));
        }
    }
    return res;
}

int main()
{
   freopen("B-small-attempt0.in","r",stdin);
   freopen("B-small-attempt0.txt","w",stdout);
    int ks;

    int n,r,c;
    scanf("%d",&ks);
    FOR(cas,1,ks+1)
    {
    scanf("%d%d%d",&r,&c,&n);
    printf("Case #%d: %d\n",cas,get(r,c,n));
    }

    return 0;
}
/*

*/
