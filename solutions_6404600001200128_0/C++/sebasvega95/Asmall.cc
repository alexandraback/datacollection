#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x ": " << (x) << endl;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int cn = 0; cn < T; cn++) {
		int n;
		cin >> n;

		ll a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		ll sum1 = 0;
		for (int i = 1; i < n; i++) {
			ll aux = a[i] - a[i-1];
			if (aux < 0)
				sum1 += -aux;
		}

		ll sum2, sumAux;
		for (int rate = 1; rate < 1010; rate++) {
			sum2 = 0;
			bool canCont = false;

			//cout << "-> " << rate << endl;

			for (int i = 0; i < n-1; i++) {
				if (a[i] - rate > a[i+1]) {
					canCont = true;
					break;
				}

				if (a[i] - rate >= 0)
					sum2 += rate;
				else
					sum2 += a[i];
				//cout << "-->" << sum2 << " " << sumAux << endl;
			}

			if (canCont)
				continue;

			if (a[n-2] - rate == a[n-1])
				break;
			else
				sum2 = 0;
		}

		cout << "Case #" << cn+1 << ": " << sum1 << " " << sum2 << endl;
	}

	return 0;
}