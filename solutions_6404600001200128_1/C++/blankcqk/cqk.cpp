#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <time.h>
#define maxn 2005
#define maxm 1000005
#define eps 1e-7
#define mod 998244353
#define INF 0x3f3f3f3f
#define PI (acos(-1.0))
#define lowbit(x) (x&(-x))
#define mp make_pair
//#define ls o<<1
//#define rs o<<1 | 1
//#define lson o<<1, L, mid 
//#define rson o<<1 | 1, mid+1, R
#define pii pair<int, int>
#pragma comment(linker, "/STACK:16777216")
typedef long long LL;
typedef unsigned long long ULL;
//typedef int LL;
using namespace std;
LL qpow(LL a, LL b){LL res=1,base=a;while(b){if(b%2)res=res*base;base=base*base;b/=2;}return res;}
LL powmod(LL a, LL b){LL res=1,base=a;while(b){if(b%2)res=res*base%mod;base=base*base%mod;b/=2;}return res;}
// head

int a[maxn];
int n;

void work(int _)
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans1 = 0, mx = 0, ans2 = 0;
	for(int i = 2; i <= n; i++) if(a[i-1] - a[i] > 0) ans1 += a[i-1] - a[i], mx = max(a[i-1]-a[i], mx);
	for(int i = 2; i <= n; i++) {
		int t = a[i-1] - mx;
		t = max(0, t);
		ans2 += a[i-1] - t;
	}
	printf("Case #%d: %d %d\n", _, ans1, ans2);
	
}

int main()
{
//	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int i = 1; i <= _; i++) work(i);

	return 0;
}
