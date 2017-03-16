// Template.cpp by kevinptt 20150108
#include <bits/stdc++.h>
/*
#include <cstdio>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <iostream>
// */
using namespace std;

#define REP(I, N) for(int I=0; I<(N); ++I)
#define REP1(I, N) for(int I=1; I<=(N); ++I)
#define REPP(I, A, B) for(int I=(A); I<(B); ++I)
#define REPR(I, N) for(int I=N-1; I>=0; --I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int X; scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define MP make_pair
#define PB push_back
#define MSET(x, y) memset(x, y, sizeof(x))
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;

/***************************************************************/

int all[1005];

int main() {
#ifdef KEVINPTT
	//freopen("a.in", "r", stdin);
	//freopen("a.ans", "w", stdout);
#endif
	DRI(T);
	REP1(casen, T) {
		DRI(N);
		REP(i, N) RI(all[i]);
		int ans1 = 0, ans2 = 0, rate = 0;
		REP1(i, N-1) {
			if( all[i-1]>all[i] ) {
				ans1 += all[i-1]-all[i];
				rate = max(rate, all[i-1]-all[i]);
			}
		}
		REP1(i, N-1) {
			if( all[i-1]>=rate ) 
				ans2 += rate;
			else
				ans2 += all[i-1];
		}
		printf("Case #%d: %d %d\n", casen, ans1, ans2);
	}
	
	return 0;
}

