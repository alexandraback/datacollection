#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }

typedef pair< char, int > pci;
typedef vector< pci > vs;

bool cons(vs const & lhs, vs const & rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}
	for (size_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i].first != rhs[i].first) {
			return false;
		}
	}
	return true;
}

int best(vector< int > const & l) {
	int left =  *min_element(ALL(l));
	int right = *max_element(ALL(l));
	int res = l.size() * right;
	for (int i = left; i <= right; ++i) {
		int cur = 0;
		for (size_t j = 0; j < l.size(); ++j) {
			cur += abs(l[j] - i);
		}
		res = min(cur, res);
	}
	return res;
}

void solve() {
	int n = next< int >();
	vector< vs > data;
	for (int i = 0; i < n; ++i) {
		string tmp = next< string >();
		vs v;
		char c = tmp[0];
		int len = 0;
		for (size_t j = 0; j < tmp.size(); ++j) {
			if (c == tmp[j]) {
				len++;
			} else {
				v.push_back(make_pair(c, len));
				c = tmp[j];
				len = 1;
			}
		}
		v.push_back(make_pair(c, len));

		data.push_back(v);
	}
	for (size_t i = 1; i < data.size(); ++i) {
		if (!cons(data[0], data[i])) {
			cout << "Fegla Won\n";
			return;
		}
	}
	int res = 0;
	for (size_t i = 0; i < data[0].size(); ++i) {
		vector< int > lens;
		for (size_t j = 0; j < data.size(); ++j) {
			lens.push_back(data[j][i].second);
		}
		res += best(lens);
	}
	cout << res << "\n";
}

int main() {

//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}

