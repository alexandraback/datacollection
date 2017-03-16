#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

char retezce[1000][1000];
char znaky[1000];
int delky[1000][1000];

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", retezce[i]);
		}

		int P = 0;
		for (int i = 0; retezce[0][i]; i++) {
			char znak = retezce[0][i];
			if (P == 0 || znaky[P-1] != znak) {
				znaky[P++] = znak;
			}
		}
		znaky[P] = 0;

		for (int i = 0; i < N; i++) {
			int p = 0;
			delky[i][0] = 0;
			for (int j = 0; retezce[i][j]; j++) {
				char znak = retezce[i][j];
				if (j != 0 && znaky[p] != znak) {
					p++;
					delky[i][p] = 0;
				}
				if (znaky[p] != znak) {
					printf("Case #%d: Fegla Won\n", t);
					goto dalsi_pripad;
				}
				delky[i][p]++;
			}
			if (znaky[p + 1]) {
				printf("Case #%d: Fegla Won\n", t);
				goto dalsi_pripad;
			}
		}

		{
			int vysledek = 0;
			for (int i = 0; i < P; i++) {
				int nejmensi = delky[0][i], nejvetsi = delky[0][i];
				for (int j = 1; j < N; j++) {
					nejmensi = min(nejmensi, delky[j][i]);
					nejvetsi = max(nejvetsi, delky[j][i]);
				}
				int nejmene_kroku = 1000000;
				for (int j = nejmensi; j <= nejvetsi; j++) {
					int kroku = 0;
					for (int k = 0; k < N; k++) {
						kroku += abs(delky[k][i] - j);
					}
					nejmene_kroku = min(nejmene_kroku, kroku);
				}
				vysledek += nejmene_kroku;
			}
			printf("Case #%d: %d\n", t, vysledek);
		}

dalsi_pripad:
			continue;
	}
	return 0;
}
