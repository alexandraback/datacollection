#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
int a[30];

int main() {
	int o, cas = 0;
	scanf("%d", &o);
	while (o--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		printf("Case #%d:", ++cas);
		while (true) {
			int x = 0, y = 0, j, k;
			for (int i = 1; i <= n; i++)
				if (a[i] > x) {
					x = a[i];
					j = i;
				}
			if (x == 0) break;
			a[j] --;
			int num = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] > y) {
					y = a[i];
					k = i;
				}
				if (a[i]) num++;
			}
			if (num == 0) break;
			printf(" %c", j + 'A' - 1);
			if (!(y == 1 && num == 2)) {
				a[k]--;
				printf("%c", k + 'A' - 1);
			}
		}
		printf("\n");
	}
}
