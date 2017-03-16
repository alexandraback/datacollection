
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("ololo.txt", "w", stdout);
	int t;
	cin >> t;
	for (int T=1; T<=t; T++) {
		cout << "Case #" << T << ": ";
		int n;
		cin >> n;
		int a[n];
		int mx = 0, pmx=-1;
		int smx = 0, psmx=-1;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i]>mx) {
				mx=a[i];
				pmx=i;
			}
		}
		int cnt=0;
		for (int i=0; i<n; i++) {
			if (a[i]==mx) cnt++;
			else {
				if (smx< a[i]) {
					smx=a[i];
					psmx=i;
				}
			}
		}
		if (cnt>1) {
			smx=mx;
			for (int i=0; i<n; i++) {
				if (a[i]==mx && i!=pmx) {
					psmx=i;
					break;
				}
			}
		}
		while (mx>smx) {
			cout << char(pmx+'A') << " ";
			mx--;
		}
		for (int i=0; i<n; i++) {
			if (i!=pmx && i!=psmx) {
				while (a[i]) {
					cout << char(i+'A') << " ";
					a[i]--;
				}
			}
		}
		while (mx--) cout << char(pmx+'A') << char(psmx+'A') << " ";
		cout << "\n";
	}
	return 0;
}
