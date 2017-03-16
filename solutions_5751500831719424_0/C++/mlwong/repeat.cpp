#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

char s[102][102];
int cnt[102][102];

void solve(int tc) {
	int out = 0;
	cout << "Case #" << tc << ": ";
	memset(cnt,0,sizeof(cnt));
	memset(s,0,sizeof(s));
	int n;
	scanf("%d ", &n);

	for (int i=0; i<n; i++) scanf("%s", s[i]);
	
	s[n][0] = s[0][0];
	int l = strlen(s[0]), p, pans=1;
	for (int i=1; i<l; i++) {
		if (s[0][i] != s[0][i-1])
			s[n][pans++] = s[0][i];
	}
	
	bool b = false;
	for (int i=0; i<n; i++) {
		l = strlen(s[i]);
		p = 0;
		for (int j=0; j<l; j++) {
			if (s[i][j] == s[n][p])
				cnt[p][i]++;
			else {
				if (j == 0) {
					b = true;
					break;
				}
				p++;
				if (s[i][j] != s[n][p]) {
					b = true;
					break;
				}
				cnt[p][i]++;
			}
		}
		if (p != pans-1) b = true;
		if (b) break;
	}
	
	for (int i=0; i<pans; i++) sort(cnt[i], cnt[i]+n);

	for (int i=0; i<pans; i++) {
		for (int j=0; j<n; j++) {
			out += abs(cnt[i][n/2]-cnt[i][j]);
		}
	}
	
	if (b) {
		cout << "Fegla Won" << endl;
		return;
	}
	
	cout << out << endl;
}

int main() {
	int T;
	cin >> T;
	for (int tc=1; tc<=T; tc++) solve(tc);
	return 0;
}
