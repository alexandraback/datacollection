#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int T;
int R, C, N;
const int INF = 100000;

int bitCount(int bits)
{
	int num;
	num = (bits >> 1) & 03333333333;
	num = bits - num - ((num >> 1) & 03333333333);  
	num = ((num + (num >> 3)) & 0707070707) % 077;
	return num;
}

void solve()
{
	int minuh = INF;
	int total = R * C;
	int x = (1 << total) - 1;
	for ( ; x >= 0; --x) {
		if (bitCount(x) == N) {
			int uh = 0;
			for (int r = 0; r < R; ++r) {
				for (int c = 0; c < C - 1; ++c) {
					int idx = r * C + c;
					if ((x & (1 << idx)) && (x & (1 << (idx+1)))) {
						uh++;
					}
				}
			}
			for (int c = 0; c < C; ++c) {
				for (int r = 0; r < R - 1; ++r) {
					int idx = r * C + c;
					if ((x & (1 << idx)) && (x & (1 <<(idx+C)))) {
						uh++;
					}
				}
			}
			minuh = min(minuh, uh);
		}
	}
	printf("%d", minuh);
}

int main()
{
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d %d", &R, &C, &N);
		printf("Case #%d: ", t);
		solve();
		printf("\n");
	}
	return 0;
}
