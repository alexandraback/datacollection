#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<endl)

struct DUMP : ostringstream {
	template<class T> DUMP &operator,(const T &t) {
		if(this->tellp()) *this << ", ";
		*this << t;
		return *this;
	}
};

template<class T> inline void chmax(T &a, const T &b) { if(b > a) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(b < a) a = b; }

template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

template<class Tuple, unsigned Index>
void print_tuple(ostream &os, const Tuple &t) {}

template<class Tuple, unsigned Index, class Type, class... Types>
void print_tuple(ostream &os, const Tuple &t) {
	if(Index) os << ", ";
	os << get<Index>(t);
	print_tuple<Tuple, Index + 1, Types...>(os, t);
}

template<class... Types>
ostream &operator<<(ostream &os, const tuple<Types...> &t) {
	os << '(';
	print_tuple<tuple<Types...>, 0, Types...>(os, t);
	return os << ')';
}

template<class Iterator>
ostream &dump_range(ostream &, Iterator, const Iterator &);

template<class T>
ostream &operator<<(ostream &os, const vector<T> &c) {
	return dump_range(os, c.cbegin(), c.cend());
}

template<class Iterator>
ostream &dump_range(ostream &os, Iterator first, const Iterator &last) {
	os << '[';
	for(int i = 0; first != last; ++i, ++first) {
		if(i) os << ", ";
		os << *first;
	}
	return os << ']';
}

int calc(vector<string> strings) {
	for(auto &e : strings) {
		e.erase(unique(e.begin(), e.end()), e.end());
		if(strings[0] != e) return -1;
	}
	return strings[0].size();
}

string solve() {
	int n;
	cin >> n;

	vector<string> strings(n);
	for(auto &e : strings) cin >> e;

	const int num = calc(strings);
	if(num == -1) return "Fegla Won";

	vector<vector<int>> cnt;
	cnt.reserve(n);

	for(const auto &s : strings) {
		vector<int> tmp;
		tmp.reserve(num);

		char prev = '#';
		int t;

		for(const auto &c : s) {
			if(prev != c) {
				if(prev != '#') tmp.emplace_back(t);
				prev = c;
				t = 1;
			}
			else {
				++t;
			}
		}

		tmp.emplace_back(t);
		cnt.emplace_back(tmp);
		assert(tmp.size() == num);
	}

	int ans = 0;
	for(int i = 0; i < num; ++i) {
		int tmp = INT_MAX;
		for(int j = 1; j <= 100; ++j) {
			int sum = 0;
			for(const auto &x : cnt) {
				sum += abs(j - x[i]);
			}
			chmin(tmp, sum);
		}
		ans += tmp;
	}

	return to_string(ans);

}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": " << solve() << "\n";
	}

	return EXIT_SUCCESS;
}
