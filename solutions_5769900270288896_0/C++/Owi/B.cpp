#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>
#include <cstring>
#include <list>
#include <stack>
using namespace std;

typedef long long LL;
typedef unsigned int UI;

const int MAXN = 511111;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const LL MAXL = (LL)(0x7fffffffffffffff);
const int MAXI = 0x7fffffff;

bool mt[22][22];
int off[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("outputA.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	for(int cases = 1; cases <= T; cases++){
		int R, C, n;
		cin >> R >> C >> n;
		int ans = 3333333, x = R * C;
		for(int i = 0; i < (1 << x); i++){
			int d = 0;
			for(int j = 0; j < x; j++){
				d += (1 & (i >> j));
			}
			if(d == n){
				memset(mt, 0, sizeof(mt));
				for(int j = 0; j < x; j++){
					mt[j / C][j % C] = (1 &(i >> j));
				}
				int a = 0;
				for(int j = 0; j < R; j++){
					for(int k = 0; k < C; k++){
						if(mt[j][k] == 0) continue;
						for(int o = 0; o < 4; o++){
							int nj = j + off[o][0], nk = k + off[o][1];
							if(nj >= 0 && nj < R && nk >= 0 && nk < C && mt[nj][nk]) a++;
						}
					}
				}
				ans = min(ans, a / 2);
			}
		}
		printf("Case #%d: %lld\n", cases, ans);
	}
}