#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int N = 11111;

long long n, id;
long long b[N];

bool check(long long t) {
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		res += t / b[i] + 1;
	}
	return res >= id;
}

int main() {
	freopen("B_.in", "r", stdin);
	freopen("B_.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for (int T = 1; T <= TT; ++T) {
		printf("Case #%d: ", T);
		scanf("%I64d %I64d", &n, &id);
		for (int i = 1; i <= n; ++i) {
			scanf("%I64d", b + i);
		}
		long long ll = -1, rr = id * 100000LL + 10LL;
		while (ll < rr - 1) {
			long long mm = (ll + rr) / 2;
			if (check(mm)) rr = mm;
			else ll = mm;
		}
		long long tmp = 0;
		for (int i = 1; i <= n; ++i) {
			tmp += ll / b[i] + 1;
		}
		id -= tmp;
		for (int i = 1; i <= n; ++i) {
			if (rr % b[i] == 0) {
				--id;
				if (!id) {
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}
