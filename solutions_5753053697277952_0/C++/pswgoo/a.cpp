#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define FOR(i, s, t) for(int i(s); i<=(int)(t); i++)
#define REP(i, n) FOR(i,0,n-1)

int n, a[33], sum;

bool ok() {
	REP(i, n) if (a[i] + a[i] > sum) return false;
	return true;
}

string ts(int i) {
	string s;
	s += 'A' + i;
	return s;
}

void Work(int casen) {
	cout << "Case #" << casen << ":";
	cin >> n;
	REP(i, n) cin >> a[i];
	sum = 0;
	REP(i, n) sum += a[i];
	vector<string> ans;
	while (sum > 0) {
		vector<pair<int, int>> p;
		REP(i, n) if (a[i]) p.emplace_back(a[i], i);
		sort(p.begin(), p.end());
		reverse(p.begin(), p.end());
		int i = p[0].second;
		int j = p[1].second;
		string si = ts(i);
		string sj = ts(j);
		{
			a[i]--; sum--;
			if (ok()) {
				ans.push_back(si);
				continue;
			}
			a[i]++; sum++;
		}
		if (a[i] >= 2) {
			a[i] -= 2; sum -= 2;
			if (ok()) {
				ans.push_back(si + si);
				continue;
			}
			a[i] += 2; sum += 2;
		}
		{
			a[i]--; sum--; a[j]--; sum--;
			if (ok()) {
				ans.push_back(si + sj);
				continue;
			}
			a[i]++; sum++; a[j]++; sum++;
		}
		cout << "error ";
		REP(i, n) cout << a[i] << ' ';
		cout << endl;
		break;
	}
	REP(i, ans.size()) cout << ' ' << ans[i];
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		Work(i);
}
