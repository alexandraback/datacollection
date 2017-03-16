#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

string normal(const string& s) {
	string res = "";
	char last = '-';
	for(char c : s) {
		if(c != last) {
			res += c; 
		}

		last = c;
	}

	return res;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int n;
		cin >> n;
		std::vector<string> v;
		for(int j = 1; j <= n; ++j) {
			string s;
			cin >> s;
			v.push_back(s);
		}

		bool fegla_won = false;
		string normal_0 = normal(v[0]);
		//cerr << "normal_0 = " << normal_0 << endl;
		for(string s : v) {
			if(normal(s) != normal_0) {
				fegla_won = true;
				break;
			}
		}

		if(fegla_won) {
			cout << "Case #" << i << ": " << "Fegla Won" << endl;
		} else {
			int res = 0;
			map<int, int> m;

			for(int j = 0; j < n; ++j) {
				m[j] = 0;
			}

			for(char c : normal_0) {
				int diff = 1000000000;
				int maxoccur = 0;
				map<int, int> count_c;
				for(int j = 0; j < n; ++j) {
					string s = v[j];
					int occur = 0;
					int idx = m[j];
					while(idx < s.size() && s[idx] == c) {
						++idx;
						++occur;
					}

					m[j] = idx;

					if(maxoccur < occur) {
						maxoccur = occur;
					}

					count_c[j] = occur;
				}

				for(int avg = 1; avg <= maxoccur; ++avg) {
					int tmpdiff = 0;
					for(int j = 0; j < n; ++j) {
						int d = avg - count_c[j];
						tmpdiff += d > 0 ? d : -d;
					}

					if(diff > tmpdiff)
						diff = tmpdiff;
				}

				res += diff;
			}
			cout << "Case #" << i << ": " << res << endl;
		}
	}
	
	return 0;
}
