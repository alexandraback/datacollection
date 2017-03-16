#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct vec {
	int x,y;
	int idx;
	vec operator - (const vec& c) const {
		vec r;
		r.x = x-c.x;
		r.y = y-c.y;
		r.idx = -1;
		return r;
	}
};

long long cross(const vec &a,const vec &b) {
	return (long long)a.x*b.y - (long long)a.y*b.x;
}

bool cmpXY(vec a,vec b) {
	if( a.x!=b.x )
		return a.x < b.x;
	return a.y < b.y;
}

vec base;
bool cmpByBase(vec a,vec b) {
	return cross(a-base,b-base) > 0;
}


vec p[10000];
int n;

vec cvx[10000];
int ncvx;

vec pp[10000];
int npp;

int ans[10000];
bool onConvex[10000];



void ConvexHull() {
	sort(p,p+n,cmpXY);
	int m = 0;
	for(int i=0;i<n;++i) {
		while(m>1&&cross(cvx[m-1]-cvx[m-2],p[i]-cvx[m-2]) < 0)
			--m;
		cvx[m++] = p[i];
	}
	
	int k = m;
	for(int i=n-2;i>=0;i--) {
		while(m>k&&cross(cvx[m-1]-cvx[m-2],p[i]-cvx[m-2]) < 0)
			--m;
		cvx[m++] = p[i];
	}
	if( n > 1 )
		--m;
	ncvx = m;
}

int main() {
	int T,ics = 0;
	cin >> T;
	while( T-- ) {
		cin >> n;
		for(int i=0;i<n;++i) {
			cin >> p[i].x >> p[i].y;
			p[i].idx = i;
			onConvex[i] = false;
			ans[i] = 99999999;
		}
		ConvexHull();
		for(int i=0;i<ncvx;++i) {
			onConvex[cvx[i].idx] = true;
			ans[cvx[i].idx] = 0;
		}
		npp = 0;
		for(int i=0;i<n;++i) if( !onConvex[p[i].idx] ) {
			pp[npp++] = p[i];
		}
		
		for(int s=0;s<ncvx;++s) {
			base = cvx[s];
			vec lastE = cvx[s] - cvx[(s+ncvx-1)%ncvx];
			sort(pp,pp+npp,cmpByBase);
			for(int d=2;d<ncvx;++d) {
				vec e = cvx[(s+d)%ncvx] - cvx[s];
				for(int g=0;g<npp;++g) {
					if ( cross(lastE,pp[g]-base) >= 0 && cross(pp[g]-base,cvx[(s+d)%ncvx]-pp[g]) >= 0 ) {
						ans[pp[g].idx] = min(ans[pp[g].idx],d-1);
					}
				}
			}
		}
		printf("Case #%d:\n",++ics);
		for(int i=0;i<n;++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}
