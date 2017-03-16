#include <iostream>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int a[10000];

void run() {
	int r, c, n;
	cin >> r >> c >> n;
	int s = r*c;
	for (int i=0; i<n; i++) a[i] = 0;
	for (int i=n; i<s; i++) a[i] = 1;
	int out = (r-1)*c + (c-1)*r;
	do {
		int cnt = 0;
		//cout << "----" << endl;
		for (int i=0; i<c; i++) {
			for (int j=0; j<r; j++) {
			//	cout << a[i*r+j];
				if (i > 0) if (a[i*r+j] == 0 && a[(i-1)*r+j] == 0) cnt++;
				if (j > 0) if (a[i*r+j] == 0 && a[i*r+j-1] == 0) cnt++;
			}
			//cout << endl;
		}
		//cout << "cnt == " << cnt << endl;
		if (cnt < out) out = cnt;
	} while (next_permutation(a, a+s));
	cout << out << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cout << "Case #" << i << ": ";
		run();
	}
	return 0;
}
