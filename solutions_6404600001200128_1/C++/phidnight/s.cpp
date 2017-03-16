#include <cstdio>

int T,N;
int mvl[1008];
int main() {
	scanf("%d",&T);
	for(int tn=1;tn<=T;tn++) {
		scanf("%d",&N);
		for(int i=0;i<N;i++) scanf("%d",&mvl[i]);
		long long sumx=0;
		int min_ratio=0;
		for(int i=1;i<N;i++) {
			if(mvl[i]<mvl[i-1]) {
				sumx+=mvl[i-1]-mvl[i];
				if(min_ratio<mvl[i-1]-mvl[i]) min_ratio=mvl[i-1]-mvl[i];
			}
		}
		long long sumy=0;
		for(int i=1;i<N;i++) {
			if(mvl[i-1]>=min_ratio) {
				sumy+=min_ratio;
			} else {
				sumy+=mvl[i-1];
			}
		}
		printf("Case #%d: %lld %lld\n",tn,sumx,sumy);
	}
	return 0;
}
