#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)

int n;
vector<string> a;

int normalize(vector<int> elem) {
//	for(int x : elem) { cerr << x << ", " ; } cerr << endl;
	sort(elem.begin(), elem.end());
	int base = elem[elem.size() / 2];

	int s = 0;
	for(int x : elem) s += abs(x - base);
	return s;
}

int go() {
	set<string> target;
	for(string s : a) {
		s.erase(unique(s.begin(), s.end()), s.end());
		target.insert(s);
	}
	if(target.size() > 1) return -1;
	string T = *target.begin();

	vector< vector<int> > L(T.size());
	for(int i = 0; i < n; ++ i) {
		int b = 0;
		int j = 0;
		for(char ch : T) {
			int e;
			for(e = b; e < (int)a[i].size() && a[i][e] == ch; ++ e);
			--e;
			int len = e - b + 1;
			b = e + 1;
			L[j].push_back(len);
			j ++;
		}
	}

	int cost = 0 ;
	for(int j = 0; j < (int)L.size(); ++ j) {
//		cerr << T[j] << endl;
		cost += normalize(L[j]);
	}

	return cost;
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++ t) {
		cin >> n;
		a = vector<string> (n);
		REP(i, n) cin >> a[i];

		int ans = go();
		if(ans < 0)
			printf("Case #%d: Fegla Won\n", t);
		else
			printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
