#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
using namespace std;

#define INS insert
#define MP make_pair
#define PB push_back

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define MEM(p, v) memset(p, v, sizeof(p))
#define SCD(i) scanf("%d", &(i))

typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1000000007;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int ceil(int a, int b) { return (a + b - 1)/b; }

bool eq(vector<char> v1, vector<char> v2) {
	int sz;
	if ((sz = v1.size()) != v2.size())
		return false;

	FOR (i, 0, sz) {
		if (v1[i] != v2[i])
			return false;
	} return true;
}

int main(void) {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-out.txt", "w", stdout);

	int T;
	scanf("%d\n", &T);
	
	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d\n", &n);
		
		char s1[105], s2[105];
		gets(s1);
		gets(s2);

		int L1 = strlen(s1), L2 = strlen(s2);

		vector<char> v1, v2;
		char last = '-';
		FOR (i, 0, L1) {
			char c = s1[i];
			if (c != last) v1.PB(c);
			last = c;
		} last = '-';

		FOR (i, 0, L2) {
			char c = s2[i];
			if (c != last) v2.PB(c);
			last = c;
		}

		if (!eq(v1, v2)) {
			printf("Case #%d: Fegla Won\n", t);
			continue;
		}

		vector<int> w1, w2;
		int cur = 0;
		FOR (i, 0, L1) {
			if (i == 0 || s1[i] == s1[i - 1]) cur++;
			else {
				w1.PB(cur);
				cur = 1;
			}
		} w1.PB(cur);

		cur = 0;
		FOR (i, 0, L2) {
			if (i == 0 || s2[i] == s2[i - 1]) cur++;
			else {
				w2.PB(cur);
				cur = 1;
			}
		} w2.PB(cur);

		//assert(w1.size() == w2.size());
		int diff = 0;
		FOR (i, 0, w1.size()) {
			diff += abs(w1[i] - w2[i]);
		}
		printf("Case #%d: %d\n", t, diff);
	}

	return 0;
}
