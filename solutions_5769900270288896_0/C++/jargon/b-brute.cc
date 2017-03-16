#include <bits/stdc++.h>
using namespace std;

#define chk(r, c) ((r) >= 0 && (c) >= 0 && (r) < R && (c) < C && occ[(r) * C + (c)])

int main() {
	int T;
	cin >> T;
	for (int t = 0; t++ < T;) {
		int R, C, N;
		cin >> R >> C >> N;
		vector<int> occ(R * C, 0);
		for (int i = 0; i < N; i++) {
			occ[R * C - i - 1] = 1;
		}
		int best = 0x7fffffff;
		do {
			int un = 0;
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					if (chk(r, c)) {
						un += chk(r - 1, c);
						un += chk(r + 1, c);
						un += chk(r, c - 1);
						un += chk(r, c + 1);
						//cerr << "-- " << r << " " << c << " " << un << endl;
					}
				}
			}
/*for (int i = 0; i < occ.size(); i++) {
	if (i % C == 0) cerr << endl;
	cerr << occ[i] << ' ';
}
cerr << "-> " << un << endl;*/
			best = min(best, un / 2);
		} while (next_permutation(occ.begin(), occ.end()));
		cout << "Case #" << t << ": " << best << endl;
//		cerr << "Case #" << t << ": " << best << endl;
	}
	return 0;
}