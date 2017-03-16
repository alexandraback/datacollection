#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T[1111], m;

ll calc ( ll t ) {
	
	ll tot = 0;

	for ( int i = 0; i < m; i ++ ) {
		tot += t / T[i];
		if ( t % T[i] ) tot ++;
	}

	return tot;
}

int main() {

	int ntc;
	int N, ans;

	cin >> ntc;

	for ( int tc = 1; tc <= ntc; tc ++ ) {

		cin >> m >> N;

		for ( int i = 0; i < m; i ++ ) cin >> T[i];
		
		ll L = 0, R = ll(N) * ll(T[0]), mid;

		while ( L <= R ) {
			mid = ( L + R ) / 2;
			if ( calc ( mid ) >= N ) R = mid - 1;
			else L = mid + 1;
		}
		L --;

		int done = calc ( L );
		assert ( done < N );

		for ( int i = 0; i < m; i ++ ) {
			if ( L % T[i] ) continue;
			else {
				done ++;
				if ( done == N ) {
					ans = i + 1;
					break;
				}
			}
		}

		cout << "Case #" << tc << ": " << ans << '\n';
	}

	return 0;
}
