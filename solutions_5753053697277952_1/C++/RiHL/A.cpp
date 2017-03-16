#include <stdio.h>

#define ABC 26

int n;

char maximum(int *ps)
{
	char m = 0;
	for (char i=1; i<n; i++)
		if (ps[i] > ps[m])
			m = i;

	return m;
}

void vyres(void)
{
	int ps[ABC];
	scanf("%d", &n);
	int rem = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &ps[i]);
		rem += ps[i];
	}

	while (rem > 0){
		char a = maximum(ps);
		printf(" %c", 'A' + a);
		rem--;
		ps[a]--;
		if (rem == 2)
			continue;

		char b = maximum(ps);
		printf("%c", 'A' + b);
		rem--;
		ps[b]--;
	}

	printf("\n");
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		printf("Case #%d:", i + 1);
		vyres();
	}
}
