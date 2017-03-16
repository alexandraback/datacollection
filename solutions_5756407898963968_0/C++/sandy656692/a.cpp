#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
	int ttt;
	scanf("%d", &ttt);
	for (int test = 1; test <= ttt; ++test) {
		int row;
		int f[20];
		memset(f, 0, sizeof(f));
		for (int round = 0; round < 2; ++round) {
			scanf("%d", &row);
			for (int i = 1; i <= 4; ++i) {
				int tmp;
				if (i != row) {
					for (int j = 0; j < 4; ++j) scanf("%d", &tmp);
					continue;
				}
				for (int j = 0; j < 4; ++j) {
					scanf("%d", &tmp);
					++f[tmp];
				}
			}
		}
		int ans, sum = 0;
		for (int i = 1; i <= 16; ++i) {
			if (f[i] == 2) {
				++sum;
				ans = i;
			}
		}
		printf("Case #%d: ", test);
		if (sum == 1) printf("%d\n", ans);
		else if (sum > 1) printf("Bad magician!\n");
		else printf("Volunteer cheated!\n");
	}
	return 0;
}