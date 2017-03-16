#include <bits/stdc++.h>
using namespace std;

#define ARRAY_LEN(array) (sizeof(array) / sizeof(*array))
#define SIZEOF_MEMBER(type, member) (sizeof(((type *) NULL)->member))

template <typename T> T gcd(T x, T y) { return y == 0 ? x : gcd(y, x % y); }
int ffs(long long x) { return __builtin_ffsll(x); } // Find First Set -- 1 + index of the rightmost 1-bit; 0 if all bits are 0.
int popcount(long long x) { return __builtin_popcountll(x); } // Count the number of 1-bits.

typedef int64_t Num;
//typedef __int128 num;
#define PRINUM PRId64
#define SCANUM SCNd64

bool debug = true;
#define DEBUG_WRAP(...) \
	do { if (debug) { \
			fflush(stdout); \
			fprintf(stderr, "[D] %s:%d:%s: ", __FILE__, __LINE__, __func__); \
			__VA_ARGS__; \
			fflush(stderr); \
		} } while(0)
#define DEBUG(fmt, ...) DEBUG_WRAP(fprintf(stderr, fmt "\n", ##__VA_ARGS__))
#define DUMP(expr) DEBUG_WRAP(cerr << #expr << " = " << (expr) << "\n")

void evacuate(int *ns, int a, int b) {
	char text[3];

	text[0] = 'A' + a;
	ns[a]--;

	if (b >= 0) {
		text[1] = 'A' + b;
		text[2] = '\0';
		ns[b]--;
	} else {
		text[1] = '\0';
	}

	printf(" %s", text);
}

void handle_case(int case_num) {
	int n_parties;
	scanf(" %d", &n_parties);
	int *ns_senators = (int *) alloca(n_parties * sizeof(*ns_senators));
	for (int i_party = 0; i_party < n_parties; i_party++) {
		scanf(" %d", &ns_senators[i_party]);
	}

	while (true) {
		int i_max;
		int max = INT_MIN;
		int n_nonzero = 0;
		for (int i_party = 0; i_party < n_parties; i_party++) {
			if (ns_senators[i_party] > 0)
				n_nonzero++;
			if (ns_senators[i_party] > max) {
				max = ns_senators[i_party];
				i_max = i_party;
			}
		}

		if (n_nonzero >= 3)
			evacuate(ns_senators, i_max, -1);
		else
			break;
	}

	int is_nonzero[2];
	int n_nonzero = 0;
	for (int i_party = 0; i_party < n_parties; i_party++) {
		if (ns_senators[i_party] > 0) {
			is_nonzero[n_nonzero] = i_party;
			n_nonzero++;
		}
	}
	assert(n_nonzero == 2);

	while (ns_senators[is_nonzero[0]] > 0 || ns_senators[is_nonzero[1]] > 0) {
		if (ns_senators[is_nonzero[0]] > ns_senators[is_nonzero[1]]) {
			evacuate(ns_senators, is_nonzero[0], -1);
		} else if (ns_senators[is_nonzero[0]] < ns_senators[is_nonzero[1]]) {
			evacuate(ns_senators, is_nonzero[1], -1);
		} else if (ns_senators[is_nonzero[0]] == ns_senators[is_nonzero[1]]) {
			evacuate(ns_senators, is_nonzero[0], is_nonzero[1]);
		} else {
			assert(false);
		}
	}
}

int main(void) {
	char n_cases_str[64];
	fgets(n_cases_str, sizeof(n_cases_str), stdin);
	int n_cases;
	sscanf(n_cases_str, " %d ", &n_cases);

	for (int case_num = 1; case_num <= n_cases; case_num++) {
		printf("Case #%d:", case_num);
		handle_case(case_num);
		printf("\n");
	}

	return 0;
}
