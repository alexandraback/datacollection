#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N;
int B;
int M[1000];

ll count(ll T) {
	ll res = 0;
	for (int i=0; i<B; i++) {
		res += 1 + (T/(ll)M[i]);
	}
	return res;
}

ll seekTime() {
	if (count(0) >= N) return 0;
	if (count(1) >= N) return 1;
	ll lower = 1;
	ll upper = 2;
	while (count(upper) < N) {
		lower = upper;
		upper *= 2;
	}
	while (lower < upper-1) {
		ll mid = (lower+upper)/2;
		if (count(mid) < N) lower = mid;
		else upper = mid;
	}
	return upper;
}

int doCase(int t) {
	cin >> B >> N;
	for (int i=0; i<B; i++) cin >> M[i];
	ll T = seekTime(); //T is the time when you get your hair cut
	if (T == 0) return N; //you get served at time 0 by Barber number N.
	ll place = N - count(T-1); // Your place in line among those cut at time T
	
	vector<int> ids; //Barbers that cut on time T
	for (int i=0; i<B; i++) {
		if (T % ( (ll) M[i] ) == 0) ids.push_back( i+1 );
	}
	sort(ids.begin(),ids.end());
	return ids[ (int)place-1 ];
}

int main() {
	int T; cin >> T;
	fprintf(stderr,"There are %d cases.\n",T);
	for (int t=1; t<=T; t++) {
		printf("Case #%d: %d\n",t,doCase(t));
		fprintf(stderr,"_%d\n",t);
	}
}
