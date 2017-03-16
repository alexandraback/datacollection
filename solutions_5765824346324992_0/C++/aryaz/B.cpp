#include <bits/stdc++.h>
using namespace std;

long long m[30];
pair<long long, int> x[30];

int main () {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		long long n;
		int b;
		cin >> b >> n;
		long long s = 0, e = 100000000000001LL;
		for(int i = 0; i < b; i++) {
			cin >> m[i];
		}
		while(e-s > 1LL) {
			long long k = (s+e)/(2LL);
			long long tmp = 0;
			for(int i = 0; i < b; i++)
				tmp += (k+m[i]-1)/m[i];
			if(tmp > n)
				e = k;
			else
				s = k;
		}
		long long tmp = 0;
		for(int i = 0; i < b; i++)
			tmp += (s+m[i]-1)/m[i];
//		cerr << "!!! " << s << " " << tmp << endl;
		if(tmp >= n) {
			s--;
		}
		tmp = 0;
		for(int i = 0; i < b; i++)
			tmp += s/m[i];
//		cerr << "### " << s << " " << tmp << endl;
		for(int i = 0; i < b; i++) {
			x[i] = pair<long long, int>((s/m[i])*m[i], i+1);
		}
		sort(x, x+b);
		cout << "Case #" << t << ": " << x[n-tmp-1].second << endl;
	}
	return 0;
}
