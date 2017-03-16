#include <iostream>
using namespace std;

#define MAXN 1024

int N;
long long n[MAXN];

long long count(long long time) {
	long long RES = 0LL;
	for (int i=0; i<N; i++) RES += time/n[i] + ( time%n[i] ? 1 : 0 );
	return RES;
}

int main() {
	int T, t, i;
	long long s, e, m, M, tmp;

	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> N >> M;
		for (i=0; i<N; i++) cin >> n[i];
		
		s = 0LL; e = ((long long)M)*100000LL+1LL;
		while (e-s > 1LL) {
			m = (s+e)/2LL;
			if (count(m) < M) s = m;
			else e = m;
		}
		
		tmp = M-count(s);
		for (i=0; tmp && i<N; i++) if (s%n[i] == 0) tmp--;
		cout << "Case #" << t << ": " << i << endl;
	}

	return 0;
}
