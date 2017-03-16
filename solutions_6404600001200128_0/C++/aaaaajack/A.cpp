#include<cstdio>
#define N 10010
using namespace std;
int main(){
	int n,a[N],i,x,y,r,T,cs;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		x=y=r=0;
		for(i=1;i<n;i++){
			if(a[i]<a[i-1]){
				x+=a[i-1]-a[i];
				if(a[i-1]-a[i]>r) r=a[i-1]-a[i];
			}
		}
		for(i=0;i<n-1;i++){
			if(r>a[i]) y+=a[i];
			else y+=r;
		}
		printf("Case #%d: %d %d\n",cs,x,y);
	}
	return 0;
}