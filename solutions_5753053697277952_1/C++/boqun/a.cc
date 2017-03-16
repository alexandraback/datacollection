#include <iostream>

using namespace std;

int T;
int N;

int P[30];

int main()
{
	cin >> T;

	for (int n = 1; n <= T; n++) {
		cin >> N;
		int total = 0;

		for (int p = 0; p < N; p++) {
			cin >> P[p];
			total += P[p];
		}

		cout << "Case #" << n << ":";
		while (total > 0) {
			int fst = 0;
			int sec = 0;
			int fid = -1;
			int sid = -1;
			for (int i = 0; i < N; i++) {
				if (fst < P[i]) {
					sec = fst;
					sid = fid;
					fst = P[i];
					fid = i;
				}
				else if (sec < P[i]) {
					sec = P[i];
					sid = i;
				}
			}

			if (fst - sec >= 2) {
				cout << " " << (char)('A' + fid) << (char)('A' + fid);
				P[fid] -=2;
				total -=2;
			}
			else if (fst - sec == 1) {
				cout << " " << (char)('A' + fid);
				P[fid]--;
				total--;
			}
			else if (fst == sec && fst + sec < total) {
				cout << " " << (char)('A' + fid);
				P[fid]--;
				total--;
			}
			else {
				cout << " " << (char)('A' + fid) << (char)('A' + sid);
				P[fid]--;
				P[sid]--;
				total -=2;
			
			}

		}

		cout << endl;

	}
}
