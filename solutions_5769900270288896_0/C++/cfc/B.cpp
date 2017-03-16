#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cstring>
#define oo (int)1e9
#define fill( a , v ) memset( a , v , sizeof (a) )
#define bits( x ) __builtin_popcount( x )
#define gcd( a , b ) __gcd( a, b )
#define lcm( a , b ) (a/gcd( a, b ) ) * b
#define s(n)scanf( "%d" , &n )
#define add push_back
const int mxn = 1000000 + 10;
typedef long long ll;
#define pii pair<double,double>
using namespace std;
int cs, T;
int n, m, total;
int dp[16][1<<16][16];
int cBits[1<<16];

int consecutiveBits(int mask) {
	if(cBits[mask] != -1) return cBits[mask];

	bool prevSet = 0;
	int cnt = 0;
	for(int i=0;i<m;i++) {
		if(i == 0) {
			prevSet = (mask & (1<<i)) > 0;
		}
		else {
			if(prevSet && (mask & (1<<i)) > 0)
				cnt++;
			prevSet = (mask & (1<<i)) > 0;
		}
	}
	cBits[mask] = cnt;
	return cnt;
}

int solve(int row, int prevMask, int left) {

	if(left < 0) return oo;
	if(row == n) return left == 0 ? 0 : oo;

	int &d = dp[row][prevMask][left];
	if(~d) return d;
	d = oo;

	for(int mask=0;mask<(1<<m);mask++) {
		if (left - bits(mask) >= 0) {
			int noisy = 0;
			for(int i=0;i<m;i++) {
				int prevBit = (prevMask & (1<<i)) > 0;
				int curBit = (mask & (1<<i)) > 0;
				noisy += curBit && prevBit;
			}
			d = min(d, consecutiveBits(mask) + noisy + solve(row + 1, mask, left - bits(mask)));
		}
	}
	return d;
}

int main() {
	int first, second;
	s(T);

	while(T--) {
		fill(dp, -1);
		fill(cBits, -1);
		cin >> n >> m >> total;

		int ans = oo;
		for(int i=0;i<(1<<m);i++) {
			ans = min(ans, consecutiveBits(i) + solve(1, i, total - bits(i)));
		}
		printf("Case #%d: %d\n", ++cs, ans);
	}
}