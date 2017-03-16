#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
int n;
char g[128][128];
int len[128][128];
int l[128];
int cur[128];
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k){
		printf("Case #%d: ", k);
		scanf("%d", &n);
		int res = 0;
		for (int i = 0; i < n; ++i){
			scanf("%s", g[i]);
			l[i] = strlen(g[i]);
		}
		memset(len, 0, sizeof(len));
		memset(cur, 0, sizeof(cur));
		for (int i = 0; i < n; ++i)
			for (int j = l[i] - 1; j >= 0; --j)
				len[i][j] = 1 + int(g[i][j] == g[i][j + 1])*len[i][j+1];
		while (true){
			int mn = len[0][cur[0]];
			char c = g[0][cur[0]];
			bool no = false;
			for (int i = 0; i < n; ++i){
				if (g[i][cur[i]] != c){
					no = true;
					break;
				}else
					mn = min(mn, len[i][cur[i]]);
			}
			if (mn == 0 && c)
				no = true;
			if (no){
				res = -1;
				break;
			}
			if (!c)
				break;
			int best=1<<29, C;
			for (int c = 1; c <= 128; ++c){
				int cst = 0;
				for (int i = 0; i < n; ++i){
					cst += abs(c - len[i][cur[i]]);
				}
				if (best>cst){
					best = cst;
					C = c;
				}
			}
			for (int i = 0; i < n; ++i){
				res += abs(C - len[i][cur[i]]);
				cur[i] += len[i][cur[i]];
			}
		}
		if (res == -1)
			puts("Fegla Won");
		else
			printf("%d\n", res);
	}
	return 0;
}