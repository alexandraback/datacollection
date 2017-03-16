#include <stdio.h>
#pragma warning(disable:4996)
FILE *in = fopen("B.in", "r");
FILE *out = fopen("B.out", "w");
bool tab[17][17];
int min1;
void back(int a, int b, int d,int befi,int befj){
	if (d == 0){
		int cnt = 0;
		for(int i = 1; i <= a; i++){
			for (int j = 1; j <= b; j++){
				if (tab[i][j] && tab[i - 1][j]) cnt++;
				if (tab[i][j] && tab[i][j - 1]) cnt++;
			}
		}
		if (min1 > cnt) min1 = cnt;
		return;
	}
	for (int i = befi; i <= a; i++){
		for (int j = 1; j <= b; j++){
			if (!(i == befi && j <= befj)){
				if (!tab[i][j]){
					tab[i][j] = true;
					back(a, b, d - 1, i, j);
					tab[i][j] = false;
				}
			}
		}
	}
}
int main(){
	int n, i, r, c, x;
	fscanf(in, "%d", &n);
	for (i = 1; i <= n; i++){
		min1 = 0x7fffffff;
		fscanf(in, "%d %d %d", &r, &c, &x);
		
		int flag = (r*c) % 2 == 0 ? (r*c) / 2 : (r*c) / 2 + 1;
		if (flag >= x) min1 = 0;
		else 
			back(r, c, x,1,0);
		fprintf(out, "Case #%d: %d\n", i, min1);
	}
	return 0;
}