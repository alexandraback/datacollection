#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.out");
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define abs(x) ((x)<0 ? -(x) : (x))

int main() {
	int T, N, c, i, j, x;
	bool flag;
	fin >> T;
	vector<string> IN;
	vector<string> real;
	vvi count;
	for (c = 1; c <= T; c++) {
		IN.clear();
		real.clear();
		count.clear();
		fin >> N;

		IN.resize(N);
		real.resize(N);


		for (i = 0; i < N; i++) {
			fin >> IN[i];
		}
		for (i = 0; i < N; i++) {
			real[i] = "";
			real[i] += IN[i][0];
			for (j = 1; j < sz(IN[i]); j++) {
				if (IN[i][j] != IN[i][j-1]) real[i] += IN[i][j];
			}
		}
		for (i = 0; i < N-1; i++) {
			flag = true;
			if (sz(real[i]) != sz(real[i+1])) {
				flag = false;
				break;
			}
			for (j = 0; j < sz(real[i]); j++) {
				if (real[i][j] != real[i+1][j]) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		if (!flag) {
			fout << "Case #" << c << ": Fegla Won" << endl;
			continue;
		}

		count.resize(N, vi(sz(real[0]), 0));
		for (i = 0; i < N; i++) {
			int ind = 0;
			for (j = 0; j < sz(IN[i]) && ind < sz(real[i]); j++) {
				if (IN[i][j] == real[i][ind]) count[i][ind]++;
				else {
					ind++;
					j--;
				}
			}
		}
		int res = 0;
		for (i = 0; i < sz(real[0]); i++) {
			int minim = 10000000;
			for (x = 1; x <= 100; x++) {
				int co = 0;
				for (j = 0; j < N; j++) {
					co += abs(x-count[j][i]);
				}
				if (minim > co) minim = co;
			}
			res+= minim;
		}
		fout << "Case #" << c << ": " << res << endl;
	}

	return 0;
}
