#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	int nc; cin >> nc;
	for (int cs = 1; cs <= nc; cs++) {
		int n; cin >> n;
		ll shrooms[n];
		for (int i = 0; i < n; i++) {
			cin >> shrooms[i];
		}
		ll sumdiff = 0;
		ll maxdiff = 0;
		ll maxdiffmul = 0;
		ll z = 0;
		for (int i = 0; i+1 < n; i++) {
			ll diff = shrooms[i] - shrooms[i+1];
			if (diff >= 0) sumdiff += diff;
			if (diff > maxdiff) maxdiff = diff;
		}
		for (int i = 0; i+1 < n; i++) {
			z += min(maxdiff, shrooms[i]);
		}
		cout << "Case #" << cs << ": " << sumdiff << " " << z << endl;
	}
}
