#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

int r, c, n;

int nbad(const vector<vector<int> >& b)
{
	int bad = 0;
	FOR(y, r) FOR(x, c) {
		if (!b[y][x]) continue;
		if (x + 1 < c && b[y][x + 1]) bad++;
		if (y + 1 < r && b[y + 1][x]) bad++;
	}
	return bad;
}

#define TF(y, x) if (b[y][x] == 0) { \
		b[y][x] = 1;  \
		cnt++;  \
		if(cnt == n) return nbad(b);  \
	}

int solve(int offset)
{
	vector<vector<int> > b = vector<vector<int> >(r, vector<int>(c, 0));
	int cnt = 0;
	FOR(y, r) FOR(x, c) {
		b[y][x] = (offset+x+y)%2;
		cnt += b[y][x];
	}
	if (cnt >= n) return 0;
	TF(r-1, c-1);
	TF(0, c - 1);
	TF(r - 1, 0);
	TF(0, 0);
	FOR(x, c) {
		TF(0, x);
	}
	FOR(x, c) {
		TF(r - 1, x);
	}
	FOR(y, r) {
		TF(y, 0);
	}
	FOR(y, r) {
		TF(y, c - 1);
	}
	FOR(y, r) FOR(x, c) TF(y, x);
	return nbad(b);
}

int main(void)
{
	int T;
// 	freopen("/home/vesko/gcj/b.in", "rt", stdin);
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", tc, min(solve(0), solve(1)));
	}

	return 0;
}
