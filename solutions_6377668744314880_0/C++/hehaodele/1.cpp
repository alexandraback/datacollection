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

struct node{
	int x, y;
	// bool operator< (const node &p)const{
		// return (x==p.x)? y<p.y: x<p.x;
	// }
	int ans, id;
}a[maxn], s[maxn], b[maxn];

node *na[maxn], *ns[maxn], *nb[maxn];

bool cmp (node *a, node *b){
	return (a->x == b->x) ? a->y < b->y: a->x < b->x;
}

long long cross(node *a, node *b, node *c){
	int x1 = b->x - a->x, y1 = b->y - a->y;
	int x2 = c->x - a->x, y2 = c->y - a->y;
	return 1l * x1 * y2 - 1ll * x2 * y1;
}

int convex(int n, node **a, node **s){
	int r = 0;
	for(int i=0; i<n; i++){
		while(r>1 && cross(s[r-2], s[r-1], a[i])<=0) r--;
		s[r++] = a[i];
	}
	int tmp = r;
	for(int i=n-2; i>=0; --i){
		while(r>tmp && cross(s[r-2], s[r-1], a[i])<=0) r--;
		s[r++] = a[i];
	}
	return r>1? r - 1: r;
}

int n;
int main(int argc, char const *argv[])
{
	rep(i,maxn) na[i] = &a[i], ns[i] = &s[i];
	int cas = getint();
	rep(ca,cas){
		n = getint();
		rep(i,n) scanf("%d%d", &a[i].x, &a[i].y), a[i].id = i;
		rep(i,n) a[i].ans = n;
		sort(na, na+n, cmp);
		int r = convex(n, na, ns);

		int all = (1<<n), msk = 0;
		rep(st,all){
			int len = 0, have = 0, nn = 0;
			for(int i=0; i<n; ++i) if((st>>i)&1){
				len += (st>>i) & 1;
				nb[nn++] = na[i];
			}
			r = convex(nn, nb, ns);
			rep(i,r) ns[i]->ans = min(ns[i]->ans, n - len);
		}
		printf("Case #%d: \n", ca+1);
		rep(i,n) printf("%d\n", a[i].ans);
	}
	return 0;
}