#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 1000 + 5;
int n, index;
LL cut[maxn];

LL getHaveStartCut(LL x) {
	LL haveStartCut = 0;
	for (int i = 0; i < n; i++) {
		if (x % cut[i] == 0) haveStartCut += (x / cut[i]);
		else haveStartCut += (x / cut[i] + 1);
	}
	return haveStartCut;
}

int main() {
//freopen("in", "r", stdin);
//freopen("B-small-attempt2.in", "r", stdin);
//freopen("B-small-attempt2.out", "w", stdout);
//freopen("B-large.in", "r", stdin);
//freopen("B-large.out", "w", stdout);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d %d", &n, &index);
		for (int i = 0; i < n; i++) scanf("%lld", cut + i);

		LL ll = 0, rr = (LL)100000L * index + 5, mid;
//rr = 100;
		while (ll < rr) {
			mid = (ll + rr) / 2;
//printf("%lld %lld %lld %lld\n", ll, rr, mid, getHaveStartCut(mid));
			if (getHaveStartCut(mid) >= index) rr = mid;
			else ll = mid + 1;
		}
		LL cutTime = ll;
//printf("cutTIme=%lld\n", cutTime);
		int res = -2;
		int haveStartCut = getHaveStartCut(cutTime - 1);
		for (int i = 0, j = 0; i < n; i++) 
		if (cut[i] == 1 || cutTime % cut[i] == 1) {
			j++;
			if (j == index - haveStartCut) {
				res = i;
				break;
			}
		}

		printf("Case #%d: %d\n", ti, res + 1);
	}
	return 0;
}
