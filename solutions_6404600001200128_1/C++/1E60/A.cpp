#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void)
{
	int t,T;
	scanf("%d\n",&T);
	for (t=1;t<=T;t++){
		int N;
		scanf("%d\n",&N);
		int i;
		int m[N];
		for (i=0;i<N;i++){
			scanf("%d ",&m[i]);
		}
		int A1=0;
		for (i=1;i<N;i++){
			int d=m[i]-m[i-1];
			if (d<0){
				A1+= (-d);
			}
		}
		int A2=0;
		int rate_m_10=0;
		for (i=1;i<N;i++){
			int d=m[i]-m[i-1];
			if (rate_m_10<(-d)){
				rate_m_10=(-d);
			}
		}
		for (i=0;i<N-1;i++){
			int d1,d2;
			d1 = rate_m_10;
			d2 = m[i];
			A2+=(d1<d2)?d1:d2;
		}
		printf("Case #%d: %d %d\n",t,A1,A2);
	}
	return 0;
}
