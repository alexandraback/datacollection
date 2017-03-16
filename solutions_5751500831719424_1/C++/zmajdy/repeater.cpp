#include <bits/stdc++.h>

using namespace std;

int T,n;
string s[200];
vector<int> v[1000];
vector<char> c[1000];
vector<int> x[1000];
int med[1000];

int main () {
	cin >> T;
	for (int tc =1; tc <= T; tc++) {
		cin >> n;
		for (int i=0; i<=1000; i++)
			x[i].clear();
			
		for (int i=1; i<=n; i++) {
			cin >> s[i];
			v[i].clear();
			c[i].clear();
			v[i].push_back(1);
			c[i].push_back(s[i][0]);
			for (int j=1; j<s[i].size(); j++)
				if (s[i][j] == s[i][j-1])
					v[i].back()++;
				else {
					v[i].push_back(1);
					c[i].push_back(s[i][j]);
				}
					
			for (int j=0; j<v[i].size(); j++) 
				x[j].push_back(v[i][j]);
		}
		printf ("Case #%d: ",tc);
		bool valid = true;
		int sz = v[1].size();
		for (int i=1; i<=n; i++) {
			if (v[i].size() != sz) valid = false;
			for (int j=0; j<sz; j++)
				if (c[i][j] != c[1][j]) valid = false;
		}
		if (!valid) {
			puts("Fegla Won");
			continue;
		}
		
		for (int i=0; i<sz; i++) {
			sort(x[i].begin(),x[i].end());
			med[i] = x[i][(int(x[i].size()) - 1)/2];
		}
		int ans = 0;
		for (int i=1; i<=n; i++)
			for (int j=0; j<sz; j++) 
				ans += abs(v[i][j] - med[j]);
				
		cout << ans <<endl;
	}
}