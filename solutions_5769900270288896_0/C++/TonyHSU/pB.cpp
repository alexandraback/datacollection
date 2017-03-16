#include<cstdio>


int find_ans(int table[16][16], int r, int c, int x, int y, int n) {
	//printf("r= %d, c= %d, x= %d, y= %d, n= %d\n", r, c, x, y, n);
	/*
	printf("table:\n");
	for (int i=0;i<r;i++) {
		for (int j=0;j<c;j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	*/
	int nx, ny, finish= 0;
	if (x+1 < r && y < c) {
		nx = x+1;
		ny = y;
	}
	else if (x+1 == r && y+1 < c) {
		nx = 0;
		ny = y+1;
	}
	else if (x+1 == r && y+1 == c) {
		nx = 0;
		ny = c;
		finish = 1;
	}
	else {
		if (n > 0) return -1;
		//printf("n= %d\n", n);
		int ct = 0;
		/*
		printf("table:\n");
		for (int i=0;i<r;i++) {
			for (int j=0;j<c;j++) {
				printf("%d ", table[i][j]);
			}
			printf("\n");
		}
		*/
		for (int i=0;i<r;i++) {
			for (int j=0;j<c;j++) {
				if (table[i][j] == 0) continue;
				if (i+1<r && table[i+1][j]) ct++;
				if (j+1<c && table[i][j+1]) ct++;
			}
		}
		//printf("ct = %d\n", ct);
		return ct;
	}
	int table1[16][16], table2[16][16];
	for (int i=0;i<r;i++) {
		for (int j=0;j<c;j++) {
			table1[i][j] = table[i][j];
			table2[i][j] = table[i][j];
		}
	}
	table1[x][y] = 1;
	int ans1 = find_ans(table1, r, c, nx, ny, n-1);
	int ans2 = find_ans(table2, r, c, nx, ny, n);
	if (ans1 == -1) return ans2;
	if (ans2 == -1) return ans1;
	return ans1<ans2 ? ans1 : ans2;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int nm=1;nm<=T;nm++) {
		int r, c, n;
		scanf("%d%d%d", &r, &c, &n);
		int table[16][16] = {0};
		printf("Case #%d: %d\n", nm, find_ans(table, r, c, 0, 0, n));
	}
	return 0;
}
