#include <stdio.h>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int r, c, n;

int nbit(int x) {
	int ans = 0;

	while (x > 0) {
		ans ++;
		x -= x&-x;
	}
	return ans;
}

bool vv(int t, int off) {
	if (t & (1<<off))
		return true;
	return false;
}

int nshare(int t) {
	int ans = 0;
	for  (int y=0; y<r; y++) {
		for (int x=0; x<c-1; x++) {
			int a = x + y*c;
			int b = x+1 +y*c;

			if (vv(t, a) && vv(t, b))
			ans ++;

		}
	}

	for  (int y=0; y<r-1; y++) {
		for (int x=0; x<c; x++) {
			int a = x + (y+1)*c;
			int b = x + y*c;

			if (vv(t, a) && vv(t, b))
			ans ++;

		}
	}

	return ans;

}

int solve()
{
	int ans = INT_MAX;
	for  (int t = 0; t < (1 <<(r*c)); t++) {
		if (nbit(t) != n) continue;

		ans = min (ans, nshare(t));
	}
	return ans;
}

int main()
{
	freopen("D:\\gcj\\a\\a.txt", "r", stdin);
	freopen("D:\\gcj\\a\\r.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	for (int icase=1; icase<=ncase; icase++) {
		scanf("%d %d %d", &r, &c, &n);
		printf_s("Case #%d: %d\n", icase,  solve());
	}
	

	return 0;
}