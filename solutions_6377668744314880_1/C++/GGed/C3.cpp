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
	vect(){}
	vect(LLD x, LLD y) : x(x), y(y){}
	vect operator + (vect const &T) const{return vect(x+T.x, y+T.y);}
	vect operator - (vect const &T) const{return vect(x-T.x, y-T.y);}
	vect operator * (LLD const &t) const{return vect(x*t, y*t);}
	LLD operator % (vect const &T) const{return x*T.x + y*T.y;}
	LLD operator ^ (vect const &T) const{return x*T.y - y*T.x;}
	bool operator < (vect const &T) const{return x==T.x ? y<T.y : x<T.x;}
};

struct dat{
	vect v;
	LLD x, y, w;
	bool operator < (dat const &T) const{
		return w == T.w ? y*T.x < x*T.y : w < T.w;
	}
};

dat a[6005];
vect p[3005];

void solve(int tc){
	int n;
	scanf("%d", &n);
	FOR(i,0,n) scanf("%lld%lld", &p[i].x, &p[i].y);
	printf("Case #%d:\n", tc);
	FOR(i,0,n){
		int ret = n;
		int t = 0;
		if (n <= 3){
			ret = 0;
			goto END;
		}
		FOR(j,0,n) if (i != j){
			a[t].v = p[j] - p[i];
			a[t].x = p[j].x - p[i].x;
			a[t].y = p[j].y - p[i].y;
			a[t].w = a[t].x > 0 || (!a[t].x && a[t].y > 0);
			++t;
		}
		sort(a, a + t);
		FOR(j,0,t) a[j+t] = a[j];
		{
		int k = 0;
		FOR(j,0,t){
			while (1){
				++k;
				LLD C = a[j].v ^ a[k].v;
				if (C < 0 || k >= j + t){
					--k;
					break;
				}
				if (k == t + t - 1) break;
			}
			ret = min(ret, n - 1 - (k - j + 1));
		}

		}
		
		END:
		printf("%d\n", ret);
	}
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
