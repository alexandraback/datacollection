#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T;
int N;

typedef long long co;
struct pu {
	co x,y;
	pu(co a=0, co b=0) {x=a;y=b;}
};
pu operator-(const pu &a, const pu &b) {
	return pu(a.x-b.x,a.y-b.y);
}
pu operator*(co a, const pu &b) {
	return pu(a*b.x, a*b.y);
}
///orientation
co kr(const pu &a, const pu &b) { // z component of the cross product $a\times b$
	return a.x*b.y-b.x*a.y;
}
co kr(const pu &a, const pu &b, const pu &c) { // z component of the cross product $(b-a)\times (c-a)$
	return kr(b-a,c-a);
}

pu p[4000];

bool cmp(const pu &a, const pu &b) {
	bool upa = a.y > 0 || (a.y == 0 && a.x > 0);
	bool upb = b.y > 0 || (b.y == 0 && b.x > 0);
	if (upa && !upb)
		return true;
	if (upb && !upa)
		return false;
	return kr(a,b) > 0;
}

bool onl(const pu &a, const pu &b) {
	return (kr(a,b) == 0 && a.x*b.x >= 0 && a.y*b.y >= 0);
}

bool sas(const pu &a, const pu &b) {
	return kr(a,b) > 0;
}

int doa(int i) {
	vector<pu> v;
	REP(j,0,N)
		if (j != i)
			v.push_back(p[j]-p[i]);
	sort(v.begin(), v.end(), cmp);
	int NN = N-1;
	int res = NN;
	REP(s,0,NN-1)
		assert(!cmp(v[s+1], v[s]));
	REP(s,0,NN)
		if (kr(v[s], v[(s+1)%NN]) <= 0 && (!onl(v[s], v[(s+1)%NN]) || s == NN-1))
			res = 0;
	if (res != 0) {
		int e = 0;
		REP(s,0,NN) {
			while((e+1)%NN != s && kr(v[s],v[(e+1)%NN])>0)
				e = (e+1)%NN;
			if (!onl(v[s],v[(s+1)%NN]))
				res = min(res, (e-s+NN)%NN);
// 				if (e == s)
// 					e = (e+1)%NN;
		}
	}
	return res;
}

int dob(int i) {
	vector<pu> v;
	REP(j,0,N)
		if (j != i)
			v.push_back(p[j]-p[i]);
	sort(v.begin(), v.end(), cmp);
	int NN = N-1;
	int res = NN;
	REP(s,0,NN-1)
		assert(!cmp(v[s+1], v[s]));
	REP(s,0,NN)
		REP(t,s,NN)
			assert(!cmp(v[t],v[s]));
	REP(s,0,NN) {
		int cnt = 0;
		REP(t,0,NN) {
			if (kr(v[s],v[t]) > 0)
				cnt++;
		}
		res = min(res, cnt);
	}
	return res;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d:\n", test+1);
		scanf("%d", &N);
		REP(i,0,N)
			scanf("%lld%lld", &p[i].x, &p[i].y);
		REP(i,0,N) {
			int res = doa(i);
			printf("%d\n", res);
			if (N < 500)
				assert(doa(i) == dob(i));
		}
	}
	return 0;
}
