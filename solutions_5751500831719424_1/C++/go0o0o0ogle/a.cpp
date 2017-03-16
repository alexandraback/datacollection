#include <stdio.h>

struct node {
	char ch;
	int count;
};

char str[100][105];
node data[100][105];
int N;

int abs(int t)
{
	return t > 0 ? t : -t;
}

int calc()
{
	int i;
	for (i = 0; i < N; i++) {
		char last = -1;
		int index = -1;
		char *p = str[i];
		for (;;) {
			char ch = *p;
			p++;
			if (ch != last) {
				index++;
				last = ch;
				data[i][index].ch = ch;
				data[i][index].count = 0;
			}
			data[i][index].count++;
			if (ch == 0) {
				break;
			}
		}
	}
	int ret = 0;
	int index = 0;
	for (;;) {
		char ch = data[0][index].ch;
		for (i = 1; i < N; i++) {
			if (data[i][index].ch != ch) {
				return -1;
			}
		}
		if (ch == 0) {
			break;
		}
		int min = -1;
		for (i = 0; i < N; i++) {
			int j;
			int count = data[i][index].count;
			int t = 0;
			for (j = 0; j < N; j++) {
				t += abs(count - data[j][index].count);
			}
			if (min == -1 || min > t) {
				min = t;
			}
		}
		ret += min;
		index++;
	}
	return ret;
}

int main()
{
	int cs, k;
	scanf("%d", &cs);
	for (k = 0; k < cs; k++) {
		scanf("%d", &N);
		int i;
		for (i = 0; i < N; i++) {
			scanf("%s", str[i]);
		}
		int min = calc();
		if (min < 0) {
			printf("Case #%d: Fegla Won\n", k + 1);
		}
		else {
			printf("Case #%d: %d\n", k + 1, min);
		}
	}
	return 0;
}