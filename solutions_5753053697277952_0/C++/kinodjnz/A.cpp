#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

bool isok(int N, int *p) {
	int a = accumulate(p, p+N, 0);
	for (int i = 0; i < N; i++) {
		if (p[i]*2 > a)
			return false;
	}
	return true;
}

vector<string> solve(int N, int *p) {
	vector<string> ans;
	while (true) {
		string r = "";
		int m = 0;
		int maxi = -1;
		for (int i = 0; i < N; i++) {
			if (m < p[i]) {
				m = p[i];
				maxi = i;
			}
		}
		if (m == 0)
			return ans;
		p[maxi]--;
		r += 'A'+maxi;
		if (!isok(N, p)) {
			m = 0;
			maxi = -1;
			for (int i = 0; i < N; i++) {
				if (m < p[i]) {
					m = p[i];
					maxi = i;
				}
			}
			if (m == 0) {
				ans.push_back(r);
				return ans;
			}
			p[maxi]--;
			r += 'A'+maxi;
			if (!isok(N, p)) {
				cout << "!!!!!!!!!!!!" << endl;
			}
		}
		ans.push_back(r);
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int p[30] = {};
		for (int j = 0; j < N; j++)
			cin >> p[j];
		vector<string> ans = solve(N, p);
		cout << "Case #" << i+1 << ":";
		for (string &s: ans) {
			cout << " " << s;
		}
		cout << endl;
	}
}
