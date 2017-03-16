#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

using namespace std;

template<typename T> T mabs(const T &a){ return a<0 ? -a : a; }
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;


void init() {
	//return;
	//memset(dyn, -1, sizeof(dyn));
	//dyn[1] = 1;
	//bfs();
}

int stupidCalc(int r, int c, int n) {
	int res = 0;
	if (c == 1) {
		int happyCount = (r + 1) / 2;
		int cornCount = (r + 1) % 2;
		n -= min(n, happyCount);
		int cc = min(n, cornCount);
		n -= cc;
		res += cc;
		res += 2 * n;
	}
	else {
		int happyCount = (r * c + 1) / 2;
		int cornCount = (r * c) % 2 ? 0 : 2;
		n -= min(n, happyCount);
		int cc = min(n, cornCount);
		n -= cc;
		res += 2 * cc;
		int sideCount = 0;
		if ((r & 1) && (c & 1)) {
			sideCount += r + c - 2;
		}
		else if (r & 1) {
			sideCount += r / 2 * 2 - 1 + c - 2;
		}
		else if (c & 1) {
			sideCount += c / 2 * 2 - 1 + r - 2;
		}
		else {
			sideCount += r + c - 4;
		}
		int side = min(sideCount, n);
		n -= side;
		res += 3 * side;
		res += 4 * n;
	}
	return res;
}

int stupidCalc2(int r, int c, int n) {
	int res = 0;
	if (c == 1) {
		return 1e9;
	}
	int happyCount = (r * c) / 2;
	int cornCount = (r * c) % 2 ? 4 : 2;
	n -= min(n, happyCount);
	int cc = min(n, cornCount);
	n -= cc;
	res += 2 * cc;
	int sideCount = 0;
	if ((r & 1) && (c & 1)) {
		sideCount += r + c - 6;
	}
	else if (r & 1) {
		sideCount += r / 2 * 2 - 1 + c - 2;
	}
	else if (c & 1) {
		sideCount += c / 2 * 2 - 1 + r - 2;
	}
	else {
		sideCount += r + c - 4;
	}
	int side = min(sideCount, n);
	n -= side;
	res += 3 * side;
	res += 4 * n;
	return res;
}

int bestBoard[20][20];

int cleverCalc(int r, int c, int n) {
	int rcm = r * c;
	int board[20][20];
	int bestVal = 100500;
	rep(mask, 0, 1 << rcm) {
		if (__builtin_popcount(mask) != n)
			continue;
		rep(i, 0, r) {
			rep(j, 0, c) {
				board[i][j] = (mask >> (i * c + j)) & 1;
			}
		}

		int curVal = 0;
		rep(i, 0, r) {
			rep(j, 0, c - 1) {
				if (board[i][j] && board[i][j + 1])
					curVal++;
			}
		}
		rep(i, 0, r - 1) {
			rep(j, 0, c) {
				if (board[i][j] && board[i + 1][j])
					curVal++;
			}
		}
		if (bestVal > curVal) {
			bestVal = curVal;
			memcpy(bestBoard, board, sizeof(board));
		}
	}
	return bestVal;
}

void test() {
	int n, r, c;
	scanf("%d%d%d", &r, &c, &n);
	if (r < c)
		swap(r, c);
	int res = stupidCalc(r, c, n);
	int res2 = stupidCalc2(r, c, n);
	res = min(res, res2);
	//int trueRes = cleverCalc(r, c, n);
	//if (res != trueRes) {
	//	printf("%d %d %d %d %d\n", r, c, n, res, trueRes);
	//	rep(i, 0, r) {
	//		rep(j, 0, c) {
	//			printf("%d ", bestBoard[i][j]);
	//		}
	//		printf("\n");
	//	}
	//}
	printf("%d\n", res);
}

void run()
{
	init();
	int tc;
	scanf("%d", &tc);
	rep(i, 0, tc) {
		printf("Case #%d: ", i + 1);
		test();
	}
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	time_t st = clock();
#else 
#ifdef prob
	freopen(prob".in", "r", stdin);
	freopen(prob".out", "w", stdout);
#endif
#endif

	run();

#ifdef LOCAL_DEBUG
	fprintf(stderr, "\n=============\n");
	fprintf(stderr, "Time: %.2lf sec\n", (clock() - st) / double(CLOCKS_PER_SEC));
#endif

	return 0;
}