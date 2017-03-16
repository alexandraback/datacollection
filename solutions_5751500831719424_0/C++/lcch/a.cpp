#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

const int maxn = 100 + 10;
const int maxl = 100 + 10;
char s[maxn][maxl], t[maxn][maxl];
int m[maxn][maxl], g[maxn], n;

void norepeat(int k)
{
	int w = 0;
	t[k][w] = s[k][0];
	m[k][w] = 1;
	for (int i = 1; i < strlen(s[k]); i++) 
	if (t[k][w] != s[k][i]) {
		++w;
		m[k][w] = 1;
		t[k][w] = s[k][i];
	} else 
		m[k][w] ++;
	g[k] = w;
}

int Abs(int x) {
	return (x > 0) ? x : -x;
}
	
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A_small.out", "w", stdout);
	int TextN;
	scanf("%d", &TextN);
	for (int TT = 1; TT <= TextN; TT++) {
		scanf("%d", &n);
		for (int i = 0; i != n; i++) {
			scanf("%s", s[i]);
			norepeat(i);
		}
		printf("Case #%d: ", TT);
		bool bj = true;
		for (int i = 1; i != n; i++)
			if (g[i] != g[0]) bj = false;
		if (bj) {
			int ans = 0, sum;
			for (int i = 0; i <= g[0]; i++) {
				sum = 0;
				for (int j = 0; j != n; j++)
					if (t[j][i] != t[0][i]) bj = false;
					else sum += m[j][i]; 
				sum = round((double)(sum) / n);
				for (int j = 0; j != n; j++) {
					ans += Abs(m[j][i] - sum);
				}
			}
			if (bj) printf("%d\n", ans);
		}
		if (!bj) printf("Fegla Won\n");
	}
	return 0;
}