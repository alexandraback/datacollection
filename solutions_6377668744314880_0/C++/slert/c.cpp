#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct item{
	int x, y;
	double a;
	void q(item &r){
		if(x==r.x&&y==r.y)a=-10;
		else a=atan2(y-r.y, x-r.x);

	}
	bool operator < (const item &r) const {
		if(a!=r.a)return a<r.a;
		if(x!=r.x)return x<r.x;
		return y<r.y;
	}
};
item a[3010];
item b[3010];

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d%d",&a[i].x, &a[i].y);
			b[i] = a[i];
		}
		printf("Case #%d:\n", ti);
		if(n<=3){
			for(int i = 0; i < n; i++)
				printf("0\n");
			continue;
		}
		for(int i = 0; i < n; i++){
			int mn=n;
			for(int j = 0; j < n; j++){
				a[j].q(b[i]);
			}
			sort(a,a+n);
			for(int j=1,k=2; j<n; j++){
				while(true){
					double x=a[k].a-a[j].a;
					if(x<0)x+=M_PI+M_PI;
					if(x>M_PI)break;

					k++;
					if(k==n)k=1;
					if(k==j)break;
				}
				int m = j-k;
				if(m<0)m+=n-1;
				if(mn>m)mn=m;
			}
			printf("%d\n", mn);
		}
		
	}
	return 0;
}