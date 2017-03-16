#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define N 3005
int n,x[N],y[N];

long long cross(int i,int j,int k) {
	int a1,a2,a3,a4;
	a1=x[j]-x[i];
	a2=y[j]-y[i];
	a3=x[k]-x[i];
	a4=y[k]-y[i];
	return (long long)a1*a4-(long long)a2*a3;
}

void work() {
	int i,j,k,ans,temp;
	FOR(i,1,n) {
		if(n<=3){
			printf("%d\n",0);
			continue;
		}
		ans=n;
		FOR(j,1,n) {
			if(i!=j) {
				temp=0;
				FOR(k,1,n) {
					if(i!=k && j!=k) {
						if(cross(j,i,k)<0)
							temp++;
					}
				}
				ans=min(ans,min(temp,n-temp));
			}			
		}
		printf("%d\n",ans);
	}
}

void init() {
	int i;
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d%d",x+i,y+i);
	}
}

int main() {
	int i,T;
	scanf("%d",&T);
	FOR(i,1,T) {
		init();
		printf("Case #%d:\n", i);
		work();
	}
}