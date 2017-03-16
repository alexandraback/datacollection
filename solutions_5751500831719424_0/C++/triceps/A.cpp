#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string shorten(const string& s, vector<int>& v)
{
	char prev = s[0];
	int rep = 1;
	string mod;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == prev) {
			rep++;
		}
		else {
			v.push_back(rep);
			mod + s[i-1];
			mod.append(&s[i - 1], &s[i]);
			prev = s[i];
			rep = 1;
		}
	}
	v.push_back(rep);
	mod.append(s.end()-1, s.end());
	return mod;
}

int main()
{
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++){
		int N = 0;
		cin >> N;
		vector<string> v(N);
		vector<vector<int>> vv(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			v[i] = shorten(v[i], vv[i]);
		}

		bool same = true;
		for (int i = 1; i < N; i++){
			if (v[0] != v[i]) {
				same = false;
				break;
			}
		}
		if (!same) {
			printf("Case #%d: Fegla Won\n", t);
			continue;
		}

		int sum = 0;
		for (int i = 0; i < vv[0].size(); i++) {
			int rmin = 1000, rmax = 0;
			vector<int> vr;
			for (int j = 0; j < N; j++) {
				rmin = min(rmin, vv[j][i]);
				rmax = max(rmax, vv[j][i]);
				vr.push_back(vv[j][i]);
			}
			int mmin = 100000;
			for (int r = rmin; r <= rmax; r++) {
				int s = 0;
				for (int k = 0; k < vr.size(); k++){
					s += abs(vr[k] - r);
				}
				mmin = min(mmin, s);
			}
			sum += mmin;
		}
		printf("Case #%d: %d\n", t, sum);
	}



	return 0;
}