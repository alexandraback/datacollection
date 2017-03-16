#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

typedef pair<int, int> ii;

ii table[27];

int main(void) {
	int T;
	int N;
	int sum = 0;
	int i, j, k;

	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d", &N);
		int temp;
		for (j = 1; j <= N; j++) {
			scanf("%d", &temp);
			table[j] = ii(temp, j - 1);
			sum += table[j].first;
		}
		sort(table + 1, table + 1 + N, greater<ii>());

		printf("Case #%d: ", i);

		if (sum % 2 == 1) {
			printf("%c", table[1].second + 'A');
			sum -= 1;
			table[1] = ii(table[1].first - 1, table[1].second);
			if (sum != 0) {
				printf(" ");
			}
		}

		while (sum > 0) {
			sort(table + 1, table + 1 + N, greater<ii>());
			printf("%c", table[1].second + 'A');
			table[1] = ii(table[1].first - 1, table[1].second);
			sort(table + 1, table + 1 + N, greater<ii>());
			printf("%c", table[1].second + 'A');
			table[1] = ii(table[1].first - 1, table[1].second);
			sum -= 2;

			if (sum != 0) {
				printf(" ");
			}
		}

		printf("\n");
	}
}