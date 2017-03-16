#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int main() {

	freopen ( "B0.in", "r", stdin );
	freopen ( "SalidaB.out", "w", stdout );

	int R, C, N;
	int ntc;

	cin >> ntc;

	for ( int tc = 1; tc <= ntc; tc ++ ) {

		cin >> R >> C >> N;
		cout << "Case #" << tc << ": ";

		int r[5];
		int c[5], Ni = N;

		if ( R % 2 ) swap ( R, C );

		r[1] = ( C + 1 ) / 2;
		r[0] = C / 2;

		c[1] = ( R + 1 ) /  2;
		c[0] = R / 2;

		N -= c[0] * r[0];
		N -= c[1] * r[1];

		if ( N <= 0 ) {
			cout << "0\n";
			continue;
		}

		if ( R == 1 || C == 1 ) {
			cout << N * 2 - (( R + C ) % 2)<< '\n';
			continue;
		}

		if ( Ni == (R * C - 1) && R > 2 && C > 2 ) {
			int tot = (R - 1) * C + R * ( C - 1 );
			cout << tot - 4 << '\n';
			continue;
		}

		int pend = N;
		int as = 0;

		if ( C % 2 == 0 ) as += 1;
		if ( R % 2 == 0 ) as += 1;
		if ( ( R + C ) % 2 ) as += 1;

		if ( as > pend ) {
			cout << N * 2 << '\n';
			continue;
		}
		
		if ( C - c[0] >= pend ) {
			cout << N * 3 - as<< '\n';
			continue;
		}
		pend -= ( C - c[0] );

		if ( R - r[0] >= pend ) {
			cout << N * 3 - as<< '\n';
			continue;
		}
		pend -= ( R - r[0] );

		if ( R - r[C%2] >= pend ) {
			cout << N * 3 - as<< '\n';
			continue;
		}
		pend -= ( R - r[C%2] );

		if ( C - c[R%2] >= pend ) {
			cout << N * 3 - as<< '\n';
			continue;
		}
		pend -= ( C - c[R%2] );

		cout << (N - pend) * 3 + pend * 4 - as << '\n';
		
	}


	return 0;
}
