#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int seated(const vector<int> &Ms, ll target) {
	int sum = Ms.size();
		for(int b=0;b<Ms.size();++b) {
			sum += target/Ms[b];
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	int T;
	scanf("%d", &T);
	for(int t=0;t<T;++t) {
		int B, N, M;
		scanf("%d%d", &B, &N);
		vector<int> Ms;
		double avg_rate = 0;
		for(int b=0;b<B;++b) {
			scanf("%d", &M);
			Ms.push_back(M);
			avg_rate+= 1.0 / M;
		}

		if (N <= B) {
			printf("Case #%d: %d\n", t+1, N);
			continue;
		}

		ll target = ll(N)/avg_rate-100;
		if (target < 0)
			target = 0;

		assert(seated(Ms, target) < N);
		while(seated(Ms, ++target) < N);

		int N2 = N-seated(Ms, target-1);
		bool printed = false;
		for(int b=0; b<B;++b) {
			if (target%Ms[b] == 0) {
				--N2;
				if (N2 == 0) {
					printf("Case #%d: %d\n", t+1, b+1);
					printed = true;
					break;
				}
			}
		}
		assert(printed);
	}
	return 0;
}