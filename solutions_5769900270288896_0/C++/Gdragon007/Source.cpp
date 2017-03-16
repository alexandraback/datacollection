#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int t, r, c, n, ans, y, d;
	cin>>t;
	for (int ca = 1; ca <= t; ca ++ ) {
		cin>>r>>c>>n;
		if (n <= (r * c + 1) / 2) ans = 0;
		else {
			y = r * c - n;
			if (y <= ((r - 1) * (c - 1) + 1) / 2) ans = r * c * 2 - r - c - 4 * y;
			else {
				d = ((r - 1) * (c - 1) + 1) / 2;
				y -= d;
				if ((r * c) & 1) {
					if (y <= r + c - 4) {
						ans = r * c * 2 - r - c - 4 * d - 3 * y;
					}
					else {
						ans = r * c * 2 - r - c - 4 * d - 3 * max(0, r + c - 4) - 2 * (y - max(0, r + c - 4));
					}
				}
				else {
					if (y <= r + c - 2) {
						ans = r * c * 2 - r - c - 4 * d - 3 * y;
					}
					else {
						ans = r * c * 2 - r - c - 4 * d - 3 * max(0, r + c - 2) - 2 * (y - max(0, r + c - 2));
					}
				}
			}
		}
		cout<<"Case #"<<ca<<": "<<max(ans, 0)<<endl;
	}
	//while (1);
	return 0;
}