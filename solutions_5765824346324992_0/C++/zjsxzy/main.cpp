#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 1000 + 5;
int N, B;
int M[MAXN];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
LL count(LL t) {
	LL sum = 0;
	for (int i = 0; i < B; i++) {
		if (t % M[i] == 0) sum += t / M[i];
		else sum += t / M[i] + 1;
	}
	// cout << sum << endl;
	return sum;
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
    int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		cin >> B >> N;
		for (int i = 0; i < B; i++) {
			cin >> M[i];
		}
		LL lo = 0, hi = 1LL << 60, ret = -1;
		while (lo <= hi) {
			LL mid = (lo + hi) >> 1;
			if (count(mid) >= N) {
				ret = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		// cout << ret << endl;
		int cnt = count(ret - 1), barber = -1;
		for (int i = 0, j = 0; i < B; i++) {
			if (M[i] == 1 || ret % M[i] == 1) {
				j++;
				if (j == N - cnt) {
					barber = i;
				}
			}
		}
		// cout << ret << endl;
		// for (int i = 0; i < available.size(); i++)
		// 	cout << available[i] << " ";
		// cout << cnt << endl;
		printf("Case #%d: %d\n", cas, barber + 1);
		// printf("Case #%d: %lld\n", cas, ret);
	}
	return 0;
}

