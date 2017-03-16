#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x, ans;
int a[4][4], mrk[17];

int main()
{
	FILE *in = fopen("in.txt", "r");
	FILE *out = fopen("out.txt", "w");
	int T;
	fscanf(in, "%d", &T);
	for (int sc=1; sc <= T; sc++) {
		memset(mrk, 0, sizeof(mrk));
		for (int t=0; t < 2; t++) {
			fscanf(in, "%d", &x);
			for (int i=0; i < 4; i++) {
				for (int j=0; j < 4; j++) {
					fscanf(in, "%d", &a[i][j]);
				}
			}
			for (int j=0; j < 4; j++) {
				mrk[a[x-1][j]]++;
			}
		}
		ans = -1;
		for (int i=1; i <= 16; i++) {
			if (mrk[i] == 2) {
				if (ans == -1) ans = i;
				else { ans = 0; break; }
			}
		}
		fprintf(out, "Case #%d: ", sc);
		if (ans == -1) fprintf(out, "Volunteer cheated!\n");
		else if (ans == 0) fprintf(out, "Bad magician!\n");
		else fprintf(out, "%d\n", ans);
	}
	return 0;
}
