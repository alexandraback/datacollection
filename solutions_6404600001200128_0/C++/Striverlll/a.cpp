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

int a[10000];
int main()
{
	int tt, ans, mm, n, cas = 0;
	cin >> tt;
	while (tt --) {
		cin >> n;
		for (int i = 1; i <= n; i ++) scanf("%d", a + i);
		printf("Case #%d:", ++cas);
		ans = 0; mm = 0;
		for (int i = 2; i <= n; i ++)
			if (a[i] < a[i - 1]) {
				ans += a[i - 1] - a[i];
				mm = max(mm, a[i - 1] - a[i]);
			}
		printf(" %d", ans);
		ans = 0;
		for (int i = 2; i <= n; i ++) {
			if (a[i - 1] > mm) ans += mm;
			else ans += a[i - 1];
		}
		printf(" %d\n", ans);
	}
	return 0;
}


