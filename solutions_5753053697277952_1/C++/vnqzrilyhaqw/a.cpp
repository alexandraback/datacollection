#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

char gl(pii& v) {
	char c = (char)v.second + 'A';
	return c;
}

void single_test() {
	int n;
	cin >> n;
	vector<pii> p(n);
	int sum = 0;
	for(int i=0; i<n; ++i) {
		int c;
		cin >> c;
		p[i] = pii{c, i};
		sum += c;
	}
	sort(p.begin(), p.end(), greater<pii>());
	if(sum & 1) {
		char a = gl(p[0]);
		--p[0].first;
		cout << ' ' << a;
	}
	sort(p.begin(), p.end(), greater<pii>());
	while(p[0].first) {
		char a = gl(p[0]);
		char b = gl(p[1]);
		--p[0].first;
		--p[1].first;
		cout << ' ' << a << b;
		sort(p.begin(), p.end(), greater<pii>());
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ":";
		single_test();
	}
	return 0;
}
