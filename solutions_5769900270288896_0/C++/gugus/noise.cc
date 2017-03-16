#include <pe.h>


int cobits(int R, int C, int c) {
	ll result = 0;
	vector<vector<ll> > tab(R+2);
	for (int i = 0; i < R+2; ++i) {
		for (int j = 0; j < C+2; ++j) {
			tab[i].pb(0);
		}
	}
	vector<ll> b(R*C);
	for (ll i = 0; i < R*C; ++i) {
		b[i] = (c & (1<<i)) >> i;
		//cout << b[i];
	}
	//cout << endl;
	//cout << "OK" << endl;
	for (int i = 1; i < R+1; ++i) {
		for (int j = 1; j < C+1; ++j) {
			tab[i][j] = b[(i-1)*C +j-1];
		}
	}
	
	for (int i = 1; i < R+1; ++i) {
		for (int j = 1; j < C+1; ++j) {
			if (tab[i][j]==1) {
				result += tab[i+1][j]+tab[i][j+1];
			}
		}
	}
	return result;
}

ll solve(ll R, ll C, ll N) {
	if (N==0) {
		return 0;
	}
	int k = N;
	int c = (1<<k)-1;
	int n = R*C;
	ll minimum= 1e9;
	while (c < (1<<n)) {
		//display_bits(c);
		if (cobits(R, C, c)<minimum) {
			minimum = cobits(R, C, c);
		}
		int a = c&-c, b = c+a;
		c = (c^b)/4/a|b;
	}
	return minimum;
}

int main() {
	int T;
	cin>> T;
	int R, C, N;
	for (ll i = 0; i < T; ++i) {
		cin >> R; cin >> C; cin >> N;
		printf("Case #%Ld: %Ld\n", i+1, solve(R, C, N));
	}
	return 0;
}


