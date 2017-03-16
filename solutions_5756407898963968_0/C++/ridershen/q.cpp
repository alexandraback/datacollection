#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>


int T;
int f;
int a[4][4];
int s;
int b[4][4];

int solve() {
	int count = 0;
	int v;
	for (int c=0; c < 4; ++c)
	{
		for (int d = 0; d < 4; ++d)
		{
			if (a[f-1][c] == b[s-1][d]) {
				++count;
				v = a[f-1][c];
			}
		}
	}
	if(count == 1) {
		return v;
	}else if (count > 1) {
		return -1;
	}else {
		return -2;
	}
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		scanf("%d", &f);
		for (int c = 0; c < 4; ++c)
		{
			for (int d = 0; d < 4; ++d)
			{
				scanf("%d", &a[c][d]);
			}
		}
		scanf("%d", &s);
		for (int c = 0; c < 4; ++c)
		{
			for (int d = 0; d < 4; ++d)
			{
				scanf("%d", &b[c][d]);
			}
		}
		int r = solve();
		printf("Case #%d: ", i+1);
		if (r > 0) {
			printf("%d\n", r);
		} else if (r == -1) {
			printf("Bad magician!\n");
		} else {
			printf("Volunteer cheated!\n");
		}
	}
	return 0;
}