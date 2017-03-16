/* in the name of ALLAH, most gracious, most merciful */

#include <bits/stdc++.h>
using namespace std;

int n;
string a [110];
vector <int> mid [110];
vector <char> x;

vector <char> compress (string t) {
	vector <char> va;
	for (int i = 0; i < (int) t.size (); ++i) {
		if (!i) va.push_back (t [i]);
		else {
			if (va.back () == t [i])
				continue;
			va.push_back (t [i]);
		}
	}
	return va;
}

bool is_valid () {
	x = compress (a [0]);

	for (int i = 0; i < n; ++i)
		if (x != compress (a [i]))
			return false;

	return true;
}

void build (int idx) {
	string &s = a [idx];
	vector <int> &v = mid [idx];

	v.clear ();

	int i = 0;
	for (auto &c : x) {
		int cnt = 0;
		while (s [i++] == c) ++cnt;
		v.push_back (cnt);
	}
}

int cherry (int val, int idx) {
	int ret = 0;
	for (int i = 0; i < n; ++i)
		ret += abs (mid [i][idx] - val);
	return ret;
}

int main () {
#ifdef Local
	freopen ("A-large.in", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int cs = 1; cs <= t; ++cs) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a [i];

		printf ("Case #%d: ", cs);
		if (is_valid ()) {
			for (int i = 0; i < n; ++i)
				build (i);

			int ans = 0;
			int len = mid [0].size ();

			for (int i = 0; i < len; ++i) {
				int tmp = 0;
				for (int j = 0; j < n; ++j)
					tmp += mid [j][i];

				int try1 = tmp / n;
				int try2 = (tmp + n) / n;

				try1 = cherry (try1, i);
				try2 = cherry (try2, i);

				if (try1 < try2) ans += try1;
				else ans += try2;
			}

			printf ("%d\n", ans);
		} else puts ("Fegla Won");
	}
	return 0;
}

