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

template<class T>
struct node {
	T x, y;
	node() {}
	node(T _x, T _y) : x(_x),y(_y) {}
	node operator+(const node<T>& rhs)const
		{ return node(x+rhs.x,y+rhs.y); }
	node operator-(const node<T>& rhs)const
		{ return node(x-rhs.x,y-rhs.y); }
	node operator*(const T& rhs)const
		{ return node(x*rhs,y*rhs); }
	node operator/(const T& rhs)const
		{ return node(x/rhs,y/rhs); }
	ll operator*(const node& rhs)const
		{ return x*rhs.x+y*rhs.y; }
	ll len2()const{ return x*x+y*y; }
	ll len()const{ return sqrt(x*x+y*y); }
	node unit()const{ return *this/len(); }
	ll operator^(const node& rhs)const{ return x*rhs.y-y*rhs.x; }
	node trans() const{ return node(-y,x); }
	node rot(ll rad)const{ //逆時針旋轉 弧度
		return node(cos(rad)*x-sin(rad)*y, sin(rad)*x+cos(rad)*y);
	}
	bool operator==(const node& b) const { return x==b.x&&y==b.y; }
	bool operator<(const node& b) const { return x!=b.x?x<b.x:y<b.y; }
};

int convex_hull(int n, node<ll> point[], node<ll> ch[]) {
	node<ll>* tmp = new node<ll>[n];
	memcpy(tmp, point, sizeof(node<ll>)*n);
	sort(tmp, tmp+n);
	int top = 0;
	for(int i=0; i<n; ++i) {
		while( top>=2 && ((tmp[i]-ch[top-1])^(ch[top-2]-ch[top-1]))<0 ) --top;
		ch[top++] = tmp[i];
	}
	for(int i=n-2, flag=top+1; i>=0; --i) {
		while( top>=flag && ((tmp[i]-ch[top-1])^(ch[top-2]-ch[top-1]))<0 ) --top;
		ch[top++] = tmp[i];
	}
	if( top>1 && ch[0]==ch[top-1] ) --top;
	return top;
}

node<ll> pts[16], pts2[16], ret[16];
int ans[16];

int main() {
#ifdef KEVINPTT
	//freopen("a.in", "r", stdin);
	//freopen("a.ans", "w", stdout);
#endif
	DRI(T);
	REP1(casen, T) {
		DRI(N);
		REP(i, N) {
			scanf("%lld %lld", &pts[i].x, &pts[i].y);
			ans[i] = N;
		}

		int maxn = 1<<N;
		REP(i, maxn) {
			int top = 0;
			for(int tmp=i, tmp2 = 0; tmp; tmp>>=1, tmp2++)
				if( tmp&1 ) 
					pts2[top++] = pts[tmp2];
			int size = convex_hull(top, pts2, ret);
			REP(i1, size)
				REP(i2, N)
					if( ret[i1] == pts[i2] ) {
						ans[i2] = min(ans[i2], N-top);
					}
		}
		printf("Case #%d:\n", casen);
		REP(i, N)
			printf("%d\n", ans[i]);
	}
	
	return 0;
}

