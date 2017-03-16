#include <cstdio>

int T, t;

int n;
int A[30];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int i;
	int max1, maxp1, max2, maxp2;
	int sum;

	scanf("%d", &T);
	for(t=1; t<=T; t++){
		scanf("%d", &n);

		for(i=1; i<=n; i++) scanf("%d", &A[i]);

		sum = 0;
		for(i=1; i<=n; i++) sum += A[i];
		
		printf("Case #%d: ", t);
		for(;;){
			max1 = 0;
			for(i=1; i<=n; i++){
				if ( max1 < A[i] ){
					max1 = A[i];
					maxp1 = i;
				}
			} A[maxp1] --, sum --;

			max2 = 0;
			for(i=1; i<=n; i++){
				if ( max2 < A[i] ){
					max2 = A[i];
					maxp2 = i;
				}
			}

			if ( max2 * 2 > sum ){
				A[maxp2] --;
				sum --;

				printf("%c", maxp2+'A'-1);
			} printf("%c ", maxp1+'A'-1);

			if ( sum <= 0 ) break;
		} printf("\n");
	}

	return 0;
}