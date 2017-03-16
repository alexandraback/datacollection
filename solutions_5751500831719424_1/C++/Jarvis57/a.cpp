//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i ++)
#define DOW(i, a, b) for(int i = a; i >= b; i --)
#define FOREACH(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it ++)
#define RESET(c, val) memset(c, val, sizeof(c))

int test, n;
string S, s[200];
int a[200][200];

int main() {
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	cin >> test;
	FOR(t, 1, test) {
		scanf("%d\n", &n);
		FOR(i, 1, n) {
			getline(cin, S);
			s[i] = ""; int cc = -1; RESET(a[i], 0);
			FOR(j, 0, S.length()-1) if (j == 0 || S[j] != S[j-1]) {
				int z = j;
				while (z < S.length() && S[z] == S[j]) z++;
				s[i] += S[j];
				a[i][++cc] = z-j;
			}
		}
		int res = 1000000000;
		FOR(i, 1, n) if (s[i]!=s[1]) res = -1;
		if (res == -1) printf("Case #%d: Fegla Won\n", t);
		else {
			res = 0;
			FOR(j, 0, s[1].length()-1) {
				int mm = 1000000000;
				FOR(i, 1, n) {
					int rr = 0;
					FOR(z, 1, n) rr += abs(a[i][j] - a[z][j]);
					mm = min(mm, rr); 
				}
				res += mm;
			}
			printf("Case #%d: %d\n", t, res);
		}
	}
	return 0;
}
