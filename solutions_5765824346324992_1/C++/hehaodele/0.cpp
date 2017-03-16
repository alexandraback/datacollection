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
		if(r<=100) return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int cas = getint();
	rep(ca,cas){
		n = getint(), N = getint();
		rep(i,n) a[i] = getint();
		long long l = 0, r = (long long)1e15;
		while(l+1<r){
			long long m = (l+r)/2;
			if(enough(m)) l = m; else r = m;
		}
		int NN = N;
		long long last = l;
		rep(i,n){
			NN -= l / a[i];
			b[i] = l / a[i] * a[i];
		}
		// printf("~~%I64d\n", l);
		// printf("~~%I64d\n",NN);
		// rep(i,n) printf("%I64d, %I64d  ", b[i], b[i] / a[i]); printf("\n");
		int j;
		rep(st,NN){
			j = 0;
			rep(i,n) if(b[i] < b[j]) j = i;
			b[j] += a[j];
			// printf("j %d\n", j);
		}
		printf("Case #%d: %d\n", ca+1, j+1);
	}	
	return 0;
}