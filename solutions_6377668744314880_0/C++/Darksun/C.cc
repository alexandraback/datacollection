#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector <int> VI;
typedef pair <int, int> PII;
const int MAXN = 1e6 + 7, Mo = 1e9 + 7;

inline int zero(LL x){
	return x == 0;
}
inline int sgn(LL x){
    return (x > 0 ? 1 : (x < 0 ? -1 : 0));
}
struct point{
	LL x, y;
	point(LL x, LL y):x(x), y(y) {}
	point() {}
	bool operator == (const point & a) const{
	    return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
    }
	bool operator  < (const point & a) const{
	    return sgn(x - a.x) < 0 || (sgn(x - a.x) == 0 && sgn(y - a.y) < 0);
    }
	point operator + (const point & a) const{
	    return point(x + a.x, y + a.y);
    }
	point operator - (const point & a) const{
	    return point(x - a.x, y - a.y);
    }
	point operator * (const double & a) const{
	    return point(x * a, y * a);
    }
	point operator / (const double & a) const{
	    return point(x / a, y / a);
    }
	LL operator * (const point & a) const{
	    return x * a.y - y * a.x;
    }//xmult
	LL operator ^ (const point & a) const{
	    return x * a.x + y * a.y;
    }//dmult
};

typedef vector <point> VP;


inline int SideLD(point l1, point l2, point p){
    return sgn((l2-l1)*(p-l1));
}
int ConvexHull (VP &p, VP &v){
    sort(p.begin(),p.end());
	int n = p.size();
    point q[n];
    int r=0;
    for (int i=0; i<n; i++){
        while (r>1 && SideLD(q[r-2],q[r-1],p[i])!=1) r--;
        q[r++]=p[i];
    }
    int l=r;
    for (int i=n-2; i>=0; i--){
        while (r>l && SideLD(q[r-2],q[r-1],p[i])!=1) r--;
        q[r++]=p[i];
    }
    if (n!=1) r--;
	v.clear();
    for (int i=0; i<r; i++) v.push_back(q[i]);
    return r;
}

point a[MAXN];
int n;

void init(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		int x, y; scanf("%d%d", &x, &y);
		a[i] = point(x, y);
	}
}

VP v, t;
int ans[MAXN];

inline bool DotOnSeg(point &p, point &l1, point &l2){
    return zero((l2-l1)*(p-l1)) && sgn((l1-p)^(l2-p))<=0;
}

void calc(int mask){
	v.clear();
	for (int i=0; i<n; i++)
		if ((mask>>i)&1) v.push_back(a[i]);
	if (v.size() == 0) return;
	t.clear();
	ConvexHull(v, t);
	t.push_back(t[0]);
	int cut = n - v.size();
	
	for (int i=0; i<n; i++){
		for (int j=1; j<(int)t.size(); j++) 
			if (DotOnSeg(a[i], t[j-1], t[j]) || a[i] == t[j]){
				ans[i] = min(ans[i], cut);
			}
	}
}

void dfs(int s, int mask){
	if (s == n){
		calc(mask); return;
	}
	dfs(s+1, mask);
	dfs(s+1, mask|(1<<s));
}

void brute(){
	v.clear();
	memset(ans, 1, sizeof(ans));
	dfs(0, 0);
	for (int i=0; i<n; i++) printf("%d\n", ans[i]);
}

int main(){
	int t; scanf("%d", &t);
	for (int cas = 1; cas <= t; cas ++){
		printf("Case #%d:\n", cas);
		init();
		brute();
	}
	return 0;
}

