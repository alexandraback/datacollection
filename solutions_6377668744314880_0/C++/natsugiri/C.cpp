#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const double PI = M_PI;
typedef pair<LL,LL> Point;
LL cross(const Point &x, const Point &y) {
    return x.first * y.second - x.second * y.first;
}
int N;
Point Z[3333];
void solve() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	Z[i].first = x;
	Z[i].second = y;
    }

    REP (X, N) {
	vector<pair<double, int> > v;
	REP (j, N) {
	    if (X == j) continue;
	    Z[j].first -= Z[X].first;
	    Z[j].second -= Z[X].second;
	    v.push_back(make_pair(atan2(Z[j].second, Z[j].first), j));
	}

	sort(v.begin(), v.end());
	REP (i, v.size()) 
	    v.push_back(make_pair(v[i].first + 2*PI, v[i].second));
	int t = 0;
	int best = N-1;
	REP (i, N-1) {
	    // while (t < i+N-1 && v[i].first+PI > v[t].first) t++;
	    amax(t, i+1);
	    while (t < i+N-1 && cross(Z[v[i].second], Z[v[t].second]) > 0) t++;
	    amin(best, t-i-1);
	}
	printf("%d\n", best);
	
	REP (j, N) {
	    if (X == j) continue;
	    Z[j].first += Z[X].first;
	    Z[j].second += Z[X].second;
	}

    }
}
int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	printf("Case #%d:\n", tc);
	solve();
    }
    return 0;
}
