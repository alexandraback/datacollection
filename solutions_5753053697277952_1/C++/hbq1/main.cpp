#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

const int MAXSIZE = 100;

int a[MAXSIZE];


int main() {
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int t, tn = 1;
	cin >> t;
	while (tn <= t) {
		cout << "Case #" << tn << ": ";
		tn++;
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		int maxn1, maxn2;
		while (sum > 0) {
			maxn1 = maxn2 = -1;
			for (int k = 0; k < n; ++k)
				if (a[k] > 0) {
					if (maxn1 == -1)
						maxn1 = k;
					else
						maxn2 = k;
				}
			for (int k = 0; k < n; ++k)
				if (a[k] > a[maxn1])
					maxn1 = k;
			for (int k = 0; k < n; ++k)
				if (a[k] > a[maxn2] && k != maxn1)
					maxn2 = k;
			
			if (a[maxn1]>1 && (sum - 2) / 2 >= a[maxn2]) {
				a[maxn1] -= 2;
				sum -= 2;
				cout << char('A' + maxn1) << char('A' + maxn1) << " ";
			}
			else if ((sum - 1) / 2 >= a[maxn2]) {
				a[maxn1]--;
				sum--;
				cout << char('A' + maxn1) << " ";
			}
			else {
				a[maxn1]--;
				a[maxn2]--;
				sum -= 2;
				cout << char('A' + maxn1) << char('A' + maxn2) << " ";
			}
			
		}

		
		cout << endl;
	}
	return 0;
}

