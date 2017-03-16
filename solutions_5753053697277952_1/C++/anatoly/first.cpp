#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T> using V = vector<T>;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> Pii;

const double Pi = acos(-1.0);

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))

set<pair<int, char>> s;
bool check() {
	int total = 0;
	for (auto p : s) total += p.first;
	for (auto p : s) {
		if (p.first * 2 > total) {
			cout << endl << "!ERR" << endl;
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int T; cin >> T;
	forn(tc, T) {
		cout << "Case #" << tc + 1 << ": ";

		int N; cin >> N;

		int total = 0;
		for (int i = 0; i < N; ++i) {
			int c; cin >> c;
			s.insert({ c, i + 'A' });
			total += c;
		}

		bool first = true;
		while (!s.empty()) {
			if (!first) cout << ' ';
			first = false;

			auto p = *--s.end();
			cout << p.second;
			s.erase(--s.end());

			if (p.first > 1) s.insert({ p.first - 1, p.second });
			--total;

			if (!total) break;
			if (total == 2) {
				check();
				continue;
			}

			p = *--s.end();
			cout << p.second;
			s.erase(--s.end());

			if (p.first > 1) s.insert({ p.first - 1, p.second });
			--total;

			check();
		}
		cout << endl;
	}
}