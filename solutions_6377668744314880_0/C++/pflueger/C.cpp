#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
typedef long long ll;

int N;
ll X[3000];
ll Y[3000];

//Computes cross product of z_j-z_i and z_k-z_i.
ll cross(int i, int j, int k) {
	ll a = X[j]-X[i];
	ll b = X[k]-X[i];
	ll c = Y[j]-Y[i];
	ll d = Y[k]-Y[i];
	return (a*d-b*c);
}

void doCase() {
	cin >> N;
	for (int n=0; n<N; n++) cin >> X[n] >> Y[n];

	for (int n=0; n<N; n++) {
		int best = N+1;
		for (int m=0; m<N; m++) {
			if (m==n) continue;
			int side1 = 0;
			int side2 = 0;
			for (int i=0; i<N; i++) {
				ll c = cross(n,m,i);
				if (c>0) side1++;
				if (c<0) side2++;
			}
			best = min(best, min(side1,side2));
		}
		if (N == 1) best = 0;
		cout << best << endl;
	}
}

int main() {
	int T; cin >> T;
	fprintf(stderr,"There are %d cases.\n",T);
	for (int t=1; t<=T; t++) {
		printf("Case #%d:\n",t);
		doCase();
		fprintf(stderr,"_%d\n",t);
	}
}
