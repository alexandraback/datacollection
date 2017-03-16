#include <cstdio>
#include <algorithm>
using namespace std;

bool check[16];

int main(void) {
	int testNum;

	scanf("%d", &testNum);
	for (int testCase = 0; testCase < testNum; testCase++) {
		int row1, row2;

		for (int i = 0; i < 16; i++)
			check[i] = 0;

		scanf("%d", &row1);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int cardIdx;
				scanf("%d", &cardIdx);
				if (row1 - 1 == i) {
					check[cardIdx - 1] = true;
				}
			}
		}

		scanf("%d", &row2);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int cardIdx;
				scanf("%d", &cardIdx);
				if (row2 - 1 != i) {
					if (check[cardIdx - 1]) {
						check[cardIdx - 1] = false;
					}
				}
			}
		}

		int cnt = 0, cardIdx;
		for (int i = 0; i < 16; i++) {
			if (check[i]) {
				cnt++;
				cardIdx = i + 1;
			}
		}

		if (cnt == 1) {
			printf("Case #%d: %d\n", testCase + 1, cardIdx);
		} else if (cnt == 0) {
			printf("Case #%d: Volunteer cheated!\n", testCase + 1);
		} else {
			printf("Case #%d: Bad magician!\n", testCase + 1);
		}
	}
	return 0;
}
