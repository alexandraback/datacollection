#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

#define oo 1e9
#define pi 3.1415926536
#define all(x) x.begin(),x.end()
#define sorta(x) sort(all(x))
#define sortam(x,comp) sort(all(x),comp)
#define sortd(x) sort(x.rbegin(),x.rend())
#define pb push_back
#define mp make_pair
#define sf(x) scanf("%d", &x);
#define sfll(x) scanf("%I64d", &x);
#define pr(x) printf("%d ", x);

typedef long long ll;
using namespace std;

int r, c, n;
bool is[19][19];
int go(int i, int j, int left) {
	if(j == c) {
		if(i == r - 1) return !left ? 0 : oo;
		return go(i + 1, 0, left);
	}

	int ret = go(i, j + 1, left), tmp = 0;
	if(j && is[i][j - 1]) tmp++;
	if(i && is[i - 1][j]) tmp++;

	is[i][j] = 1;
	ret = min(ret, go(i, j + 1, left-1) + tmp);
	is[i][j] = 0;
	return ret;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	sf(t);
	for(int tc = 1; tc <= t; tc++) {
		sf(r); sf(c); sf(n);
		memset(is, 0, sizeof is);
		printf("Case #%d: ", tc);
		if(n <= r*c / 2) cout << 0 << endl;
		else cout << go(0, 0, n) << endl;
	}
	return 0;
}
