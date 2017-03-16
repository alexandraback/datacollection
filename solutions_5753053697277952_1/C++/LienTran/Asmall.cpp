#include <bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()
#define rep(i, n) for(int i = 0, _ = (n); _ < n; ++i)
#define ufor(i, a, b) for(int i = (a); _ = (b); i <= _; ++i)
#define dfor(i, a, b) for(int i = (a); _ = (b); i >= _; --i)

typedef pair<int, char> IC;

void solve() {
	int n;
	priority_queue< IC > q;
	scanf("%d", &n);
	int sum  = 0;
	for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        q.push(make_pair(x, i + 'A'));
	}
	while (!q.empty()) {
        IC x = q.top(); q.pop();
        --x.first;
        --sum;
        if (x.first) q.push(x);

        if (!q.empty() && q.top().first * 2 > sum) {
            IC y = q.top(); q.pop();
            --y.first;
            --sum;
            if (y.first) q.push(y);
            if (q.empty()) printf("%c%c\n", x.second, y.second);
            else printf("%c%c ", x.second, y.second);
        } else {
            if (q.empty()) printf("%c\n", x.second);
            else printf("%c ", x.second);
        }
	}
}

int main() {
    freopen("in", "r", stdin);
    freopen("outSmall", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int tc = 1; tc <= ntest; ++tc) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
