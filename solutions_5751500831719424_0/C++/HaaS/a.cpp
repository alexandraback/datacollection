#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

const int maxN = 1000 + 10;

string s[maxN];
vector <pie> S[maxN];

vector <pie> normal (string s) {
	vector <pie> ans;
	for (int i = 0; i < s.size(); ) {
		int j = i;
		while (j < s.size() && s[j] == s[i]) j++;
		ans.push_back (pie (s[i], j - i));
		i = j;
	}
	return ans;
}

int solve() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> s[i], S[i] = normal(s[i]);

	int l = S[0].size();
	for (int i = 0; i < n; i++)
		if (S[i].size() != l) return -1;

	int res = 0;
	for (int i = 0; i < l; i++) {
		vector <int> v;
		for (int j = 0; j < n; j++) {
			if (S[j][i].ff != S[0][i].ff) return -1;
			v.push_back (S[j][i].ss);
		}
		sort (v.begin(), v.end());
		for (int i = 0; i < n; i++)
			res += abs (v[i] - v[n / 2]);
	}
	return res;
}

main() {
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		int res = solve();
		if (res == -1)
			cout << "Case #" << o << ": " << "Fegla Won" << endl; 
		else
			cout << "Case #" << o << ": " << res << endl; 
	}

	return 0;
}
