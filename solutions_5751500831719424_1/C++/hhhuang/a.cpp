#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char common[120];
char data[120][120];

void ministr(char *in, char *out) {
	int i;
	for (i = 0; i < strlen(in); ++i) {
		if (i == 0 || in[i] != in[i - 1]) {
			*out = in[i];
			out++;
		}
	}
	*out = 0;
}

int cmp(const void *a, const void *b) {
	return *((int *)a) - *((int *)b);
}

int abs(int a) {
	if (a >= 0)
		return a;
	return -a;
}

int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

int count(char *str1, char *str2) {
	int map[120][120];
	memset(map, 0, sizeof(map));
	map[0][0] = 0;
	//puts(str1);
	//puts(str2);
	for (int i = 0; i <= strlen(str1); ++i)
		map[i][0] = i;
	for (int j = 0; j <= strlen(str2); ++j)
		map[0][j] = j;
		
	for (int i = 1; i <= strlen(str1); ++i) {
		for (int j = 1; j <= strlen(str2); ++j) {
			if (str1[i - 1] == str2[j - 1])
				map[i][j] = map[i - 1][j - 1];
			else 
				map[i][j] = min(map[i][j - 1], map[i - 1][j]) + 1;
		//	printf("%d ", map[i][j]);
		}
		//printf("\n");
	}
	return map[strlen(str1)][strlen(str2)];
}

void run() {
	int n;
	int i, j;
	scanf("%d", &n);
	char mini[120];
	int possible = 1;
	int strlens[120];
	
	for (i = 0; i < n; ++i) {
		scanf("%s", data[i]);
		ministr(data[i], mini);
		if (i == 0)
			strcpy(common, mini);
		else if (strcmp(common, mini) != 0) {
			possible = 0;
		}
	}
	if (possible == 0) {
		puts("Fegla Won");
		return;
	}
	//printf("\n%s\n", common);
	
	int pointers[120];
	int repeats[120];
	memset(pointers, 0, sizeof(pointers));
	int ans = 0;
	for (int i = 0; i < strlen(common); ++i) {
		//printf("%c\n", common[i]);
		for (int j = 0; j < n; ++j) {
			repeats[j] = 0;
			while (data[j][pointers[j]] == common[i]) {
				pointers[j]++;
				repeats[j]++;
			}			
		}	
		qsort(repeats, n, sizeof(repeats[0]), cmp);
		int sum1 = 0, sum2 = 0;
		for (int j = 0; j < n; ++j) {
			//printf("%d: %d ", j, repeats[j]);
			sum1 += abs(repeats[j] - repeats[n / 2]);
			sum2 += abs(repeats[j] - repeats[(n - 1) / 2]);
		}
		//printf("\n");
		ans += min(sum1, sum2);
	}
	printf("%d\n", ans);
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d: ", t);
        run();
    }
    return 0;
}

