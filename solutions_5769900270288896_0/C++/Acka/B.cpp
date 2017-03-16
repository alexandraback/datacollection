#include <stdio.h>

int H[4] = { 1, 0, -1, 0 }, W[4] = { 0, 1, 0, -1 };
int r, c, n, min;
bool isExist[100001];

void solve(int h, int w, int score, int smile){
	if (score >= min) return;
	if (smile == n){
		min = score; return;
	}

	int remain = (r - h - 1) * c + (c - w - 1) + 1;
	if (smile + remain < n) return;

	for (int i = h; i < r; i++)
		for (int j = (i == h ? w : 0); j < c; j++){
			int add = 0;
			for (int k = 0; k < 4; k++){
				int chkH = i + H[k], chkW = j + W[k];
				if (chkH < 0 || chkW < 0 || chkH >= r || chkW >= c) continue;
				if (isExist[chkH * c + chkW]) add++;
			}

			isExist[i * c + j] = true;
			solve(i, j + 1, score + add, smile + 1);
			isExist[i * c + j] = false;
			solve(i, j + 1, score, smile);
		}
}

int main()
{
	int tc, step = 0; scanf("%d", &tc);
	FILE* fout = fopen("B.txt", "w");
	while (step++ < tc){
		for (int i = 0; i < 100001; i++) isExist[i] = false;

		scanf("%d %d %d", &r, &c, &n);
		if (n == 0) min = 0;
		else{
			min = r * (c - 1) + c * (r - 1);
			if (n != r * c) solve(0, 0, 0, 0);
		}
		fprintf(fout, "Case #%d: %d\n", step, min);
	}
	return 0;
}