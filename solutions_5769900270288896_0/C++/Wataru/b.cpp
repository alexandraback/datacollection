#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;



int n, r, c;

void Load()
{
	cin >> r >> c >> n;
}


// R, mask < 2^c, total -> min inner conflicts;
int dp[20][20][20];



int bits(int x) {
	int i;
	int ans = 0;
	for (i = 0; i < (1 << c); i++) {
		if (x & (1 << i)) ans++;
	}
	return ans;
}

void Solve()
{
	if (r < c)
	{
		int t = r;
		r = c;
		c = t;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;



	int i, m, t;
	for (i = 0; i < r; i++) {
		for (m = 0; m < (1 << c); m++) {
			for (t = 0; t <= n; t++) {
				if (dp[i][m][t] == -1) continue;
				//cerr << i << ' ' << m << ' ' << t << " : " << dp[i][m][t] << "\n";
				for (int mm = 0; mm < (1 << c); mm++) {
					int cur = dp[i][m][t] + bits(mm & m) + bits(mm & (mm >> 1));
					int nt = t + bits(mm);
					//cerr << "appl mask " << mm << " nt = " << nt << " cur = " << cur << "\n";
					if (dp[i+1][mm][nt] == -1 || dp[i+1][mm][nt] > cur) {
						dp[i+1][mm][nt] = cur;
				    }
				}
			}

		}
	}
	int mn = 4*n;
	for (m = 0; m < (1 << c); m++) {
		if (dp[r][m][n] != -1 && dp[r][m][n] < mn)
			mn = dp[r][m][n];	
	}

	cout << mn << "\n";

}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
