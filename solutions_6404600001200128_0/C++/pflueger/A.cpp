#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
typedef long long ll;

int m[1000];

void doCase(int t) {
	int N; cin >> N;
	for (int i=0; i<N; i++) cin >> m[i];
	ll meth1 = 0;
	int ts = 0; //This is ten times the eating slope
	for (int i=1; i<N; i++) {
		int diff = m[i-1]-m[i];
		meth1 += (ll) max(0,diff);
		ts = max(ts, diff);
	}
	ll meth2 = 0;
	for (int i=1; i<N; i++) {
		meth2 += (ll) min(m[i-1],ts);
	}
	printf("Case #%d: ",t);
	cout << meth1 << " " << meth2 << endl;
}

int main() {
	int T; cin >> T;
	fprintf(stderr,"There are %d cases.\n",T);
	for (int t=1; t<=T; t++) {
		doCase(t);
		fprintf(stderr,"_%d\n",t);
	}
}
