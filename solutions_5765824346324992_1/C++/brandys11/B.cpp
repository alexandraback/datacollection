#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve() {
	ll B, N;
	cin >> B >> N;
	vector<ll> bar(B);
	for(ll &a: bar) { cin >> a; }

	ll be = 0, e = 1000000000ll * 1000000ll + 47ll, str;

	while(e - be > 1) {
		str = (e+be)/2;
		ll stihne = 0;
		for(int a: bar) {
			stihne += str / a + 1;
		}
		if(stihne >= N) {
			e = str;
		}
		else be = str;
	} 

	if(B >= N) { e = 0; }
	//cerr << "Time " << e << " N " << N << endl;
	ll time = e, res  = -1;

	ll done = 0;
	for(ll a: bar) {
		done += (time - 1)/a + 1;
	}
	//cerr << "done " << done << endl;
	for(int i=0; i < B; i++) {
		if(time % bar[i] == 0) done++;
		if(done == N) return i + 1;
	}

	return -1;
}

int main(void) {
	int t;
	cin >> t;
	for(int i=1; i <= t; i++) {
		cout << "Case #" << i << ": " << solve() << endl; 
	}	
}