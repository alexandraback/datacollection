#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

const int INF = 1e6;

vector<string> s;
vector< vector<int> > lens;
string base_string;

int min_ans() {
	const int N = s.size();
	const int K = base_string.size();
	int res = 0;
	for (int k = 0; k < K; ++k) {
		int min_k = INF;
		int max_k = -INF;
		for (int i = 0; i < N; ++i) {
			if (lens[i][k] < min_k) {
				min_k = lens[i][k];
			}
			if (lens[i][k] > max_k) {
				max_k = lens[i][k];
			}
		}

		int loc_res = INF;
		for (int val = min_k; val <= max_k; ++val) {
			int aa = 0;
			for (int i = 0; i < N; ++i) {
				aa += abs(lens[i][k] - val);
			}
			loc_res = min(loc_res, aa);
		}

		res += loc_res;
	}
	return res;
}

vector< vector<int> > get_lens(const string& base) {
	const int N = s.size();
	vector< vector<int> > lens(N, vector<int>(base.size(), 0));
	for (int i = 0; i < N; ++i) {
		int last_idx = 0;
		int idx = 1;
		int lidx = 0;
		while (idx < s[i].size()) {
			if (s[i][idx] != s[i][idx - 1]) {
				lens[i][lidx] = idx - last_idx;
				++lidx;
				last_idx = idx;
			}
			++idx;
		}
		lens[i][lidx] = idx - last_idx;
	}
	return lens;
}

bool check_order() {
	bool ok = true;
	string bs;
	bs.push_back(s[0][0]);
	for (int i = 1; i < s[0].size(); ++i) {
		if (s[0][i] != s[0][i - 1]) {
			bs.push_back(s[0][i]);
		}
	}
	for (int x = 1; x < s.size(); ++x) {
		string st;
		st.push_back(s[x][0]);
		for (int i = 1; i < s[x].size(); ++i) {
			if (s[x][i] != s[x][i - 1]) {
				st.push_back(s[x][i]);
			}
		}
		ok &= (bs == st);
	}
	if (!ok){
		return false;
	}

	base_string = bs;
	lens = get_lens(bs);
	return ok;
}

int main() {
	//ifstream input("input.txt");
	//ofstream output("output.txt");
	ifstream input("A-large.in");
	ofstream output("A-large.out");
	int T;
	input >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		input >> N;
		s.resize(N);
		string str;
		for (int i = 0; i < N; ++i) {
			input >> str;
			s[i] = str;
		}

		output << "Case #" << t << ": ";
		if (check_order()) {
			output << min_ans() << endl;
		}
		else {
			output << "Fegla Won" << endl;
		}
	}
	return 0;
}
