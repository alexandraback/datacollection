#include <stdio.h>
#define min(a, b)	(a)<(b) ? (a):(b)

const int INF=987654321;
int T, row, col, n, sol, data[16][16];

void bruteForce(int r, int c, int sel) {
	if(r>row) {
		if(sel!=n) return;

		int cnt=0;
		for(int i=1 ; i<=row ; i++) {
			for(int j=1 ; j<=col ; j++) {
				if(!data[i][j]) continue;

				if(data[i-1][j]) cnt++;
				if(data[i][j-1]) cnt++;
			}
		}
		sol=min(sol, cnt);
		return;
	}

	int nextR=r, nextC=c+1;
	if(nextC>col) {
		nextR++;
		nextC=1;
	}

	data[r][c]=1;
	bruteForce(nextR, nextC, sel+1);
	data[r][c]=0;
	bruteForce(nextR, nextC, sel);
}

int main() {
	scanf("%d", &T);
	for(int t=1 ; t<=T ; t++) {
		sol=INF;
		scanf("%d%d%d", &row, &col, &n);
		bruteForce(1, 1, 0);
		printf("Case #%d: %d\n", t, sol);
	}
}