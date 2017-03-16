#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int cnt[20], map[5][5];

int main() {
	freopen("A-small-attempt11.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for(; test--; ) {
		static int testCount = 0;
		printf("Case #%d: ", ++testCount);
		fill(cnt + 1, cnt + 17, 0);
		for(int times = 0; times < 2; times++) {
			int row;
			scanf("%d", &row);
			for(int i = 1; i <= 4; i++)
				for(int j = 1; j <= 4; j++) {
					scanf("%d", &map[i][j]);
					if (i == row) {
						cnt[map[i][j]]++;
					}
				}
		}
		
		int res = -1;
		for(int i = 1; i <= 16; i++) {
			if (cnt[i] == 2) {
				if (res != -1) {
					res = 0;
					break;
				}
				res = i;
			}
		}
		if (res == -1) {
			printf("Volunteer cheated!\n");
		} else if (res == 0) {
			printf("Bad magician!\n");
		} else {
			printf("%d\n", res);
		}
	}
	return 0;
} 
