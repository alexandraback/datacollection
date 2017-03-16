#include <iostream>

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t; cin >> t;

	for (int T = 1; T <= t; T++){
		cout << "Case #" << T << ": ";
		int n, d[30];
		cin >> n;
		for (int i = 0; i < n; i++) cin >> d[i];

		for (int i = 0; i <= 1000; i++) {
			int max = 0, t;
			int num, flag = -1, ac = 1, chk = 0;

			for (int j = 0; j < n; j++) {
				if (d[j] > 0 && flag == -1) {
					flag = 1;
					num = d[j];
				}
				else if (d[j] > 0) {
					if (d[j] != num) ac = chk = 1;
					ac++;
				}
			}

			if (ac == 2 && chk == 0) break;

			for (int j = 0; j < n; j++) {
				if (max < d[j]) {
					max = d[j];
					t = j;
				}
			}

			d[t]--; cout << (char)(t + 'A') << " ";
		}

		int mx = 0, tt;

		for (int i = 0; i < n; i++) {
			if (mx < d[i]) {
				mx = d[i];
				tt = i;
			}
		}

		if (mx != 0) {
			int count = 0, t2;
			for (int i = 0; i < n; i++) 
				if (mx == d[i] && tt != i) t2 = i;

			for (int i = 0; i < d[t2]; i++) cout << (char)(tt + 'A') << (char)(t2 + 'A') << " ";
		}
		cout << endl;
	}
}