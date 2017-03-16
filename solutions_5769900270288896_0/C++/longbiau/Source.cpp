// #include C/C++ {
#include <bits/stdc++.h>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
typedef pair <double, double> PDD;
// }

// #parameter{
#define LEN 2
#ifdef DEBUG_MODE

#define TYPE decltype
#define RF(filename) {freopen((filename), "r", stdin);}
#define WF(filename) {freopen((filename), "w", stdout);}
#define DEBUG printf

#else

#define TYPE __typeof
#define RF(filename) {;}
#define WF(filename) {;}
#define DEBUG(...)

#endif

// #define {
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define MP make_pair
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ALL(it) (it).begin(), (it).end()
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-6;

#define MAX_N 10005
#define MAX_M 5005
#define MAXX 0x3f
#define UPPER 2147483647LL
#define INF ((1 << 30) - 1)
#define BINF ((1LL << 62) - 1LL)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
const int OFFR[] = { 0, 1 };
const int OFFC[] = { 1, 0 };
bool tenant[MAX_N][MAX_N];
int R, C, N;
void Solve(){
	if (N == 0)
		return;
	for (int r = 0; r < R; r++) for (int c = 0; c < C; c++){
		if ((r + c) % 2 == 0){
			tenant[r][c] = true;
			if(--N == 0)
				return;
		}
	}
	for (int r = 0; r < R; r++){
		if (!tenant[r][0]){
			tenant[r][0] = true;
			if (--N == 0)
				return;
		}
		if (!tenant[r][C - 1]){
			tenant[r][C - 1] = true;
			if (--N == 0)
				return;
		}
	}
	for (int c = 0; c < C; c++){
		if (!tenant[0][c]){
			tenant[0][c] = true;
			if (--N == 0)
				return;
		}
		if (!tenant[R - 1][c]){
			tenant[R - 1][c] = true;
			if (--N == 0)
				return;
		}
	}
	for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) if (!tenant[r][c]){
		tenant[r][c] = true;
		if (--N == 0)
			return;
	}
}
int GetResult(){
	int res = 0;
	for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) if (tenant[r][c]){
		for (int k = 0; k < 2; k++){
			int nr = r + OFFR[k];
			int nc = c + OFFC[k];
			if (nr >= 0 && nr < R&&nc >= 0 && nc < C && tenant[nr][nc])
				res++;
		}
	}
	return res;
}
static int rres;
void DFS(int depth, int r, int c){
	if (depth == N){
		rres = min(rres, GetResult());
		return;
	}
	if (c == C)
		c = 0, r++;
	if (r == R)
		return;
	tenant[r][c] = true;
	DFS(depth + 1, r, c + 1);
	tenant[r][c] = false;
	DFS(depth, r, c + 1);

}
/////////////////////////////////////////////////////////////
int main(){
	RF("input.txt");
	WF("output.txt");

	int T;
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++){
		memset(tenant, false, sizeof(tenant));
		rres = INF;
		scanf("%d %d %d", &R, &C, &N);
		DFS(0, 0, 0);
		printf("Case #%d: %d\n", _, rres);
		/*Solve();
		for (int r = 0; r < R; r++){
			for (int c = 0; c < C; c++)
				printf("%d ", tenant[r][c]);
			puts("");
		}
		printf("Case #%d: %d\n", _, GetResult());*/
	}
	return 0;
}