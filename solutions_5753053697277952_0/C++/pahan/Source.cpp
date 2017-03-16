#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
using ll = long long;

void solve() {
	int n;
	scanf("%d", &n);
	vector<pair<int,int>> p(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i].first), p[i].second = i;
	while (true) {
		sort(p.begin(), p.end());
		reverse(p.begin(), p.end());
		if (p[0].first == 0)
			return;
		if (p[0].first != p[1].first || p.size() > 2 && p[2].first == p[1].first) {
			printf("%c ", 'A' + p[0].second);
			p[0].first--;
		}	else {
			printf("%c%c ", 'A' + p[0].second, 'A' + p[1].second);
			p[0].first--, p[1].first--;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(1);

	int tnumber = 0;
	cin >> tnumber;
	for (int tcase = 1; tcase <= tnumber; tcase++) {
		cout << "Case #" << tcase << ": ";
		solve();
		cout << endl;
	}
	
#ifdef LOCAL
	cerr << "time : " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}