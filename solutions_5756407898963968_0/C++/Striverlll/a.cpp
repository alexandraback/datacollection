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
set <int> st[10], st1[10];
int main()
{
	int tt, n, i, j, n1, num, ans, k, cas = 0;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	cin >> tt;
	while (tt --) {
		cin >> n;
		printf("Case #%d: ", ++cas);
		for (i = 1; i <= 4; i ++) {
			st[i].clear();
			for (j = 1; j <= 4; j ++) {
				scanf("%d", &k); st[i].insert(k);
			}
		}
		cin >> n1;
		for (i = 1; i <= 4; i ++) {
			st1[i].clear();
			for (j = 1; j <= 4; j ++) {
				scanf("%d", &k); st1[i].insert(k);
			}
		}
		//set_union(st[n].begin(), st[n].end(), st1[n1].begin(), st1[n1].end, inserter(s,s.begin()));
		num = 0;
		for (i = 1; i <= 16; i ++) if (st[n].count(i) && st1[n1].count(i)) {
			num ++; ans = i;
		}
		if (num == 0) printf("Volunteer cheated!\n");
		else if (num >= 2) printf("Bad magician!\n");
		else cout << ans << endl;
	}
	return 0;
}