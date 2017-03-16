#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const int N = 128;

int calc(int cnt[], int n) {
	int mi = cnt[0], ma = cnt[0];
	REP(i, n) {
		mi = min(mi, cnt[i]);
		ma = max(ma, cnt[i]);
	}
	int res = N;
	for (int k = mi; k <= ma; k++) {
		int sum = 0;
		REP(i, n) {
			sum += abs(cnt[i] - k);
		}
		res = min(res, sum);
	}
	return res;
}

int main() {
	freopen("a-small.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	int T;
	int n;
	string s[N];
	int pos[N];
	int cnt[N];
	cin >> T;
	REP(t, T) {
		cin >> n;
		REP(i, n) cin >> s[i];
		memset(pos, 0, sizeof(pos));
		char now = 0;
		int res = 0;
		bool ok = true;
		bool run = true;
		while(run) {
			REP(i, n) {
				if (i == 0) {
					now = s[i][pos[i]];
				}
				int count = 0;
				while(s[i][pos[i]] == now) {
					count ++;
					pos[i]++;
				}
				if (pos[i] == s[i].size()) {
					run = false;
				}
				if (count == 0) {
					ok = false;
					break;
				}
				cnt[i] = count;
			}
			res += calc(cnt, n);
		}
		REP(i, n) {
			if (pos[i] != s[i].size()) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			printf("Case #%d: Fegla Won\n", t + 1);
		} else {
			printf("Case #%d: %d\n", t + 1, res);
		}
	}
	return 0;
}
