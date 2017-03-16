#include <bits/stdc++.h>

using namespace std;

int arr[1111];

int main() {

	cin.tie( 0 );
	ios_base::sync_with_stdio(0);

	int n, ntc;

	cin >> ntc;

	for ( int tc = 1; tc <= ntc; tc ++ ) {

		cin >> n;

		int ans1, ans2, diff;

		ans1 = ans2 = diff = 0;

		for ( int i = 0; i < n; i ++ ) {
			cin >> arr[i];
			if ( i && arr[i] < arr[i - 1] )
				ans1 += arr[i - 1] - arr[i];
			if ( i )
				diff = max ( diff, arr[i - 1] - arr[i] );
		}

		for ( int i = 0; i < n - 1; i ++ ) 
			ans2 += min ( arr[i], diff );

		cout << "Case #" << tc << ": " << ans1 << " " << ans2 << '\n';

	}

	return 0;
}
