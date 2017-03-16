#include <cstdio>

int T,N,B;
int mvl[1008];
int main() {
	long long LIM=1000000000;
	LIM*=LIM;
	scanf("%d",&T);
	for(int tn=1;tn<=T;tn++) {
		scanf("%d%d",&B,&N);
		for(int i=0;i<B;i++) scanf("%d",&mvl[i]);
		long long minv=0; long long maxv=LIM;
		while(minv<maxv) {
			long long hf=(minv+maxv+1)/2;
			int used=0;
			for(int i=0;i<B;i++) {
				if(hf/mvl[i]>=N) {
					used=N;
				} else {
					if(hf%mvl[i]) {
						used+=hf/mvl[i]+1;
					} else {
						used+=hf/mvl[i];
					}
					if(used>N) used=N;
				}
			}
			if(used<N) {
				minv=hf;
			} else {
				maxv=hf-1;
			}
		}
		int ttl=0;
		for(int i=0;i<B;i++) {
			if(minv%mvl[i]) {
				ttl+=minv/mvl[i]+1;
			} else {
				ttl+=minv/mvl[i];
			}
		}
		int sol=-1;
		for(int i=0;i<B;i++) {
			if(minv%mvl[i]==0) {
				ttl++;
				if(ttl==N) sol=i+1;
			}
		}
		printf("Case #%d: %d\n",tn,sol);
	}
	return 0;
}
