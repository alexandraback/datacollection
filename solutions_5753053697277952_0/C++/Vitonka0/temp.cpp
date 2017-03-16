#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int amax(vector <int> &v) {
	int ans = 0;
	for (int i = 1; i < v.size(); ++i)
		if (v[i] > v[ans])
			ans = i;
	return ans;
}

bool check(vector <int> &v) {
	int alsum = 0;
	for (int i = 0; i < v.size(); ++i)
		alsum += v[i];
	for (int i = 0; i < v.size(); ++i)
		if (2 * v[i] > alsum)
			return false;
	return true;
}

int main () {
	ifstream cin ("input.txt");
	ofstream cout ("output.txt");
	int t;
	cin >> t;
	for (int k = 0; k < t; ++k) {
		cout << "Case #" << k + 1 << ": ";
		int n;
		cin >> n;
		vector <int> v(n);
		int alsum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v [i];
			alsum += v[i];
		}
		while (alsum > 0) {
			int a1 = -1, a2 = -1;
			bool flag1 = false;
			for (int j1 = 0; j1 < n; ++j1) {
				if (v[j1] > 0) {
					--v[j1];
					if (check(v)) {
						flag1 = true;
						a1 = j1;
						break;
					}
					++v[j1];
				}
			}

			if (flag1) {
				cout << (char)('A' + a1) << " ";
				alsum -= 1;
				continue;
			}

			bool flag2 = false;
			for (int j1 = 0; (j1 < n) && !flag2; ++j1)
				for (int j2 = 0; (j2 < n) && !flag2; ++j2) {
					if (j1 != j2 && v[j1] > 0 && v[j2] > 0) {
						--v[j1];
						--v[j2];
						if (check(v)) {
							flag2 = true;
							a1 = j1;
							a2 = j2;
							break;
						}
						++v[j1];
						++v[j2];
					}
				}
			cout << (char)('A' + a1) << (char)('A' + a2) << " ";
			alsum -= 2;
		}
		cout << endl;
	}
}