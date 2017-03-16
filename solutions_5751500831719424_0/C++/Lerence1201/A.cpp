#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#define dou double
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%I64d", &(a))
#define RLL(a, b) scanf("%I64d%I64d", &(a), &(b))
#define RLLL(a, b, c) scanf("%I64d%I64d%I64d", &(a), &(b), &(c)) 
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%I64d\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FOR(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
//Segment tree
#define MID ((l + r) >> 1)
#define L (x << 1)
#define R ((x << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#pragma warning (disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 2000000000
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111

using namespace std;

int n, m, st[N], cnt[N][N], tot, a[N];
char s[N][N], t[N][N];

void get(int x) {
	int len = SL(s[x]), tt = 0;
	REP(i, len) {
		if (i == 0 || (i > 0 && s[x][i] != s[x][i - 1])) t[x][tt++] = s[x][i];
	}
	t[x][tt] = 0;
	tot = tt;
}

void getcnt(int x) {
	int len = SL(s[x]), now = 0;
	REP(i, len) {
		if (s[x][i] == t[x][now]) cnt[x][now]++;
		else now++, cnt[x][now] = 1;
	}
}

bool good() {
	get(1);
	REPP(i, 2, n) {
		get(i);
		if (strcmp(t[1], t[i])) return 0;
	}
	return 1;
}

int main(){
	int t, x, y, z, ca = 1;
	freopen("D:/Contest/in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	//ios :: sync_with_stdio(false);
	RI(t);
	while (t--) {
		printf("Case #%d: ", ca++);
		RI(n);
		REPP(i, 1, n) RS(s[i]);
		if (good()) {
			REPP(i, 1, n) getcnt(i);
			int ans = 0;
			REP(i, tot) {
				REPP(j, 1, n) a[j] = cnt[j][i];
				sort(a + 1, a + n + 1);
				REPP(j, 1, n) ans += abs(a[j] - a[(n + 1) / 2]);
			}
			PI(ans);
		}
		else puts("Fegla Won");
		mem(s), mem(cnt), mem(st), tot = 0;
	}
	
	

	return 0;
}
