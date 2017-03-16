#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cmath"
#include "cstring"
#include "cstdlib"
#include "climits"
#include "cassert"
#include "bitset"
#include "complex"
#include "queue"
#include "vector"
#include "queue"
#include "set"
#include "map"
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define rep(i, n) for(int i=0; i<n; i++)
#define repp(i, a, b) for(int i=a; i<a+b; i++)
using namespace std;
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MK make_pair
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ITR iterator
#define LB lower_bound
#define UB upper_bound
#define PII pair<int, int>
#define CLR(a) memset(a, 0, sizeof(a))
int getint(){
    int s = 0, o = 1;
    char c;
    for(c = getchar(); c<'0'||c>'9';c = getchar()) if(c=='-') o = -1;
    for(;c>='0'&&c<='9'; c = getchar()) s *=10, s+=c-'0';
    return s*o;
}

const int maxn = 2000;

int n, N, NN;
int a[maxn];
long long b[maxn];

bool enough(long long x){
	long long r = N;
	rep(i,n){
		r -= x / a[i];
		if(r<=0) return 0;
	}
	NN = r;
	return 1;
}

int main(int argc, char const *argv[])
{
	int cas = getint();
	rep(ca,cas){
		n = getint();
		int r1 = 0, r2 = 0, rate = 0;
		rep(i,n) a[i] = getint();
		rep(i, n-1) if(a[i] > a[i+1]){
			r1 += a[i] - a[i+1];
			rate = max(rate, a[i] - a[i+1]);
		}
		// if(rate%10!=0) rate = (rate/10 + 1) * 10;
		rep(i, n-1) r2 += min(a[i], rate);
		printf("Case #%d: %d %d\n", ca+1, r1, r2);
	}	
	return 0;
}