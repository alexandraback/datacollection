#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int num[10010], n;

void input() {
	scanf("%d", &n);
	for(int i = 0;i < n;i ++) scanf("%d", &num[i]);
}

void solve() {
	int res1 = 0;
	for(int i = 1;i < n;i ++) if(num[i] < num[i-1]) res1 += num[i-1] - num[i];

	int rate = 0;
	for(int i = 0;i < n;i ++) if(num[i-1] - num[i] > rate) rate = num[i-1] - num[i];

	int res2 = 0;
	for(int i = 1;i < n;i ++) {
		if(num[i-1] > rate) res2 += rate;
		else res2 += num[i-1];
	}
	printf("%d %d\n", res1, res2);
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Case;
	scanf("%d", &Case);
	for(int cas = 1;cas <= Case;cas ++) {
		input();
		printf("Case #%d: ", cas);
		solve();
	}
}