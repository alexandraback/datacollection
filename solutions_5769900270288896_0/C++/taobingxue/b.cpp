#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T, R, C, N;
int main(int argc, char** argv) {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &T);
	
	int count1[66000];
	for (int i=0; i<65536; i++) {
		int j=i, s=0;
		for (; j>0; j/=2)
			if (j & 1) s++;
		count1[i] = s;
	}
	
	bool f[18][18];
	for (int times=1; times<=T; times ++) {
		printf("Case #%d: ", times);
		scanf("%d%d%d", &R, &C, &N);
		if (N <= (R*C+1)/2) {
			printf("0\n");
			continue;
		}
		
		int len = R*C, ans = len + len;
		for (int i=0; i< ( 1 << len); i++)
			if (count1[i] == N) {
				for (int ii=0; ii<R; ii++)
					for (int jj=0; jj<C; jj++)
						if (i & (1 << (ii*C+jj))) f[ii][jj] = true;
						else f[ii][jj] =false;
				int ss = 0;
				for (int ii=0; ii<R; ii++)
					for (int jj=0; jj<C-1; jj++) if (f[ii][jj] & f[ii][jj+1]) ss += 1;
				for (int ii=0; ii<R-1; ii++)
					for (int jj=0; jj<C; jj++) if (f[ii][jj] & f[ii+1][jj]) ss += 1;
				if (ss < ans) ans = ss;
			}
		printf("%d\n", ans);
	}
	return 0;
}

