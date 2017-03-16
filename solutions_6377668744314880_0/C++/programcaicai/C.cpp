#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
struct Point{
	LL x,y;

	Point operator-(const Point &b){
		Point ret;
		ret.x = x-b.x;
		ret.y = y-b.y;
		return ret;
	}

};


LL cross(Point a,Point b){
	return a.x*b.y - b.x*a.y;
}


int T;
int n;
Point ps[10010];

int main() {

	scanf("%d",&T);

	for(int cas=1;cas<=T;cas++){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lld %lld", &ps[i].x,&ps[i].y);
		printf("Case #%d:\n",cas);

		for(int i=0;i<n;i++){

			int ans = 0;
			for(int j=0;j<n;j++) if(j!=i){
				Point v = ps[j]-ps[i];
				int pos=0,neg=0;
				int eq = 0;
				for(int k=0;k<n;k++)if(k!=i && k!=j){
					Point v2 = ps[k]-ps[i];
					LL c = cross(v,v2);
					if(c>0) pos+=1;
					else if(c<0) neg+=1;
					else eq+=1;
				}
				ans = max(ans,pos+eq);
				ans = max(ans,neg+eq);
			}
			printf("%d\n",max(n-ans-2,0));
		}

	}





	return 0;
}
