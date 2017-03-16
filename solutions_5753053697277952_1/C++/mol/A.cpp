#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int tt=0; tt<T; tt++){
		int N;
		scanf("%d",&N);
		int p[N],cnt=0;
		for(int i=0; i<N; i++){
			scanf("%d",&p[i]);
			cnt += p[i];
		}
		printf("Case #%d: ",tt+1);
		int maxp=0,max2p=0,argmax,argmax2;
		for(int i=0; i<N; i++)
			if(p[i] > maxp){
				max2p = maxp;
				argmax2 = argmax;
				maxp = p[i];
				argmax = i;
			}else if(p[i] >= max2p){
				max2p = p[i];
				argmax2 = i;
			}
		for(int i=0; i<maxp-max2p; i++)
			printf("%c ",'A'+argmax);
		for(int i=0; i<N; i++)
			if(i != argmax && i != argmax2)
				for(int j=0; j<p[i]; j++)
					printf("%c ",'A'+i);
		for(int i=0; i<max2p; i++)
			printf("%c%c ",'A'+argmax,'A'+argmax2);
		printf("\n");
	}
	return 0;
}
