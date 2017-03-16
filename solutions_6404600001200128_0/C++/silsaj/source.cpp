#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	freopen("A-small-practice.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int ar[1010];
		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {
			cin >> ar[i];
		}

		int c1 = 0;
		int c2 = 0;
		int maxDif = 0;
		
		for (int i = 1; i < num; i++) {
			c1 += max(ar[i - 1] - ar[i], 0);
			if (max(ar[i - 1] - ar[i], 0) > maxDif) {
				maxDif = max(ar[i - 1] - ar[i], 0);
			}
		}
		
		for (int i = 1; i < num; i++) {
			if (ar[i - 1] >= maxDif)
				c2 += maxDif;
			else {
				c2 += ar[i - 1];
			}
		}
		


		cout << "Case #" << tc << ": " << c1 << " " << c2 << endl;
	}
}