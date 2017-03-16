#include <iostream>
using namespace std;

int N;
int m[1005];

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> m[i];
			
		// compute (1)
		int res1 = 0;
		for (int i = 1; i < N; i++) {
			if (m[i] < m[i-1]) res1 += m[i-1] - m[i];
		}
		
		// compute (2)
		int res2 = 0;
		int minrate = 0;
		for (int i = 1; i < N; i++) {
			if (m[i] < m[i-1]) minrate = max(minrate, m[i-1] - m[i]);
		}
		for (int i = 0; i < N-1; i++) {
			res2 += min(minrate, m[i]);
		}
		
		cout << "Case #" << icase << ": " << res1 << " " << res2 << endl;
	}
	return 0;
}
