/*******************\
|* # By longbiau # *|
\*******************/

#define _CRT_SECURE_NO_WARNINGS

// #include C {
#include<cstring>
#include<cassert>
#include<cstdio>
#include<cctype>
#include<cmath>
// }

// #include C++ {
#include<functional>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
typedef pair <char, char> PCC;
typedef pair <double, double> PDD;
// }
#ifndef ONLINE_JUDGE
// #parameter{
#define TYPE decltype
/////////////////////////////////////////////////////////////
#else
/////////////////////////////////////////////////////////////
#define TYPE __typeof
// }
#endif
// #define {
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = 2.0*acos(0.0);
const double EPS = 1e-6;

#define GREATER(x, y) ((x) > (y) + EPS)
#define GREATER_EQUAL(x, y) ((x) > (y) - EPS)
#define LESS(x, y) ((x) < (y) - EPS)
#define LESS_EQUAL(x, y) ((x) < (y) + EPS)
#define EQUAL(x, y) (abs((x) - (y)) < EPS)

#define MAX_N 105
#define MAXX 0x3f
#define UPPER 2147483647LL
#define INT_MAX 2147483647
#define INF (1<<29)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
char s[MAX_N][MAX_N];
vector < pair<char, int> > V[MAX_N];
int n;
void init(){
	for (int i = 0; i < MAX_N; i++)
		V[i].clear();
}
bool solvable(){
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (SZ(V[i]) != SZ(V[j]))
				return false;
			for (int k = 0; k < SZ(V[i]); k++){
				if (V[i][k].X != V[j][k].X)
					return false;
			}
		}
	}
	return true;
}
int go(){
	int total = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			for (int k = 0; k < SZ(V[i]); k++)
				total += abs(V[i][k].Y - V[j][k].Y);
		}
	}
	return total / (n - 1);
}
/////////////////////////////////////////////////////////////
int main(){
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%s", s[i]);
			int m = strlen(s[i]);
			V[i].PB(MP(s[i][0], 1));
			for (int j = 1; j < m; j++){
				if (s[i][j] != V[i].back().X)
					V[i].PB(MP(s[i][j], 1));
				else
					V[i].back().Y++;
			}
		}
		printf("Case #%d: ", t); 
		if (!solvable()){
			puts("Fegla Won");
		}
		else{
			printf("%d\n", go());
		}
	}
	return 0;
}
