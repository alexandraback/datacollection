#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <time.h>
#include <functional>

#define M_PI           3.14159265358979323846

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "1"

#pragma comment(linker, "/STACK:56777216")

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

int main() {
	freopen(PROBLEM_ID".in", "r", stdin);
	freopen(PROBLEM_ID".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	// getline(cin, name);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vi p(n);
		set<pii, std::greater<pii>> x;
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			x.insert({ p[i], i });
		}

		vi plan1, plan2;
		while (!x.empty()) {
			auto it = x.begin();
			auto it2 = x.begin();
			it2++;

			if (it->first > it2->first || x.size() == 3 && x.begin()->first == 1) {
				int count = it->first;
				int num = it->second;
				plan1.push_back(num);
				plan2.push_back(-1);
				count--;
				x.erase(it);
				if (count > 0) {
					x.insert({ count, num });
				}
			}
			else {
				int c = it->first;
				int n1 = it->second;
				int n2 = it2->second;
				x.erase(it);
				x.erase(it2);
				c--;
				plan1.push_back(n1);
				plan2.push_back(n2);
				if (c > 0) {
					x.insert({ c, n1 });
					x.insert({ c, n2 });
				}
			}
		}

		string ans = "";
		for (int i = 0; i < plan1.size(); ++i) {
			ans += 'A' + plan1[i];
			if (plan2[i] != -1) {
				ans += 'A' + plan2[i];
			}
			ans += ' ';
		}

		cout << "Case #" << i + 1 << ": " << ans << endl;
	}

	return 0;
}