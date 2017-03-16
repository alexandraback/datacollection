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
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(int argc, char const *argv[]) {
	int T;
	scanf("%d", &T);
	for(int t=0;t<T;++t) {
		int N,M;
		vector<int> Ms;

		scanf("%d", &N);
		for(int n=0; n<N;++n) {
			scanf("%d", &M);
			Ms.push_back(M);
		}

		long long tot1 = 0, tot2 = 0;
		int largest = 0;
		for(int n=1; n<N;++n) {
			if (Ms[n] < Ms[n-1])
				tot1 += Ms[n-1]-Ms[n];
			if (Ms[n-1]-Ms[n] > largest)
				largest = Ms[n-1]-Ms[n];
		}
		for(int n=0; n<N-1;++n) {
			tot2 += min(largest, Ms[n]);
		}

		printf("Case #%d: %lld %lld\n", t+1, tot1, tot2);
	}
	return 0;
}