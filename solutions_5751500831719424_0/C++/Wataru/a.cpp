#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>


using namespace std;

int n;             

vector<vector <int> > a;
vector<vector <char> > chr;


void Load()
{
	cin >> n;
	string s;
	a.clear();
	a.resize(n);
	chr.clear();
	chr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		s += '.';
		char c = s[0];
		int j;
		int k = 0;
		for (j = 1; j < (int)s.size(); j++) {
			if (s[j] != c) {
				chr[i].push_back(c);
				a[i].push_back(k);
				c = s[j];
				k = 1;
			} else k++;
		}
	}
}

void Solve()
{
	int l = a[0].size();
	int i, j, k;
	bool bad = false;
	for (i = 0; i < n-1; i++) {
		if (a[i].size() != a[i+1].size()) {
			bad = true;
			break;
		}
		for (j = 0; j < (int) a[i].size(); j++) {
			if (chr[i][j] != chr[i+1][j]) {
				bad = true;
				break;
			}
		}
	}
	if (bad) {
		cout << "Fegla Won\n";
		return;
	}
	k = 0;
	for (i = 0; i < l; i++) {
		vector<int> tmp;
		for (j = 0; j < n; j++) {
			tmp.push_back(a[j][i]);
		}

		sort(tmp.begin(), tmp.end());
		int m = tmp[n/2];

		for (j = 0; j < n; j++)
			k += abs(tmp[j] - m);
	}
	cout << k << "\n";
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
