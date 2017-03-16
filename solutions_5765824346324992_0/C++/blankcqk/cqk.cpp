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

set<int> s;
set<int>::iterator it;
LL a[maxn];
int n, m;

bool check(LL x)
{
	LL ans = 0;
	for(int i = 1; i <= m; i++) {
		ans += x / a[i] + 1;
	}
	return ans >= n;
}

void work(int _)
{
	scanf("%d%d", &m, &n);
	LL top = 1e16, bot = 0, mid, res;
	for(int i = 1; i <= m; i++) scanf("%lld", &a[i]);
	while(top >= bot) {
		mid = (top + bot) >> 1;
		if(check(mid)) res = mid, top = mid-1;
		else bot = mid+1;
	}
	int ans = 0;
	s.clear();
	for(int i = 1; i <= m; i++) {
		n -= res / a[i] + 1;
		if(res % a[i] == 0) {
			n++;
			s.insert(i);
		}
	}
	it = s.begin();
	for(int i = 1; i < n; i++, it++);
	printf("Case #%d: %d\n", _, *(it));

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
