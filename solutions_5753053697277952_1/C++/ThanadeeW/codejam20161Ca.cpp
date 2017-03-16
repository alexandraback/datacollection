#include "main.h"
#include <list>
using namespace Core;
using namespace std;

void Core::init() {}

void Core::solve() {
	int N;
	CGET(N);
	vector<int> e(N);
	fori(i, N) {
		CGET(e[i]);
	}
	set<pair<int, int>> s;
	int sum = 0;
	fori(i, N) {
		s.insert(make_pair(e[i], i));
		sum += e[i];
	}
	while (!s.empty()) {
		auto p = s.rbegin()->second;
		auto v = s.rbegin()->first;
		s.erase(--s.end());
		cout << (char)('A' + p);
		--sum;
		if (sum % 2 == 0) {
			cout << " ";
		}
		if (v > 1) {
			s.insert(make_pair(v - 1, p));
		}
		if (sum % 2 == 0) {
			int max = 0;
			int sum = 0;
			fore(i, s) {
				max = std::max(i->first, max);
				sum += i->first;
			}
			if (max * 1.0 / sum > 0.5) {
				cerr << "gg";
			}
		}
	}
	cout << endl;
}