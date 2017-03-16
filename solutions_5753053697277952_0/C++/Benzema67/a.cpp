#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
int a[30];

void find(int &max_1, int &max_2, int &id_1, int &id_2, int &sum) {
	sum = 0;
	max_1 = -1;
	max_2 = -1;
	for (int p = 0; p < n; p++) {
		sum += a[p];
		if (a[p] > max_1) {
			max_2 = max_1;
			id_2 = id_1;
			max_1 = a[p];
			id_1 = p;
		}
		else if (a[p] > max_2) {
			max_2 = a[p];
			id_2 = p;
		}
	}
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("Case #%d:", t + 1);
		while(1) {
			int max_1 = -1, max_2 = -1;
			int id_1, id_2;
			int sum = 0;
			find(max_1, max_2, id_1, id_2, sum);
			if (max_1 == 0 && max_2 == 0) {
				printf("\n");
				break;
			}
			else {
				printf(" %c", 'A' + id_1);
				a[id_1]--;
				//printf("----a[%d] = %d\n", id_1, a[id_1]);
				sum--;
				find(max_1, max_2, id_1, id_2, sum);
				if (sum == 1 || max(max_2, max_1 - 1) / ((double)sum - 1) <= 0.5) {
					printf("%c", 'A' + id_1);
					a[id_1]--;
					//printf("----a[%d] = %d\n", id_1, a[id_1]);
				}
			}
		}
	}
}