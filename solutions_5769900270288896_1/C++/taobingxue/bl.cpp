#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T, R, C, N;
int main(int argc, char** argv) {
	freopen("bl.in", "r", stdin);
	freopen("bl.out", "w", stdout);
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
		if (len <= 16) {
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
					if (ss < ans) {
						ans = ss;
					}
				}
			printf("%d\n", ans);
		} else {
			int ans1 = 0;
			int res = N - (R*C+1)/2;
			int onedge = R + C -2;
			int a[5], b[5];
			if (R&C&1) {
				a[0] = onedge;
				b[0] = 3;
				a[1] = R*C;
				b[1] = 4;
			} else {
				a[0] = 2;
				b[0] = 2;
				a[1] = onedge-2;
				b[1] = 3;
				a[2] = R*C;
				b[2] = 4;
			}
			for (int i=0; i<3; i++) {
				if (res <= a[i]) {
					ans1 += res * b[i];
					break;
				} else {
					ans1 += a[i] * b[i];
					res -= a[i];
				}
			}
			
			if (R&C&1) {
				int ans2 = 0;
				int res = N - R*C/2;
				int onedge = R + C -2;
				int a[5], b[5];
				if (R&C&1) {
					a[0] = 4;
					b[0] = 2;
					a[1] = onedge-4;
					b[1] = 3;
					a[2] = R*C;
					b[2] = 4;
				} else {
					a[0] = 2;
					b[0] = 2;
					a[1] = onedge-2;
					b[1] = 3;
					a[2] = R*C;
					b[2] = 4;
				}
				for (int i=0; i<3; i++) {
					if (res <= a[i]) {
						ans2 += res * b[i];
						break;
					} else {
						ans2 += a[i] * b[i];
						res -= a[i];
					}
				}
				if (ans1 > ans2) ans1 = ans2;
			}
			printf("%d\n", ans1);
		//	if (ans != ans1) printf("QAQ");
		}
	}
	return 0;
}

