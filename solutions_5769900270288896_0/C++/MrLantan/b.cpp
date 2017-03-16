#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a [16];
int bd [18][18];
int bans [18][18];

int main () {
	freopen ("input2.in", "r", stdin);
	freopen ("output2.out", "w", stdout);
	int t;
	scanf ("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		int r, c, n;
		scanf("%d%d%d", &r, &c, &n);
		int q = r * c;
		for (int i = 0; i < q - n; i++)
			a[i] = 0;
		for (int i = q - n; i < q; i++)
			a[i] = 1;
		int ans = 1000000000;
		do {
		//	for (int i = 0; i < q; i++)
	//			cout << a[i] << " ";
//			cout << endl;
			int cur_ans = 0;
			for (int i = 0; i < q; i++) {
				bd [i / c][i % c] = a[i];
			}
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (bd[i][j] == 1 && bd[i][j + 1] == 1)
						cur_ans++;
					if (bd[i][j] == 1 && bd[i + 1][j] == 1)
						cur_ans++;
				}
			}
			if (cur_ans < ans) {
				ans = cur_ans;
//				for (int i = 0; i < r; i++)
//					for (int j = 0; j < c; j++)
//						bans[i][j] = bd[i][j];
			}
		}
		while (next_permutation (a, a+q));
		printf ("Case #%d: %d\n", tt + 1, ans);
//			for (int i = 0; i < r; i++) {
//					for (int j = 0; j < c; j++)
//						cout << bans[i][j] << " ";
//				cout << endl;
//			}
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				bd[i][j] = 0;
	}
	
}

