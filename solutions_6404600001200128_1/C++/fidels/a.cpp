#include <iostream>
using namespace std;

#define MAXN 1024

int main() {
	int T, t, i, N, n[MAXN], RES1, RES2, tmp;
	
	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> N;
		for (i=0; i<N; i++) cin >> n[i];
		
		RES1 = RES2 = tmp = 0;
		for (i=1; i<N; i++) if (n[i] < n[i-1]) { RES1 += n[i-1]-n[i]; tmp = max(tmp, n[i-1]-n[i]); }
		for (i=0; i<N-1; i++) RES2 += min(n[i], tmp);
		
		cout << "Case #" << t << ": " << RES1 << ' ' << RES2 << endl;
	}

	return 0;
}
