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

int barber[1005];
struct xd{
	int time, num;
	inline bool operator<(const xd& b) const {
		return time^b.time?time>b.time:num>b.num;
	}
};

int main() {
#ifdef KEVINPTT
	//freopen("a.in", "r", stdin);
	//freopen("a.ans", "w", stdout);
#endif
	DRI(T);
	REP1(casen, T) {
		priority_queue<xd> pq; // (total time, id)
		DRII(n, m);
		int gcdd = 1, lcmm, tmp2 = 0;
		REP(i, n) {
			RI(barber[i]);
			gcdd = __gcd(gcdd, barber[i]);
			pq.push(xd{0, i});
		}
		lcmm = gcdd;
		REP(i, n)
			lcmm *= barber[i]/gcdd;
		REP(i, n)
			tmp2 += lcmm/barber[i];
		m = (m-1)%tmp2+1;
		xd _;
		REP(i, m-1) {
			_  = pq.top();
			pq.pop();
			_.time += barber[_.num];
			pq.push(_);
		}
		printf("Case #%d: %d\n", casen, pq.top().num+1);
	}
	
	return 0;
}

