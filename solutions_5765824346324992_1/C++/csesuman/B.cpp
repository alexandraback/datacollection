#include<bits/stdc++.h>

using namespace std;

#define in(a,x,y) (a>=x && a<=y)
#define out(a,x,y) (!in(a,x,y))
#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back

#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)|(b))
#define XOR(a,b) ((a) ^ (b))
#define xx first
#define yy second
#define mp make_pair
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))

#define LB(a,x) (lower_bound(all(a),x)-a.begin()) // first element in the range [first,last) which does not compare less than val.
#define UB(a,x) (upper_bound(all(a),x)-a.begin()) // first element in the range [first,last) which compares greater than val.
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define left nokol_left
#define right nokol_right
#define countbit(x) __builtin_popcountll((ll)x)
#define PQ priority_queue
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<class T>T __sqr(const T x){return x*x;}
template< class T, class X > inline T __pow(T a,X y) {T z=1; rep(i,1,y){z*=a;} return z; }
template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return __gcd(b,a%b);}
template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/__gcd(a,b))*b;}
inline bool ispow2(int x){return (x!=0 && (x&(x-1))==0);}
template<class T>void UpdateMin(T &x,T y){ if(y<x){x=y;}}
template<class T>void UpdateMax(T &x,T y){if(x<y){x=y;}}
template<class T,class X, class Y > inline T bigmod(T n,X m,Y mod){ull ret=1, a = n%mod ; while(m){ if(m&1)ret=(ret*a)%mod; m>>=1; a=(a*a)%mod; }ret%=mod;return (T)ret;}
template<class T, class Y > inline T modinv(T n,Y mod) {return bigmod(n,mod-2,mod);}

template<class T,class X> int getbit(T s,X i) { return (s >> i) & 1; }
template<class T,class X> T onbit(T s, X i) { return s | (T(1) << i); }
template<class T,class X> T offbit(T s, X i) { return s & (~(T(1) << i)); }
template<class T> inline void read(T &n){char c;for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar()); n = c - '0';for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';}

const ll mod[] ={0,1000000007,1000000009,1000000021,1000000033,1000000097,1000000093,1000000097,1000000103};
const ll base[] ={0,1000003,1000033,1000037,1000039,1000081,1000099,1000117,1000121};

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define eps 1e-9
#define MX (lmt + 20 )
#define inf 1000000000000010LL
//---------->0123456789123465789
#define lmt 1000

long long bar[MX];
//vector< int >v;

int main()
{
    READ("B-large.in");
    WRITE("B-large.out");

    long long ts , n , b , kk  =1   ;
    cin>>ts;
    while(ts--){

        cin>>b;
        cin>>n;
        rep(i,1,b){
            cin>>bar[i];
        }

        long long ans = 0, lo , hi , pre = 0;

        lo = 0; hi = inf;
        while(lo<=hi){

//    cout<<lo<<" "<<hi<<endl;

            long long m  = (lo + hi) / 2;
            long long tot = 0;
            rep(i,1,b){
                tot += m/bar[i];

                if(m%bar[i]!=0) tot++;
            }

//            cout<<"t "<<tot<<" "<<n<<endl;

            if(tot>=n) hi = m - 1;
            else{
                ans = max(ans , m);
                pre = max(pre , tot);

                lo = m + 1;
            }
        }

//        cout<<ans<<endl;

        int res = -1;
        rep(i,1,b){
            if(ans%bar[i]==0)
            {
                pre++;
                if(pre==n){
                    res = i;
                    break;
                }
            }
        }

        cout<<"Case #"<<kk++<<": "<<res<<endl;
    }

    return 0;
}
