//============================================================================
// Name        : GCJ_A.cpp
// Author      : ftfish
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int mn = 105, mlen = 105;

char s[mn][mlen], cs[mn][mlen];
int a[mn][mlen];

void compress(char *s, char *cs, int *a) {
	int l = strlen(s), p = 1;
	cs[0] = s[0];
	a[0] = 1;
	for (int i = 1; i < l; ++i) {
		if (s[i] == s[i - 1]) {
			a[p - 1]++;
		} else {
			cs[p] = s[i];
			a[p] = 1;
			p++;
		}
	}
	cs[p] = 0;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int Tn;
	scanf("%d", &Tn);
	for (int Tc = 1; Tc <= Tn; ++Tc) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			compress(s[i], cs[i], a[i]);
//			printf("cs[%d] = %s\n", i, cs[i]);
//			for(int j=0;j<strlen(cs[i]);++j) {
//				printf("%d", a[i][j]);
//			}
//			putchar('\n');
		}
		bool invalid = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (strcmp(cs[i], cs[j]) != 0) {
					invalid = 1;
				}
			}
		}

		printf("Case #%d: ", Tc);
		if (invalid) {
			printf("Fegla Won\n");
		} else {

			int m = strlen(cs[0]);
			long long ans = 0;
			for (int i = 0; i < m; ++i) {
				int maxc = 0;
				for (int j = 0; j < n; ++j)
					if (a[j][i] > maxc)
						maxc = a[j][i];
				long long ans_step = 1ll << 60;
				for (int j = 1; j <= maxc; ++j) {
					long long t = 0;
					for (int k = 0; k < n; ++k) {
						t += abs(a[k][i] - j);
//						cout << a[k][i]  <<" " << j << endl;
					}
					if (t < ans_step)
						ans_step = t;
				}
				ans += ans_step;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
