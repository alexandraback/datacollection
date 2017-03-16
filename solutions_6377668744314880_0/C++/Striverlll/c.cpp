#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define ll long long
#define pb push_back 
#define mp make_pair
#define FOR(x, l, r) for(x = (l); x <= (r); x++)
#define FORD(x, r, l) for(x = (r); x >= (l); x --)
using namespace std;

int x[4000], y[4000];
int main()
{
	ll sm;
	int tt, cas = 0, ln, rn, ansn, n;
	cin >> tt;
	while (tt --) {
		cin >> n;
		for (int i = 1; i <= n; i ++) scanf("%d%d", x + i, y + i);
		printf("Case #%d:\n", ++cas);
		for (int i = 1; i <= n; i ++) {
			ansn = n;
			if (n == 1) ansn = 0;
			for (int j = 1; j <= n; j ++)
				if (j != i) {
					ln = rn = 0;
					for (int k = 1; k <= n; k ++) {
						sm = (ll)(x[k] - x[i]) * (y[j] - y[i]) - (ll)(x[j] - x[i]) * (y[k] - y[i]);
						if (sm < 0) {
							ln ++;
							if (ln >= ansn && rn >= ansn) break;
						}
						if (sm > 0) {
							rn ++;
							if (rn >= ansn && ln >= ansn) break;
						}
					}
					ln = min(ln, rn);
					ansn = min(ansn, ln);
				}

		   printf("%d\n", ansn);
		}
	}
	return 0;
}


