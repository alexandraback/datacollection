#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

string getAbbr(string str, vector <int> &repeat) {
	int sz = str.size();
	int cnt = 1;
	string res;

	res += str[0];
	for (int i = 1; i < sz; i++) {
		if (str[i] != str[i - 1]) {
			res += str[i];
			repeat.push_back(cnt);
			cnt = 1;
		} else {
			cnt++;
		}
	}

	if (cnt > 0) {
		repeat.push_back(cnt);
	}

	return res;
}

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w+", stdout);
	cin >> T;

	for (int cas = 1; cas <= T; cas++) {
		int N = 0;

		set <string> abbr;
		vector <vector <int> > repeat;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string curr;
			string tmp;
			vector <int> rep;
			
			cin >> curr;
			tmp = getAbbr(curr, rep);

			repeat.push_back(rep);
			
			if (abbr.count(tmp) <= 0) {
				abbr.insert(tmp);
			}
		}

		if (abbr.size() > 1) {
			cout << "Case #" << cas << ": Fegla Won" << endl;
		} else {
			int res = 0;
			int sz = repeat[0].size();

			for (int i = 0; i < sz; i++) {
				int sol = 1024000;
				for (int tr = 1; tr <= 512; tr++) {
					int add = 0;
					
					for (int j = 0; j < N; j++) {
						add += abs(repeat[j][i] - tr);
					}

					if (add < sol) {
						sol = add;
					}
				}

				res += sol;
			}

			cout << "Case #" << cas << ": " << res << endl;
		}
	}
    return 0;
}
