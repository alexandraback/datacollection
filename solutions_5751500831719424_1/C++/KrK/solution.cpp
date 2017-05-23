#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int t;
int n;
string s;
string all, my;
int freq[Maxn][Maxn];
int res;

int main()
{
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (ok) {
				my = "";
				for (int j = 0; j < s.length(); j++)
					if (j == 0 || my[my.length() - 1] != s[j]) {
						my += string(1, s[j]); freq[my.length() - 1][i] = 1;
					} else freq[my.length() - 1][i]++;
				if (i == 0) all = my;
				else ok = all == my;
			}
		}
		cout << "Case #" << tc << ": ";
		if (ok) {
			res = 0;
			for (int j = 0; j < all.length(); j++) {
				sort(freq[j], freq[j] + n);
				int tk = freq[j][n / 2];
				for (int k = 0; k < n; k++)
					res += abs(tk - freq[j][k]);
			}
			cout << res << endl;
		} else cout << "Fegla Won\n";
	}
	return 0;
}