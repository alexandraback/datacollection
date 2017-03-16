#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;

const double eps=1e-6, pi=3.141592653;
const int maxn = 100;

struct POINT{ long long x, y; } a[maxn], p[maxn], vct[maxn], aa[maxn];
int m, n, orgN, ret[maxn], ind[maxn], top;

inline double dist( POINT& a, POINT& b ){
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
inline double mul( POINT& a, POINT& b, POINT& c ){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

inline int int_cmp( const void* p1, const void* p2 ){
	double t = mul( a[1], *(POINT*)p1, *(POINT*)p2 );
	if ( t>0 || t == 0 && dist( a[1], *(POINT*)p1 )<dist( a[1], *(POINT*)p2 ) )
		return -1;else return 1;
}

void Graham(){
	if (n<=3){
		for (int i=1; i<=n; i++)
			p[i] = a[i];
		p[n+1] = p[1]; p[0] = p[n];
		return;
	}

	for (int i=2; i<=n; i++)
	if ( a[i].y<a[1].y || a[i].y==a[1].y && a[i].x<a[1].x ) swap( a[1], a[i] );
	qsort( a+2, n-1, sizeof(a[0]), int_cmp );
	top=2; p[1]=a[1]; p[2]=a[2];
	for (int i=3; i<=n; i++){
		while ( top>1 && mul( p[top-1], a[i], p[top] )>=0 ) top--;
		p[++top] = a[i];
	}
	n = top;
	p[n+1] = p[1]; p[0] = p[n];
}

bool check(POINT& a){
	for (int i=1; i<=n; i++){
		if (a.x==p[i].x && a.y==p[i].y) return true;
		if (mul(a, p[i], p[i+1])==0) return true;
	}
	return false;
}

int task;

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d", &task);
	for (int CASE = 1; CASE<=task; CASE++){
		scanf("%d", &orgN);
		for (int i=0; i<orgN; i++){
			scanf("%lld%lld", &vct[i].x, &vct[i].y);
			ret[i] = orgN-1;
		}

		for (int mask=1; mask<(1<<orgN); mask++){
			//cout<<"----"<<mask<<endl;
			n = 0;
			for (int i=0; i<orgN; i++)
			if ( (1<<i) & mask ){
				n++;
				a[n] = vct[i];
				aa[n] = vct[i];
				ind[n] = i;
				//cout<<"reg "<<a[n].x<<' '<<a[n].y<<' '<<ind[n]<<endl;
			}

			m = n;
			Graham();

			//for (int i=1; i<=n; i++){
			//	cout<<p[i].x<<' '<<p[i].y<<endl;
			//}

			for (int i=1; i<=m; i++){
				if (check(aa[i])){
					//cout<<"go "<<ind[i]<<' '<<orgN-m<<' '<<orgN<<' '<<m<<endl;
					ret[ind[i]] = min(ret[ind[i]], orgN-m);
				}
			}
		}

		printf("Case #%d:\n", CASE);
		for (int i=0; i<orgN; i++){
			printf("%d\n", ret[i]);
		}
	}

	return 0;
}
