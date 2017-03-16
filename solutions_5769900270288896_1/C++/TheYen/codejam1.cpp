#include <bits/stdc++.h>
using namespace std;
#define beginx {
#define   endx }
long long int netval[10000000];
long long int WORLD, KINFDEWZ, KINFD;

long long int cxc(long long int i);

 int main()
beginx
 freopen("kk.in","r",stdin);
    freopen("kkxxx.out","w",stdout);
	long long int T;
	cin >> T;
	for (long long int P = 1; P <= T; P++)
	beginx
		cin >> WORLD >> KINFDEWZ >> KINFD;

		long long int best = WORLD * KINFDEWZ * KINFD * 100;
		for (long long int i = 1; i < (1 << (WORLD * KINFDEWZ)); i++)
		beginx
			netval[i] = netval[i - (i & -i)] + 1;
			if (netval[i] == KINFD) best = min(best, cxc(i));
		endx
		printf("Case #%lld: %lld\n", P, best);
	endx
endx


long long int cxc(long long int i)
beginx
	long long int data = 0;
	for (long long int r = 0; r < WORLD; r++)

	beginx
		for (long long int c = 0; c < KINFDEWZ; c++)

		beginx
			if (c > 0 and (i & (1 << (r * KINFDEWZ + c))) and (i & (1 << (r * KINFDEWZ + c - 1))))
				data++;

			if (r > 0 and (i & (1 << (r * KINFDEWZ + c))) and (i & (1 << (r * KINFDEWZ + c - KINFDEWZ))))
				data++;
		endx
	endx
	return data;
endx

