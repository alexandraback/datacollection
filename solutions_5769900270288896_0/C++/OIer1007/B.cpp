/*************************************************************************
    > File Name: B.cpp
    > Author: wmg_1001
    > Mail: wmg_1007@163.com 
    > Created Time: Sun 03 May 2015 01:42:32 AM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

int S, n, m, tot;

int getnum(int t) {
	int res = 0;
	while (t != 0) {
		if (t & 1) res++;
		t >>= 1;
	}
	return res;
}

int Gett(int a, int b) {
	if (a < 0 || a >= n || b < 0 || b >= m) return 0;
	int t = (a * m) + b;
	return (S >> t) & 1;
}

int main() {
	int T;
	cin >> T;
	for (int case_T = 1; case_T <= T; case_T++) {
		cin >> n >> m >> tot;
		int res = INT_MAX;
		for (S = 0; S < (1 << (n * m)); S++) {
		       if (getnum(S) != tot) continue;
		       int t_res = 0;
		       for (int j = 0; j < n; j++) {
			       for (int k = 0; k < m; k++) {
				       int tt = 0;
				       if (Gett(j, k) == 0) continue;
				       if (Gett(j - 1, k)) tt++;
				       if (Gett(j + 1, k)) tt++;
				       if (Gett(j, k + 1)) tt++;
				       if (Gett(j, k - 1)) tt++;
				       t_res += tt;
			       }
		       }
		       res = min(res, t_res);
		}
		cout << "Case #" << case_T << ": " << res / 2 << endl;
	}
	return 0;
}
	       	       
		