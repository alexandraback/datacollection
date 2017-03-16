#include <cstdio>

int i,t,T,n,y,z,x;

int main(){
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		x=y=z=0;
		scanf("%d",&n);
		int m[n];
		for(i=0;i<n;i++){
			scanf("%d",&m[i]);
			if(i&&m[i]<m[i-1]){
				y+=m[i-1]-m[i];
				if(m[i-1]-m[i]>x){
					x=m[i-1]-m[i];
				}
			}
		}
		for(i=0;i<n-1;i++){
			z+=m[i]>x?x:m[i];
		}
		printf("Case #%d: %d %d\n",t,y,z);
	}
	return 0;
}
