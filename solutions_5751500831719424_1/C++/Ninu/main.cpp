#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int myabs(int x) {
	if(x < 0)	x = -x;
	return x;
}

int main() {
	int t, x, n;
	ifstream f("input.txt");
	ofstream g("output.txt");
	f >> t;
	for(int x = 1; x <= t; x++) {
		f >> n;
		vector<string> v(n);
		int ml = 0;
		for(int i = 0; i < n; i++) {
			f >> v[i];
			ml = max(ml, (int)(v[i].length()));
		}
		int k = -1;
		set<string> u;
		vector<vector<int>> fr(ml, vector<int>(n, 0));
		for(int i = 0; i < n; i++) {
			string s = "";
			k = -1;
			for(int j = 0; j < v[i].length(); j++) {
				if(s.empty() || s.back() != v[i][j]) {
					s.push_back(v[i][j]);
					fr[++k][i] = 1;
				}
				else {
					fr[k][i]++;
				}
			}
			u.insert(s);
		}
		if(u.size() != 1) {
			g << "Case #" << x << ": " << "Fegla Won" << endl;
		}
		else {
			for(int i = 0; i <= k; i++) {
				sort(fr[i].begin(), fr[i].end());
			}
			int sum = 0;
			for(int i = 0; i <= k; i++) {
				int mid = fr[i][n / 2];
				for(int j = 0; j < n; j++) {
					sum += myabs(fr[i][j] - mid);
				}
			}
			g << "Case #" << x << ": " << sum << endl;
		}
	}
	f.close();
	g.close();
	return 0;
}
