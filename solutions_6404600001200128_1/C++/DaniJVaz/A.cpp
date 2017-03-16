#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int N;
		scanf("%d", &N);

		int mushes[N];
		for (int i=0; i<N; i++)
			scanf("%d", mushes + i);

		int meth1 = 0, meth2 = 0, step = 0;
		for (int i=1; i<N; i++) {
			if (mushes[i-1] > mushes[i]) {
				meth1 += mushes[i-1] - mushes[i];
				step = max(step, mushes[i-1]-mushes[i]);
			}
		}

		for (int i=1; i<N; i++) {
			meth2 += min(step, mushes[i-1]);
		}

		printf("Case #%d: %d %d\n", iC, meth1, meth2);
	}
	return 0;
}