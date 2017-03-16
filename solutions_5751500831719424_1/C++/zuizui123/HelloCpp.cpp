#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define fi "A-large.in"
#define fo "out.txt"
const int MAXN = 100 + 5;
const int INF = 1000000000;

int T, N;
string a[MAXN], b[MAXN];
int ind[MAXN], temp[MAXN];

string simplize(string);

int main() {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < N; ++i) {
			b[i] = simplize(a[i]);
		}
		bool flag = true;
		for (int i = 1; i < N; ++i) {
			if (b[i] != b[i - 1]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			int res = 0;
			for (int i = 0; i < N; ++i) {
				ind[i] = 0;
			}
			for (int i = 0; i < b[0].length(); ++i) {
				int count = 0;
				for (int k = 0; k < N; ++k) {
					temp[k] = ind[k];
					while (temp[k] + 1 < a[k].length() && a[k][temp[k] + 1] == a[k][temp[k]]) {
						++temp[k];
					}
					count += temp[k] - ind[k] + 1;
				}
				count /= N;
				for (int k = 0; k < N; ++k) {
					int rep = temp[k] - ind[k] + 1;
					res += abs(rep - count);
					ind[k] = temp[k] + 1;
				}
			}
//			for (int i = 0; i < N; ++i) cout << ind[i] << endl;
			cout << res << endl;
		} else {
			cout << "Fegla Won" << endl;
		}
	}
	return 0;
}

string simplize(string st) {
	string ret = "";
	for (int i = 0; i < st.length(); ++i) {
		ret += st[i];
		while (i + 1 < st.length() && st[i + 1] == st[i]) {
			++i;
		}
	}
	return ret;
}
