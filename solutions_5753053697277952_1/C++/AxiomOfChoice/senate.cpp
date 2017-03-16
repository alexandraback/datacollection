#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define bit(x,i) ((x>>i)&1)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)
#define fst first
#define snd second
#define tup make_tuple

int cnt[26];
char buf[3];

void work() {
	int n;
	scanf("%d", &n);

	int tot = 0;
	set<pii> cnt;
	rep(i, n) {
		int x;
		scanf("%d", &x);
		cnt.emplace(x, i);
		tot += x;
	}

	if(tot % 2) {
		pii a = *cnt.rbegin();
		cnt.erase(a);
		assert(a.fst * 2 <= tot);
		tot--;
		if(a.fst > 1) cnt.emplace(a.fst - 1, a.snd);
		buf[0] = a.snd + 'A';
		buf[1] = 0;
		printf(" %s", buf);
	}

	while(cnt.size() >= 2) {
		pii a = *cnt.rbegin();
		cnt.erase(a);
		pii b = *cnt.rbegin();
		cnt.erase(b);

		assert(a.fst * 2 <= tot);
		tot -= 2;
		if(a.fst > 1) cnt.emplace(a.fst - 1, a.snd);
		if(b.fst > 1) cnt.emplace(b.fst - 1, b.snd);

		buf[0] = a.snd + 'A';
		buf[1] = b.snd + 'A';
		printf(" %s", buf);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	rep(t, n) {
		printf("Case #%d:", t + 1);
		work();
		printf("\n");
	}
	return 0;
}
