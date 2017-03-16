#include <stdio.h>

double min(double a, double b) { return a<b?a:b; }


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int Test;
	scanf("%d",&Test);
	for (int test=1; test<=Test; test++) {
		int n,M[1010] = {0};
		scanf("%d",&n);
		for (int i=1; i<=n; i++) {
			scanf("%d", M+i);
		}

		int y=0,z=0;
		for (int i=2; i<=n; i++) {
			if (M[i-1] > M[i]) {
				y += M[i-1]-M[i];
			}
		}

		double rate=0;
		for (int i=2; i<=n; i++) {
			if (rate < (M[i-1]-M[i])/10.0) {
				rate = (M[i-1]-M[i])/10.0;
			}
		}
		for (int i=1; i<n; i++) {
			if ((double)M[i] > rate*10) {
				z += (rate*10);
			}
			else {
				z += M[i];
			}
		}

		printf("Case #%d: %d %d\n",test, y,z);

	}


}

