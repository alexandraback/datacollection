#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int T;
int cnt[26];
int n;

void load() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", cnt + i);
	}	
}

void solve(int tc) {
	vector<string> res;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += cnt[i];
	}
	while (sum > 0) {
		int mx = 0;
		int amount = 0;
		for (int i = 0; i < n; ++i) {
			if (cnt[i] > mx) {
				mx = cnt[i];
				amount = 0;
			}	
			if (cnt[i] == mx) {
				++amount;
			}
		}
		if (sum == 3) {
			for (int i = 0; i < n; ++i) {
				if (mx == cnt[i]) {
					string tmp = "A";
					--cnt[i];
					--sum;
					tmp[0] += i;
					res.pb(tmp);
					break;
				}
			}
			continue;
		}
		if (amount == 1) {
			for (int i = 0; i < n; ++i) {
				if (cnt[i] == mx) {
					if (mx == 1) {
						--cnt[i];
						string tmp = "A";
						tmp[0] += i;
						res.pb(tmp);
						sum -= 1;
					} else {
						cnt[i] -= 2;
						string tmp = "AA";
						tmp[0] += i;
						tmp[1] += i;
						res.pb(tmp);
						sum -= 2;
					}
					break;
				}
			}
		} else {
			int found = 0;
			string tmp = "AA";
			for (int i = 0; found < 2; ++i) {
				if (cnt[i] == mx) {
					if (mx == cnt[i]) {
						--cnt[i];
						tmp[found] += i;
						++found;
						--sum;
					}
				}
			}
			res.pb(tmp);
		}
	}
	printf("Case #%d: ", tc);
	for (auto it : res) {
		cout << it << ' ';
	}
	cout << endl;
}

void clear() {
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		clog << "Testcase " << tc << endl;
		load();
		solve(tc);
		clear();
	}
	return 0;
}