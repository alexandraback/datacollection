#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f

using namespace std;

const double PI = acos(-1.0);
typedef pair<int, int> pii;
typedef long long ll;

int v[30];
int main (void) {
	int t; scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++) {
		int n; scanf("%d", &n);
		int sumTotal = 0;
		int menor = INT_MAX;
		for (int i = 0; i < n; i++) {
			scanf("%d", v + i);
			sumTotal = 0;
			menor = min (menor, v[i]);
		}
		printf("Case #%d:", cases);
		while (true) {
			int maior = v[0], idx = 0;
			for (int i = 1; i < n; i++) {
				if (v[i] > maior) {
					maior = v[i];
					idx = i;
				}
			}
			if (maior == menor) break;

			v[idx]--;
			printf(" %c", 'A' + idx);
		}
		
		int counter = 0;
		for (int i = 0; i < n; i++) if (v[i] > 0) counter++;
		while (menor > 1) {
			if (counter == 2) {
				int  x = 1;
				for (int i = 0; i < n; i++) {
					if (v[i] > 0) {
						v[i]--;
						if (x) printf(" %c", 'A' + i);
						else printf("%c", 'A' + i);
						x = 0;
					}
				}
				menor--;
				continue ;
			}
			for (int i = 0; i < n; i++) {
				if (v[i] > 0) {
					v[i]--;
					printf(" %c", 'A' + i);
				}
			}
			menor--;
		}

		if (counter == 1) {
			for (int i = 0; i < n; i++) if (v[i] > 0) printf(" %c", i + 'A');
			continue ;
		}

		for (int i = 0; i < n; i++) {
			if (counter == 2) break;
			if (v[i] > 0) {
				counter--;
				printf(" %c", 'A' + i); v[i]--;
			}
		}

		for (int i = 0; i < n; i++) {
			if (v[i] > 0) {
				if (counter == 2)printf(" %c", 'A' + i);
				else printf("%c\n", 'A' + i);
				counter--;
			}
		}
	}
	return 0;
}
