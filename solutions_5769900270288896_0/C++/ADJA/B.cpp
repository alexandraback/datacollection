#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 20;

int tn;
int r, c, n;
int a[MAXN][MAXN];
int ans;

void go(int i, int j, int num, int u) {
	if (i > r) {
		if (num == n && u < ans)
			ans = u;
		return;
	}
    int nxi = i, nxj = j + 1;
    if (nxj > c) {
    	nxj = 1;
    	nxi = i + 1;
    }	
    
    go(nxi, nxj, num, u);

    int add = 0;
    if (a[i - 1][j])
    	add++;
	if (a[i][j - 1])
		add++;

	a[i][j] = 1;
	go(nxi, nxj, num + 1, u + add);
	a[i][j] = 0;
}

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &tn);

	for (int test = 1; test <= tn; test++) {
		scanf("%d %d %d", &r, &c, &n);
		
		ans = 1000;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				a[i][j] = 0;

		go(1, 1, 0, 0);

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}