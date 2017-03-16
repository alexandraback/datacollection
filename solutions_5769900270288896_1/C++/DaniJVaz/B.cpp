#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int p, q, n;
		scanf("%d %d %d", &p, &q, &n);

		ll c = 0;
		if (n <= (p*q+1)/2) {
			c = 0;
		}
		else if (p == 1 or q == 1) {
			p = p*q;
			q = 1;

			c = (p-1)*q + (q-1)*p; // All full, and now we start removing
			ll a = p*q - n; // How many do we remove

			c -= a*2;
		}
		else if ((p*q)%2 == 0) {
			c = (p-1)*q + (q-1)*p; // All full, and now we start removing

			ll a = p*q - n; // How many do we remove
				
			if (a >= ((p-2)*(q-2)+1)/2) {   // Center
				c -= (((p-2)*(q-2)+1)/2) * 4;
				a -= ((p-2)*(q-2)+1)/2;
			}
			else {
				c -= a*4;
				a = 0;
			}

			if (a >= (p-1+q-1-2)) {
				c -= (p-1+q-1-2)*3;
				a -= (p-1+q-1-2);
			}
			else {
				c -= a*3;
				a = 0;
			}

			c -= a*2; // Corners
			a = 0;
		}
		else {
			c = (p-1)*q + (q-1)*p; // All full, and now we start removing

			ll h1 = c;
			{
				ll a = p*q - n; // How many do we remove
				// First try: all blacks
				if (a >= (p-2)*(q-2)/2) { // Center
					h1 -= ((p-2)*(q-2)/2)*4;
					a -= (p-2)*(q-2)/2;
				}
				else {
					h1 -= a*4;
					a = 0;
				}

				h1 -= a*3; // Edges
				a = 0;
			}

			ll h2 = c;
			{
				ll a = p*q - n; // How many do we remove
				// Second try: all whites
				if (a >= ((p-2)*(q-2)+1)/2) {   // Center
					h2 -= (((p-2)*(q-2)+1)/2) * 4;
					a -= ((p-2)*(q-2)+1)/2;
				}
				else {
					h2 -= a*4;
					a = 0;
				}

				if (a >= (p-1+q-1-4)) {
					h2 -= (p-1+q-1-4)*3;
					a -= (p-1+q-1-4);
				}
				else {
					h2 -= a*3;
					a = 0;
				}

				h2 -= a*2; // Corners
				a = 0;
			}			

			c = min(h1, h2);
		}

		printf("Case #%d: %I64d\n", iC, c);
	}
	return 0;
}