#include <stdio.h>
#include <stdlib.h>

unsigned int
solve_a(unsigned int *mushrooms, size_t size)
{
	unsigned int eaten;
	unsigned int plate;
	unsigned int i;

	eaten = 0;
	plate = 0;

	for(i = 0; i < size; i++) {
		if(mushrooms[i] < plate)
			eaten += plate - mushrooms[i];

		plate = mushrooms[i];
	}

	return eaten;
}

unsigned int
solve_b(unsigned int *mushrooms, size_t size)
{
	unsigned int max;
	unsigned int eaten;
	unsigned int i;

	max   = 0;
	eaten = 0;

	for(i = 1; i < size; i++)
		if(mushrooms[i] < mushrooms[i - 1])
			if(mushrooms[i - 1] - mushrooms[i] > max)
				max = mushrooms[i - 1] - mushrooms[i];
	
	for(i = 0; i < size - 1; i++) {
		if(mushrooms[i] < max)
			eaten += mushrooms[i];
		else
			eaten += max;
	}

	return eaten;
}

int
main(int argc, char* argv[], char* envp[])
{
	unsigned int T;
	unsigned int N;
	unsigned int *m;

	unsigned int i;
	unsigned int j;

	scanf("%u", &T);

	for(i = 0; i < T; i++) {
		fprintf(stderr, "Test %d / %d\n", i + 1, T);
		scanf("%u", &N);

		m = (unsigned int*)malloc(sizeof(unsigned int) * N);
		for(j = 0; j < N; j++)
			scanf("%u", &m[j]);

		printf(
			"Case #%d: %u %u\n",
			i + 1,
			solve_a(m, N),
			solve_b(m, N));
		free(m);
	}

	return EXIT_SUCCESS;
}
