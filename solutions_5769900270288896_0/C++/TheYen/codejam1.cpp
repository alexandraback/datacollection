#include <bits/stdc++.h>
using namespace std;
#define beginx {
#define   endx }
int netval[10000000];
int WORLD, KINFDEWZ, KINFD;

int cxc(int i);

int main()
beginx
 freopen("kk.in","r",stdin);
    freopen("kk1.out","w",stdout);
	int T;
	cin >> T;
	for (int P = 1; P <= T; P++)
	beginx
		cin >> WORLD >> KINFDEWZ >> KINFD;

		int best = WORLD * KINFDEWZ * KINFD * 100;
		for (int i = 1; i < (1 << (WORLD * KINFDEWZ)); i++)
		beginx
			netval[i] = netval[i - (i & -i)] + 1;
			if (netval[i] == KINFD) best = min(best, cxc(i));
		endx
		printf("Case #%d: %d\n", P, best);
	endx
endx


int cxc(int i)
beginx
	int data = 0;
	for (int r = 0; r < WORLD; r++)

	beginx
		for (int c = 0; c < KINFDEWZ; c++)

		beginx
			if (c > 0 and (i & (1 << (r * KINFDEWZ + c))) and (i & (1 << (r * KINFDEWZ + c - 1))))
				data++;

			if (r > 0 and (i & (1 << (r * KINFDEWZ + c))) and (i & (1 << (r * KINFDEWZ + c - KINFDEWZ))))
				data++;
		endx
	endx
	return data;
endx

