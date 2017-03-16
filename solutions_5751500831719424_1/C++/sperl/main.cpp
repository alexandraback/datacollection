#include <stdio.h>

#include <vector>
#include <list>
#include <limits.h>
#include <string.h>
#include <math.h>

#define ll long long

#define N_MAX 102

int N;

int numbers[N_MAX][N_MAX];

int abs(int i) {
	if (i < 0) 
		return -i;
	return i;
}

void solve() {

	scanf("%d", &N);
	
	char str[N_MAX];
	
	for (int i = 0; i < N_MAX; i++) {
		for (int j = 0; j < N_MAX; j++) {
			numbers[i][j] = 0;
		}
	}
	
	std::vector<char> chars[N_MAX];
	int idx[N_MAX];
	
	// read
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		
		char last = -1;
		idx[i] = -1;
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] != last) {
				//printf("str[j] = %c\n", str[j]);
				idx[i]++;
				chars[i].push_back(str[j]);
				last = str[j];
			}
			numbers[i][idx[i]]++;
		}
		//printf("\n");
	}
	
	// check
	for (int i = 1; i < N; i++) {
		if (idx[i] != idx[0]) {
			printf("Fegla Won");
			return;
		}
		for (int j = 0; j <= idx[i]; j++) {
			if (chars[i][j] != chars[0][j]) {
				printf("Fegla Won");
				return;
			}
		}
	}
	
	// solve
	int amount = 0;
	for (int i = 0; i <= idx[0]; i++) {
		int min = INT_MAX;
		for (int t = 1; t <= 101; t++) {
			int asdf = 0;
			for (int j = 0; j < N; j++) {
				asdf += abs(numbers[j][i]-t);
			}
			if (asdf < min) {
				min = asdf;
			}
		}
		amount += min;
	}
	
	printf("%d", amount);
}


int main() {
	
	int T = 0;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)  {
		printf("Case #%d: ", t);
		solve();
		printf("\n");
	}
}


