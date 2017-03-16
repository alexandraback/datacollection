/*  */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <functional>
#include <iterator>
#include <iomanip>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")

#define sti				set<int>
#define stpii			set<pair<int, int> >
#define mpii			map<int,int>
#define vi				vector<int>
#define pii				pair<int,int>
#define vpii			vector<pair<int,int> >
#define rep(i, a, n) 	for (int i=a;i<n;++i)
#define per(i, a, n) 	for (int i=n-1;i>=a;--i)
#define clr				clear
#define pb 				push_back
#define mp 				make_pair
#define fir				first
#define sec				second
#define all(x) 			(x).begin(),(x).end()
#define SZ(x) 			((int)(x).size())
#define lson			l, mid, rt<<1
#define rson			mid+1, r, rt<<1|1

const int maxn = 30;
int c[maxn], id[maxn];
int cc[maxn];
char s[1005];
int n, tot;

bool comp(const int& a, const int& b) {
	return c[a] > c[b];
}

void solve() {
	rep(i, 0, 26) id[i] = i;
	vector<pair<char,char> > ans;
	pair<char,char> p;
	int b1, b2;
	int m;
	
	#ifndef ONLINE_JUDGE
	// memcpy(cc, c, sizeof(c));
	#endif

	while (1) {
		p.fir = p.sec = '\0';
		// m = 0;
		// if (tot <= 2) {
			// rep(i, 0, n) {
				// rep(j, 0, c[i]) {
					// s[m++] = i + 'A';
				// }
			// }
			// if (tot >= 1)
				// p.fir = s[0];
			// if (tot >= 2)
				// p.sec = s[1];
			// ans.pb(p);
			// break;
		// }

		sort(id, id+26, comp);
		if (c[id[0]] == 0)	break;

		#ifndef ONLINE_JUDGE
		// assert(c[id[1]] > 0);
		#endif

		if (c[id[2]] == 0) {
			// only two left
			p.fir = id[0] + 'A';
			p.sec = id[1] + 'A';
			--c[id[0]];
			--c[id[1]];
		} else {
			p.fir = id[0] + 'A';
			--c[id[0]];
		}
		
		ans.pb(p);
	}

	int sz = SZ(ans);

	rep(i, 0, sz) {
		putchar(' ');
		if (ans[i].fir)
			putchar(ans[i].fir);
		if (ans[i].sec)
			putchar(ans[i].sec);
		
		#ifndef ONLINE_JUDGE
		// bool flag = true;
		// int tot = 0;
		// if (ans[i].fir) --cc[ans[i].fir - 'A'];
		// if (ans[i].sec) --cc[ans[i].sec - 'A'];
		
		// rep(i, 0, n) {
			// if (cc[i] < 0) {
				// flag = false;
			// }
			// tot += cc[i];
		// }
		
		// int mx = 0;
		// rep(i, 0, n) {
			// mx = max(mx, c[i]);
		// }
		
		// if (mx > tot/2.0) flag = false;
		// assert(flag);
		#endif
	}
	putchar('\n');
}

int main() {
	ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		// freopen("data.in", "r", stdin);
		// freopen("data.out", "w", stdout);
	#endif

	int t;

	scanf("%d", &t);
	rep(tt, 1, t+1) {
		tot = 0;
		memset(c, 0, sizeof(c));
		scanf("%d", &n);
		rep(i, 0, n) {
			scanf("%d", &c[i]);
			tot += c[i];
		}
		printf("Case #%d:", tt);
		solve();
	}

	#ifndef ONLINE_JUDGE
		// printf("time = %ldms.\n", clock());
	#endif

	return 0;
}
