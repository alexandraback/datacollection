#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int,int>> S;
	
	for(int i=0; i < n; i++) {
		int a;
		cin >> a;
		for(int j=0; j < a; j++) S.emplace_back(j, i);
	}

	sort(S.rbegin(), S.rend());
	if(S.size() == 1) {
		cout << (char) (S[0].second + 'A');
	} else {
		for(int i=0; i + 3 <  S.size(); i+= 2) {
			cout << (char) (S[i].second + 'A');
			cout << (char) (S[i+1].second + 'A');
			cout << " ";
		}

		if (S.size() % 2 == 1) {
			cout << (char) (S[S.size() - 3].second + 'A');
			cout << " ";
		}
		cout << (char) (S[S.size() - 1].second + 'A');
		cout << (char) (S[S.size() - 2].second + 'A');
	}
}

int main(void) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
}