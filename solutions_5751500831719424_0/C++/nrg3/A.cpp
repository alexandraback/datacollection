#pragma comment(linker, "/STACK:256000000")

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;


string unite(const string& s) {
	string r = "";
	r += s[0];
	for (int i = 1; i < s.size(); ++i) {
		if (*r.rbegin() != s[i]) {
			r += s[i];
		}
	}

	return r;
}

int main() {
	int _start = clock();
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	/*
#ifndef ONLINE_JUDGE
    
    freopen("output.txt","w",stdout);
#else
#define taskname "cutting"
	//freopen(taskname".in","r",stdin);
    //freopen(taskname".out","w",stdout);
#endif
*/

	int T; cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
		int n; cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		bool bad = 0;
		string prof = unite(s[0]);
		for (int i = 1; i < n; ++i) {
			if (unite(s[i]) != prof) {
				bad = 1;
				break;
			}
		}

		if (bad) {
			cout << "Fegla Won" << endl;
			continue;
		}

		int moves = 0;
		vector<int> at(n, 0);

		while (true) {
			vector<int> q(n, 0);

			bool bad = 0;
			
			for (int i = 0; i < n; ++i) {
				int current = 1;
				if (at[i] >= s[i].size()) {
					bad = 1;
					break;
				}
				while (at[i] + 1 < s[i].size() && s[i][at[i]] == s[i][at[i] + 1]) {
					++current;
					++at[i];
				}
				++at[i];

				q[i] = current;			
			}

			if (bad) break;

			int min_at = 100, min_val = INF;
			for (int res = 1; res <= 105; ++res) {
				int current = 0;
				for (int i = 0; i < n; ++i) {
					current += abs(q[i] - res);
				}

				if (current < min_val) {
					min_val = current;
					min_at = res;
				}
			}

			moves += min_val;
		}

		cout << moves << endl;
	}


	
	cerr << endl << endl << "Time: " << (double)(clock() - _start) / CLOCKS_PER_SEC << endl;
	return 0;
}