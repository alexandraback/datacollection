#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_a"
const ldb pi = acos(-1.0);
const int N = (int) 1000;
vector<char> data[N];
vector<int> cnt[N], all_cnt;
char s[N];
int t, n;

int main() {
	assert(freopen(taskname".in", "r", stdin));
	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			data[i].clear();
			cnt[i].clear();
			scanf("%s", s);
			for (int j = 0; s[j]; ) {
				int k = j;
				while (s[k] == s[j]) ++k;
				data[i].pb(s[j]);
				cnt[i].pb(k - j);
				j = k;
			}
		}
		int l = sz(data[0]);
		bool lose = false;
		for (int i = 0; i < n; ++i)
			if (data[i] != data[0]) {
				lose = true;
				break;
			}
		printf("Case #%d: ", it + 1);
		if (lose) {
			printf("Fegla Won\n");
			continue;
		}
		int res = 0;
		for (int j = 0; j < l; ++j) {
			all_cnt.clear();
			for (int i = 0; i < n; ++i)
				all_cnt.pb(cnt[i][j]);
			sort(all_cnt.begin(), all_cnt.end());
			int med = all_cnt[n / 2];
			for (int i = 0; i < n; ++i)
				res += abs(med - all_cnt[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}