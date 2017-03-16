#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

#define cin fin
#define cout fout

void run() {
	int n;
	cin>>n;
	string s[100];
	for (int i = 0; i < n; ++i)
		cin>>s[i];
	int ans = 0;
	for (;;) {
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (s[i].size() == 0) ++cnt;
		if (cnt == n) break;
		if (cnt > 0) {
			cout<<"Fegla Won"<<endl;
			return;
		}
		char ch = s[0][0];
		for (int i = 0; i < n; ++i)
			if (s[i][0] != ch) {
				cout<<"Fegla Won"<<endl;
				return;
			}
		int c[100] = {0};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < s[i].size(); ++j)
				if (s[i][j] != ch) break;
				else ++c[i];
			s[i] = s[i].substr(c[i]);
		}
		sort(c, c + n);
		for (int i = 0; i < n; ++i)
			ans += abs(c[i] - c[n / 2]);
	}
	cout<<ans<<endl;
}

int main() {
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<": ";
		run();
	}
	return 0;
}