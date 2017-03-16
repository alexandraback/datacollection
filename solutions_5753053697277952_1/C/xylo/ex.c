#include <stdio.h>
#include <string.h>

void print_n_times(int n, char c) {
	for (int i = 0; i < n; ++i)
		printf("%c", c);
}

void solve_testcase(int tc) {
	int n_parties = 0;
	int left[26];
	char *s = "";
	scanf("%d", &n_parties);
	for (int i = 0; i < n_parties; ++i) {
		scanf("%d", &(left[i]));
	}

	printf("Case #%d: ", tc);

	if (n_parties == 2) {
		while (1) {
			if ((left[0]+left[1]) == 0) {
				break;
			} else if (left[0] > left[1]) {
				printf("%sA", s); s = " ";
				left[0]--;
			} else if (left[0] < left[1]) {
				printf("%sB", s); s = " ";
				left[1]--;
			} else {
				printf("%sAB", s); s = " ";
				left[0]--;
				left[1]--;
			}
		}
	} else {
		while (1) {
			int max_party = 0;
			int max_senators = 0;
			int n_parties_left = 0;
			for (int i = 0; i < n_parties; ++i) {
				if (left[i] > 0)
					n_parties_left++;
				if (left[i] > max_senators) {
					max_party = i;
					max_senators = left[i];
				}
			}
			if ((max_senators == 1) && (n_parties_left == 2)) {
				printf("%s", s);
				for (int i = 0; i < n_parties; ++i) {
					if (left[i] > 0)
						printf("%c", 'A'+i);
				}
				break;
			}
			if (max_senators == 0)
				break;
			left[max_party]--;
			printf("%s%c", s, 'A'+max_party);
			s = " ";
		}
	}

	printf("\n");
}

int main(void) {
	int n_cases;
	scanf("%d", &n_cases);
	for (int i = 0; i < n_cases; ++i) {
		solve_testcase(i+1);
	}
	return 0;
}
