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

int gcd(int a, int b) {
	while(b){
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main(int argc, char const *argv[])
{
	int cas = getint();
	rep(ca,cas){
		n = getint(), N = getint();
		rep(i,n) a[i] = getint();
		int lcm = a[0];
		rep(i,n-1) lcm = lcm * a[i+1] / gcd(lcm, a[i+1]);
		int all = 0;
		rep(i,n) all += lcm / a[i];
		N %= all;
		// printf("~~ %d %d %d\n", lcm, all, N);
		if(N==0) N = all;
		rep(i,n) b[i] = 0;
		int j = n-1;
		rep(st,N){
			j = 0;
			rep(i,n) if(b[j] > b[i]) j = i;
			b[j] += a[j];
		}
		printf("Case #%d: %d\n", ca+1, j+1);
	}	
	return 0;
}