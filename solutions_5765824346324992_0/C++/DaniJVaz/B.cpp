#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

long long gcd(long long a, long long b) {
	long long t;
	while (b) {
		t = a;
		a = b;
		b = t%b;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a/gcd(a,b)*b;
}


int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		ll B, N;
		scanf("%I64d %I64d", &B, &N);
		
		ll speeds[B], lcmAux[B], times[B];
		for (int i=0; i<B; i++) {
			scanf("%I64d", speeds+i);
			lcmAux[i] = speeds[i];
			times[i] = 0;
		}

		ll p = 1;
		while (p < B) {
			for (int i=0; i+p<B; i += 2*p)
				lcmAux[i] = lcm(lcmAux[i], lcmAux[i+p]);
			p *= 2;
		}

		ll lcmVal = lcmAux[0];
		ll doneInLcm = 0;
		for (int i=0; i<B; i++)
			doneInLcm += lcmVal / speeds[i];

		N %= doneInLcm;
		if (N == 0)
			N += doneInLcm;

		//printf("%I64d\n", lcmVal);

		ll countCut = 0;

		int iMin = 0;
		while (countCut < N) {
			iMin = 0;
			for (int i=1; i<B; i++)
				if (times[i] < times[iMin])
					iMin = i;

			times[iMin] += speeds[iMin];
			//printf ("%d ", iMin);
			countCut++;
		}

		printf("Case #%d: %d\n", iC, iMin + 1);
	}
	return 0;
}