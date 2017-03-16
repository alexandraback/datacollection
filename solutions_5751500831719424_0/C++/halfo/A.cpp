/* in the name of ALLAH, most gracious, most merciful */

#include <bits/stdc++.h>
using namespace std;

vector <char> compress (string a) {
	vector <char> va;
	for (int i = 0; i < (int) a.size (); ++i) {
		if (!i) va.push_back (a [i]);
		else {
			if (va.back () == a [i])
				continue;
			va.push_back (a [i]);
		}
	}
	return va;
}

bool is_valid (string a, string b) {
	return compress (a) == compress (b);
}

int main () {
#ifdef Local
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int cs = 1; cs <= t; ++cs) {
		int n;
		string a, b;
		cin >> n >> a >> b;

		printf ("Case #%d: ", cs);
		if (is_valid (a, b)) {
			vector <char> x = compress (a);

			int ans = 0, ia = 0, ib = 0;
			for (auto &c : x) {
				int cnta = 0;
				while (a [ia++] == c) ++cnta;

				int cntb = 0;
				while (b [ib++] == c) ++cntb;

				ans += abs (cnta - cntb);
			}

			printf ("%d\n", ans);
		} else puts ("Fegla Won");
	}
	return 0;
}

