#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <string>

using namespace std;

int main() {
	int T, R, C, N;
	scanf("%d",&T);
	for (int W=1;W<=T;W++) {
		scanf("%d%d%d", &R, &C, &N);
		int TOT=R*C, top=1<<TOT;
		int best=0x3fffffff;
		for (int i=0;i<top;i++) {
			int cnt=0;
			for (int j=0;j<TOT;j++)
				if (i&(1<<j))
					cnt++;
			if (cnt!=N)
				continue;
			static int g[16][16];
			for (int q=0;q<R;q++)
				for (int j=0;j<C;j++) {
					if (i&(1<<(q*C+j)))
						g[q][j]=1;
					else
						g[q][j]=0;
				}
			/*for (int i=0;i<R;i++,putchar('\n'))
				for (int j=0;j<C;j++)
					printf("%d",g[i][j]);*/
			int unh=0;
			for (int i=0;i<R;i++)
				for (int j=0;j<C;j++) {
					if (!g[i][j])
						continue;
					if (i+1<R && g[i+1][j])
						unh++;
					if (j+1<C && g[i][j+1])
						unh++;
				}
			best=min(best, unh);
		}
		printf("Case #%d: %d\n", W, best);
	}
}

