#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <hash_map>
#include <unordered_set>
#include <fstream>

using namespace std;
typedef long long ll;


int N;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int check(int mask, int r, int c, int n)
{
	vector<vector<int> > v(r, vector<int>(c, 0));
	int cnt = 0; 
	for (int i = 0; i < N; ++i)
	{
		if (mask & (1<<i))
		{
			cnt++;
			int x = i / c;
			int y = i%c;
			v[x][y] = true;
		}
	}
	if (cnt != n)
	{
		return 1e9;
	}
	int ans = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (v[i][j])
			{
				for (int q = 0; q < 4; ++q)
				{
					int x = i + dx[q];
					int y = j + dy[q];
					if (x >= 0 && x < r && y >= 0 && y < c)
					{
						if (v[x][y])
							ans++;
					}
				}
			}
		}
	}
	ans /= 2;
	return ans;

}

int main(){
	
	freopen("B-small-attempt0 (3).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	ll test;
	cin >> test;
	for (ll t = 1; t <= test; ++t)
	{
		int r, c, n;
		cin >> r >> c >> n;
		N = r*c;

		int ans = 1e9;
		for (int i = 0; i < (1 << N); ++i)
		{
			ans = min(ans, check(i, r, c, n));
		}

		cout << "Case #" << t << ": " << ans << "\n";

	}


	return 0;
}

