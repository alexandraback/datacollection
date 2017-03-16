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
int num[200][200], top[200], tmp[200];
char word[200][200], st[200];
int main()
{
	int cas = 0, i, j, k, tt, flag, ans, n;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	cin >> tt;
	while (tt --) {
		cin >> n; flag = 0; ans = 0;
		FOR(i, 1, n) {
			scanf("%s", st);
			k = strlen(st);
			word[i][0] = st[0]; num[i][0] = 1; top[i] = 0;
			FOR(j, 1, k - 1) 
			if (st[j] != st[j - 1]){ top[i] ++; word[i][top[i]] = st[j]; num[i][top[i]] = 1; }
 				else num[i][top[i]] ++;
 			if (top[i] != top[1]) flag = 1;
 			FOR(j, 0, top[i]) if (word[i][j] != word[1][j]) flag = 1;
 			//cout << i << " " << top[i] << endl;
		}
		printf("Case #%d: ", ++cas);
		if (flag) { printf("Fegla Won\n"); continue; }
		ans = 0;
		for (i = 0; i <= top[1]; i ++) {
			FOR(j, 1, n) tmp[j] = num[j][i];
			sort(tmp + 1, tmp + n + 1);
			FOR(j, 1, n) ans += abs(tmp[(n + 1) / 2] - tmp[j]);
			//cout << i <<  " " << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
