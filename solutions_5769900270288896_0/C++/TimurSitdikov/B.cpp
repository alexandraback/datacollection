#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

const int MAXN = 105, INF = 1e8;
int c[MAXN][MAXN];

void output(int t, int v){
	cout << "Case #" << t << ": " << v << endl;
}

void full_solve(int t, int n, int m, int v){
	int i, j, k, cnt = 1 << (n * m), cnt1 = n * m, ans = INF;
	for(k = 0; k < cnt; k++){
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				c[i][j] = 0;
			}
		}
		int bit_cnt = 0, tmp = k;
		for(i = 0; i < cnt1; i++, tmp >>= 1){
			if (tmp & 1){
				bit_cnt++;
			}
		}
		if (bit_cnt != v){
			continue;
		}
		tmp = k;
		for(i = 0; i < cnt1; i++, tmp >>= 1){
			if (tmp & 1){
				c[i / m][i % m] = 1;
			}
		}
		int cur = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if (c[i][j]){
					if (i < n - 1 && c[i + 1][j]){
						cur++;
					}
					if (j < m - 1 && c[i][j + 1]){
						cur++;
					}
				}
			}
		}
		/*if (k == 495){
			for(i = 0; i < n; i++){
				for(j = 0; j < m; j++){
					printf("%d", c[i][j]);
				}
				putchar('\n');
			}
			printf("%d %d %d\n", k, cur, ans);
		}*/
		ans = min(ans, cur);
	}
	output(t, ans);
	return;
}

void solve(int t){
	int n, m, v, i, j, k, dif, ans, tot_cnt;
	cin >> n >> m >> v;
	if (n > m){
		swap(n, m);
	}
	if (v <= (n * m + 1) / 2){
		output(t, 0);
		return;
	}
	/*if (n * m <= 16){
		full_solve(t, n, m, v);
		return;
	}*/
	dif = n * m - v;
	tot_cnt = (n - 1) * m + (m - 1) * n;
	if (n == 1){
		output(t, m - 1 - dif * 2);
		return;
	}
	if (n == 2){
		ans = tot_cnt - 3 * dif;
		if (dif == m - 1){
			ans++;
		}
		output(t, ans);
		return;
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			c[i][j] = 1;
		}
	}
	int cnt4, cnt3, ans1, ans2, dif1, dif2;
	cnt4 = ((n - 2) * (m - 2) + 1) / 2;
	cnt3 = (n - 2) / 2 + (m - 2) / 2 + (n - 2) / 2 + (m - 2) / 2;
	if ((n & 1) && !(m & 1)){
		cnt3++;
	}
	if (!(n & 1) && (m & 1)){
		cnt3++;
	}
	dif1 = dif;
	ans1 = min(dif1, cnt4) * 4;
	dif1 -= min(dif1, cnt4);
	ans1 += min(dif1, cnt3) * 3;
	dif1 -= min(dif1, cnt3);
	ans1 += dif1 * 2;

	cnt4 = (n - 2) * (m - 2) / 2;
	cnt3 = (n - 1) / 2 + (m - 1) / 2 + (n - 2) / 2 + (m - 2) / 2;
	if ((n & 1) && (m & 1)){
		cnt3 += 2;
	}
	dif2 = dif;
	ans2 = min(dif2, cnt4) * 4;
	dif2 -= min(dif2, cnt4);
	ans2 += min(dif2, cnt3) * 3;
	dif2 -= min(dif2, cnt3);
	ans2 += dif2 * 2;

	ans = tot_cnt - max(ans1, ans2);
	output(t, ans);
}	

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);	
	}
}
