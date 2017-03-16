#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double pi=acos(-1.0);

struct Data{
	double ang;
	int id;
	bool operator < ( const Data &b ) const {
		return ang+1e-8<b.ang || fabs(ang-b.ang)<1e-8 && id<b.id;
	}
};

int n;
int x[3010],y[3010];
Data dd[10010];

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d %d", x+i, y+i);
		printf("Case #%d:\n", T);
		for (int i=0; i<n; ++i){
			int nn=0;
			for (int j=0; j<n; ++j)
				if (i!=j){
					double t=atan2(x[j]-x[i],y[j]-y[i]);
					dd[nn].ang=t; dd[nn].id=j; ++nn;
					dd[nn].ang=t+2*pi; dd[nn].id=j; ++nn;
				}
			sort(dd,dd+nn);
			int ans=0;
			if (n-3>0) ans=n-3;
			int s=0, t=0;
			while (s<n-1){
				while (t<nn && dd[t].ang+1e-8<dd[s].ang+pi) ++t;
				if (t-s-1<ans) ans=t-s-1;
				++s;
			}
			printf("%d\n",ans);
		}
	}
}
