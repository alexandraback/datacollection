#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>
#pragma comment(linker, "/STACK:640000000")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
char s[111][111],ss[111][111];
int len[111],le[111],ptr[111];
int num[111];
void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s",s[i]);
		len[i] = strlen(s[i]);
		le[i] = 0;
		ptr[i] = 0;
		for (int j = 0; j < len[i]; j++) {
			if (j == 0 || s[i][j] != s[i][j - 1]) {
				ss[i][le[i]++] = s[i][j];
			}
		}
	}
	bool ok = true;
	for (int i = 1; i < n; i++) {
		if (le[i] != le[i - 1]) {
			ok = false;
			break;
		}
		for (int j = 0; j < le[i]; j++) if (ss[i][j] != ss[i - 1][j]) {
			ok = false;
			break;
		}
	}
	if (!ok) {
		puts("Fegla Won");
		return;
	}
	int L = le[0];
	int res = 0;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < n; j++) {
			num[j] = 0;
			while(ptr[j] < len[j] && ss[j][i] == s[j][ptr[j]]) {
				ptr[j]++;
				num[j]++;
			}
			//cout << num[j] << endl;
		}
		int mi = 1111111;
		for (int e = 1; e <= 100; e++) {
			int cur = 0;
			for (int j = 0; j < n; j++) {
				cur += abs(e - num[j]);
			}
			mi = min(cur,mi);
		}
		res += mi;
	}
	cout << res << endl;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int Cases; cin >> Cases; 
	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		solve();
	}
	return 0;
}
