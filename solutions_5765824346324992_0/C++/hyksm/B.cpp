#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <complex>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const double EPS = 0.0000000001;
const long long int INF = 1000000000;

int N;
int B;
int M[1000];

ll cnt(ll time)
{
	if (time < 0) return 0;

	ll res = 0;
	for (int i = 0; i < B; ++i) {
		res += time / M[i] + 1;
		//res += (time % M[i] != 0);
	}
	return res;
}

int solve()
{
	ll lb = -1, ub = 1e14+1;
	while (ub - lb > 1) {
		ll mb = (lb + ub) / 2;
		ll t = cnt(mb);
		//printf("mb: %lld, t: %lld\n", mb, t);
		if (t >= N) {
			ub = mb;
		} else {
			lb = mb;
		}
	}

	ll diff = N - cnt(ub - 1);
	//printf("%lld %lld\n", ub, diff);
	for (int i = 0; i < B; ++i) {
		if (ub % M[i] == 0) {
			--diff;
			if (diff == 0) return i + 1;
		}
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int j = 0; j < T; ++j) {
		scanf("%d %d", &B, &N);
		for (int i = 0; i < B; ++i) {
			scanf("%d", &M[i]);
		}
		printf("Case #%d: %d\n", j + 1, solve());
	}

	return 0;
}

