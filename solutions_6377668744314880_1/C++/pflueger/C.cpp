#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
ll X[3000];
ll Y[3000];

//Computes cross product of z_j-z_i and z_k-z_i.
ll cross(int i, int j, int k) {
	ll a = X[j]-X[i];
	ll b = Y[j]-Y[i];
	ll c = X[k]-X[i];
	ll d = Y[k]-Y[i];
	return (a*d-b*c);
}

int quadrant(int x, int y) {
	if (x > 0 && y>= 0) return 1;
	if (x <= 0 && y > 0) return 2;
	if (x<0 && y <= 0) return 3;
	if (x >= 0 && y < 0) return 4;
	return 0;
}

//Compare angles of points with indices a and b, from origin. angles in [0,2pi).
int o = -1; //Used as index of origin. Will change throughout. Bit of a hack.
bool compare(int a, int b) {
	int qa = quadrant(X[a]-X[o],Y[a]-Y[o]);
	int qb = quadrant(X[b]-X[o],Y[b]-Y[o]);
	if (qa != qb) return (qa < qb);
	//Now can assume in the same quadrant and compare with cross product
	return ( cross(o,a,b) > 0);
}

void doCase() {
	cin >> N;
	for (int n=0; n<N; n++) cin >> X[n] >> Y[n];
	
	//Edge case
	if (N <= 3) {
		for (int n=0; n<N; n++) cout << "0" << endl;
		return;
	}
	
	vector<int> v(N-1);

	for (int n=0; n<N; n++) {
		//fprintf(stderr,">>>Around (%d,%d)\n",X[n],Y[n]);
		int best = N-1;
		for (int m=0; m<N; m++) {
			if (m<n) v[m] = m;
			if (m>n) v[m-1] = m;
		}
		o = n; //Set the origin for sorting
		sort(v.begin(),v.end(),compare);
		//for (int i=0; i<N-1; i++) fprintf(" (%d, %d)",X[v[i]],Y[v[i]]
		
		int j=1;
		for (int i=0; i<N-1; i++) {
			while (cross(n,v[i],v[j]) > 0) {
				j++;
				if (j == N-1) j = 0;
			}
			int between = j-i;
			if (between < 0) between += (N-1);
			best = min(best,max(between-1,0));
		}
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
