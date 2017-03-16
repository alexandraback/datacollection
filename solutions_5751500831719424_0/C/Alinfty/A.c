#include <stdio.h>
#include <string.h>

int main(){
	int t,T;
	int N;
	int i,j,k,l;
	int tem,ans;
	int min[100];
	char a[100][101];
	int b[100][101];
	char c[100][101];
	
	scanf("%d", &T);
	for(t=1;t<=T;t++){
		scanf("%d", &N);
		for(i=0;i<N;i++){
			scanf("%s", a[i]);
		}
		for(i=0;i<N;i++){
			k=0;
			b[i][0]=0;
			c[i][0]=a[i][0];
			for(j=0;j<101;j++){
				if(a[i][j]==0){
					k++;
					b[i][k]=0;
					c[i][k]=0;
					break;
				}
				if(c[i][k]==a[i][j]){
					b[i][k]++;
				}
				else{
					k++;
					c[i][k]=a[i][j];
					b[i][k]=1;
				}
			}
//			for(j=0;j<k+1;j++){
//				printf("%d", b[i][j]);
//			}
//			printf("\n");
		}
		for(i=0;i<N;i++){
			if(strcmp(c[0],c[i])!=0){
				printf("Case #%d: Fegla Won\n", t);
				break;
			}
		}
		if(i!=N) continue;
		ans=0;
		for(j=0;j<k;j++){
			min[j]=10000;
			for(l=1;l<=100;l++){
				tem=0;
				for(i=0;i<N;i++){
					tem+=b[i][j]-l>0?b[i][j]-l:l-b[i][j];
				}
				if(tem<min[j]){
					min[j]=tem;
				}
			}
			ans+=min[j];
		}
		printf("Case #%d: %d\n", t,ans);
	}
	return 0;
}
