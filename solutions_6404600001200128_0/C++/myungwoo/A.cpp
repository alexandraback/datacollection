#include <bits/stdc++.h>
using namespace std;

#define MAXN 1004

int T, N, A[MAXN];

int main()
{
	int ts = 0;
	for (scanf("%d", &T);T--;){
		printf("Case #%d: ", ++ts);
		scanf("%d", &N);
		for (int i=1;i<=N;i++) scanf("%d", A+i);
		int ans1 = 0, ans2 = 0, maxdiff = 0;
		for (int i=1;i<N;i++) if (A[i] > A[i+1]) ans1 += A[i]-A[i+1], maxdiff = max(maxdiff, A[i]-A[i+1]);
		for (int i=1;i<N;i++) ans2 += min(A[i], maxdiff);
		printf("%d %d\n", ans1, ans2);
	}
}
