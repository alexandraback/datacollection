#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void)
{
	int t,T;
	scanf("%d\n",&T);
	for (t=1;t<=T;t++){
		long long B, N;
		scanf("%lld %lld\n",&B, &N);
		int k;
		long long M[B];
		long long tRest[B];
		double rate[B];
		double rate_sum=0;
		for (k=0;k<B;k++){
			scanf("%lld ",&M[k]);
			tRest[k]=0;
			rate[k]=1.0/(double)M[k];
			rate_sum+=rate[k];
		}
		double tSd = (N-1-B) / rate_sum;
		long long tS = (tSd>0)?tSd:0;
		long long n_assigned=0;
		for (k=0;k<B;k++){
			n_assigned += tS/M[k];
			tRest[k] = M[k] - (tS%M[k]);
			if (tRest[k]==M[k])tRest[k]=0;
			else n_assigned++;
		}
		//printf("tS=%lld, assigned=%lld\n",tS, n_assigned);
		// n_totall‚ªŠ®—¹
		assert(n_assigned < N);
		int Ans;
		while (1){
			for (k=0;k<B;k++){
				if (tRest[k]==0){
					n_assigned++;
					//fprintf(stderr,"assign %lld@%d,%lld\n",n_assigned, k+1,tS);
					if (n_assigned==N){
						Ans = k+1;
						goto done;
					}
					tRest[k]=M[k];
					//fprintf(stderr,"t[%d]=%lld\n",k,tRest[k]);
				}
			}
			int tadv=-1;
			for (k=0;k<B;k++){
				if (tadv<0 || tadv>tRest[k]){
					tadv = tRest[k];
				}
			}
			//fprintf(stderr,"tadv=%d\n",tadv);
			assert(tadv>0);
			for (k=0;k<B;k++){
				tRest[k]-=tadv;
			}
			tS+=tadv;
		}
done:;
		printf("Case #%d: %d\n",t,Ans);
	}
	return 0;
}
