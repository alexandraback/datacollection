#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

int T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an;
int a[20], b[20];

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		printf("Case #%d: ", rr);
		memset(a, 0, sizeof(a));
		for (int i=0; i<2; i++){
			scanf("%d", &m); m--;
			for (int j=0; j<4; j++){
				for (int k=0; k<4; k++){
					scanf("%d", &q);
					if (j == m)
						a[q]++;
				}
			}				
		}
		cnt = 0;
		for (int i=1; i<=16; i++)
			if (a[i] == 2)
				an = i, cnt++;
		if (cnt == 1)
			printf("%d\n", an);
		else if (cnt == 0)
			printf("Volunteer cheated!\n");
		else printf("Bad magician!\n");
	}
	return 0;
}
