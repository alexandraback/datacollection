#include <bits/stdc++.h>
#define NDEBUG
#include <cassert>
#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define log_error(M, ...) fprintf(stderr, "[assert] (%s:%d-errno:%s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define assertf(A, M, ...) if(!(A)) {log_error(M, ##__VA_ARGS__); assert(A); }
#include <climits>
#include <cfloat>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

inline unsigned int rand16(){return ((rand()) << 15) ^ rand();}
inline unsigned int rand32(){return (rand16() << 16) | rand16();}
inline ULL rand64(){return ((LL)rand32() << 32) | rand32();}
inline ULL random(LL l, LL r){return l == r ? l : rand64() %(r-l) +l;}
inline double fRand(double fMin, double fMax) // RAND_MAX: [fMin,fMax)
	{ double f = (double)rand()/(RAND_MAX+1.0f); return fMin + f*(fMax-fMin); }

const int INF = 0x3f3f3f3f;
const LL INFF = 1LL<<60;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);//2*acos(0.0);//M_PI;

//4 dirs anti-cw: int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
//4 dirs cw:      int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
//8 dirs: int dx[]={1,1,0,-1,-1,-1,0,1}, dy[]={0,1,1,1,0,-1,-1,-1};
//hex: int dx[6]={2,1,-1,-2,-1,1}, dy[6]={0,1,1,0,-1,-1};
//knight: int dx[]={2,1,-1,-2,-2,-1,1,2}, dy[]={1,2,2,1,-1,-2,-2,-1};

#define FOR(i,a,b)   for(int(i)=int(a);(i)<int(b);(i)++)
#define FOREQ(i,a,b) for(int(i)=int(a);(i)<=int(b);(i)++)
#define RFOR(i,a,b)  for(int(i)=(a),_b(b);(i)>=_b;--(i))
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define FILL(arr,val) memset((arr),(val),sizeof(arr))
#define CLR(a)        memset((a),0,sizeof(a))
#define CPY(dest,src) memcpy((dest),(src),sizeof(dest))

#define ALL(a)       (a).begin(),(a).end()
#define SZ(a)        ((int)(a).size())
#define UNIQ(a)      sort(ALL(a)); (a).erase(unique(ALL(a)),(a).end())
#define IDX(arr,ind) (lower_bound(ALL(arr),ind)-arr.begin())

#define fst first
#define snd second
#define pb  push_back
#define mp  make_pair
#define mt(a,b,c) mp(a,mp(b,c))

#include <sys/resource.h>
struct rlimit rl;
#define set_stk_sz \
	getrlimit(RLIMIT_STACK,&rl); \
	rl.rlim_cur=16*1024*1024; \
	setrlimit(RLIMIT_STACK, &rl);

template< typename T, size_t N >
inline void print_ary(T(&ary)[N], int er)
	{for(int r = 0; r < er; r++) {cout << ary[r] << " ";}cout<<endl;}
template< typename T, size_t N >
inline void print_ary_eq(T(&ary)[N], int er)
	{for(int r = 1; r <= er; r++) {cout << ary[r] << " ";}cout<<endl;}
template< typename T, size_t N, size_t M >
inline void print_ary_2d(T(&ary)[N][M], int er, int ec)
	{for(int r = 0; r < er; r++) {for(int c = 0; c < ec; c++) {cout << ary[r][c] << " ";}cout<<endl;}}
template< typename T, size_t N, size_t M >
inline void print_ary_2d_eq(T(&ary)[N][M], int er, int ec)
	{for(int r = 1; r <= er; r++) {for(int c = 1; c <= ec; c++) {cout << ary[r][c] << " ";}cout<<endl;}}
inline LL lcm(LL a, LL b) {return a*b/__gcd(a,b);}
inline double dist(double x1, double y1, double x2, double y2)
	{return hypot(x1-x2,y1-y2);}
//scanf("%[^\n]", &s);
inline int is_pow_of_2(unsigned int x) {return ((x!=0) && ((x&(~x+1))==x));}

//#leading 0-bits in x (32bit fixed width representation); x=0: undefined
inline int clz(int N) {return N ? 32 - __builtin_clz(N) : INT_MIN;}
inline int clz(ULL N) {return N ? 64 - __builtin_clzll(N) : 0;}
//#trailing 0-bits
inline int ctz(int n){return (n==0?-1:ctz(n>>1)+1);}
//#1-bits set
#define bitcnt   __builtin_popcount
#define bitcntll __builtin_popcountll

#define bin_width 32
inline char* bin(int x,char *so){char s[bin_width+1];int i=bin_width;s[i--]=0x00;do{s[i--]=(x&1)?'1':'0';x>>=1;}while(x>0);i++;sprintf(so,"%s",s+i);return so;}
//USAGE: char buf[bin_width+1];printf("%s",bin(N,buf));

/*
const int MAXN = 10005;
int fact[MAXN];
#define FACT fact[0]=1;FOR(i,1,MAXN){fact[i]=(1LL*fact[i-1]*i)%MOD;}
inline LL modinv(int a, int b=MOD-2) {LL x=1,y=a;while(b){if(b&1)x=(x*y)%MOD;y=(y*y)%MOD;b>>=1;}return x;}
// nCr
inline LL c(int n, int r) {return ((((1LL*fact[n]*modinv(fact[n-r]))%MOD)*modinv(fact[r]))%MOD);}
*/

int N, m[10005];

int main()
{
	int T; scanf("%d", &T);
	FOREQ(t,1,T)
	{
		scanf("%d", &N);
		FOR(i,0,N)
		{
			scanf("%d", &m[i]);
		}
		int a1 = 0, dmax = 0;
		FOR(i,1,N)
		{
			if (m[i] < m[i-1])
			{
				a1 += m[i-1]-m[i];
				dmax = max(dmax, m[i-1]-m[i]);
			}
		}
		int a2 = dmax*(N-1);
		FOR(i,0,N-1)
		{
			if (m[i] < dmax)
			{
				a2 = a2 - dmax + m[i];
			}
		}
		printf("Case #%d: %d %d\n", t,a1,a2);
	}
	return 0;
}
