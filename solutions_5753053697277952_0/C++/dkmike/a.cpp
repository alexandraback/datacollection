#include <iostream>
#include <set>

using namespace std;

typedef pair <int, char> pic;

bool cmp(const pic& a, const pic& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first > b.first;
}

void solve(const int t) {
	cout << "Case #" << t << ":";

	int N = 0;
	cin >> N;

	set <pic, bool (*)(const pic& a, const pic& b)> p(&cmp);
	for (int i = 0; i < N; ++i) {
		int pi = 0;
		cin >> pi;
		p.emplace(pi, 'A' + i);
	}

	while (true) {
		if (2 == p.size()) {
			const pic a = *p.begin();
			p.erase(p.begin());

			const pic b = *p.begin();
			p.erase(p.begin());

			if (a.first == b.first) {
				for (int i = 0; i < a.first; ++i) {
					cout << ' ' << a.second << b.second;
				}
				break;
			}
		}

		const pic cur = *p.begin();
		p.erase(p.begin());
		cout << ' ' << cur.second;
		if (1 < cur.first) {
			p.emplace(cur.first - 1, cur.second);
		}
	}

	cout << endl;
}

int main() {
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		solve(i + 1);
	}

	return 0;
}
