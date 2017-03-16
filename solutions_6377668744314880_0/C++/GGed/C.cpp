#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;


struct vect{
	LLD x, y;
	int z;
	vect(){}
	vect(LLD x, LLD y) : x(x), y(y){}
	vect operator + (vect const &T) const{return vect(x+T.x, y+T.y);}
	vect operator - (vect const &T) const{return vect(x-T.x, y-T.y);}
	vect operator * (LLD const &t) const{return vect(x*t, y*t);}
	LLD operator % (vect const &T) const{return x*T.x + y*T.y;}
	LLD operator ^ (vect const &T) const{return x*T.y - y*T.x;}
	bool operator < (vect const &T) const{return x==T.x ? y<T.y : x<T.x;}
};

int CH(vect p[], int n, vect r[]){
	int m = 0;
	sort(p, p + n);
	for (int i=0; i<n; i++){
		while (m > 1 && ((p[i]-r[m-1])^(r[m-2]-r[m-1])) < 0) m--;
		r[m++] = p[i];
	}
	for (int i=n-2, t=m; i>=0; i--){
		while (m > t && ((p[i]-r[m-1])^(r[m-2]-r[m-1])) < 0) m--;
		r[m++] = p[i];
	}
	return m;
}

int ret[20];
vect p[20], r[50], pp[20];

void solve(int tc){
	int n;
	scanf("%d", &n);
	FOR(i,0,n) scanf("%lld%lld", &p[i].x, &p[i].y), p[i].z = i, ret[i] = n;
	FOR(i,1,1<<n){
		int t = 0;
		FOR(j,0,n) if (i & (1<<j)) pp[t++] = p[j];
		int m = CH(pp, t, r);
		FOR(j,0,m){
			int id = r[j].z;
			ret[id] = min(ret[id], n - t);
		}
	}

	printf("Case #%d:\n", tc);
	FOR(i,0,n) printf("%d\n", ret[i]);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
