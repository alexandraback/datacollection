#include <stdio.h>
#include <stdlib.h>

unsigned int
gcd(unsigned int a, unsigned int b)
{
	if(b == 0)
		return a;
	
	return gcd(b, a % b);
}

unsigned int
lcm(unsigned int a, unsigned int b)
{
	return (a * b) / gcd(a, b);
}

int
solve(unsigned int *times, size_t size, unsigned int pos)
{
	unsigned int i;
	unsigned int min;
	unsigned int ret;
	unsigned int ppcm;
	unsigned int round;
	unsigned int *line;

	if(size == 1)
		return 1;

	/**
	 * 
	 */

	ret = 0;

	/* liine contains remaining time */
	line = (unsigned int*)malloc(sizeof(unsigned int) * size);

	for(i = 0; i < size; i++)
		line[i] = 0;

	/* Determining lcm */
	ppcm = lcm(times[0], times[1]);

	for(i = 2; i < size; i++)
		ppcm = lcm(ppcm, times[i]);


	round = 0;
	for(i = 0; i < size; i++)
		round += ppcm / times[i];

	pos = pos % round;
	if(pos == 0)
		pos += round;

	while(pos > 0) {
		/* Determining mthe barber that will end first */
		min = line[0];
		for(i = 1; i < size; i++)
			if(line[i] < min)
				min = line[i];

		/* min minutes later... */
		for(i = 0; i < size; i++) {
			line[i] -= min;

			if(line[i] == 0 && pos > 0) {
				line[i] = times[i];
				pos--;

				if(pos == 0)
					ret = i + 1;
			}
		}
	}

	free(line);

	return ret;
}

int
main(int argc, char* argv[], char* envp[])
{
	unsigned int T;
	unsigned int B;
	unsigned int N;
	unsigned int *M;

	unsigned int i;
	unsigned int j;

	scanf("%u", &T);

	for(i = 0; i < T; i++) {
		fprintf(stderr, "Test %d / %d\n", i + 1, T);
		scanf("%u %u", &B, &N);

		M = (unsigned int*)malloc(sizeof(unsigned int) * B);
		for(j = 0; j < B; j++)
			scanf("%u", &M[j]);

		printf("Case #%d: %d\n", i + 1, solve(M, B,  N));
		free(M);
	}

	return EXIT_SUCCESS;
}
