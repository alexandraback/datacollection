
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "ordena.cpp"

int main()
{
	FILE *In, *Out;

	long i, j, k;
	long T, N;
	int n;

	long total;

	long numero[26];

	long Max, iMax;

	//In = fopen("prueba.in", "r");
	In = fopen("A-small-attempt0.in", "r");
	//In = fopen("A-large.in", "r");

	//Out = fopen("prueba.out", "w");
	Out = fopen("A-small-attempt0.out", "w");
	//Out = fopen("A-large.out", "w");

	fscanf(In, "%d", &T);
	
	for (i = 0; i < T; i++)
	{
		total = 0;

		fscanf(In, "%d", &N);


		fprintf(Out, "Case #%d:", i + 1);

		for (j = 0; j < N; j++)
		{
			fscanf(In, "%d", &numero[j]);
			total += numero[j];
		}

		while (total)
		{
			Max = 0;

			for (j = 0; j < N; j++)
			{
				if (numero[j] > Max)
				{
					Max = numero[j];
					iMax = j;
				}
			}

			total--;
			numero[iMax]--;

			fprintf(Out, " %c", iMax + 65);

			if (total == 0)
				break;

			if (total == 2)
				continue;

			Max = 0;

			for (j = 0; j < N; j++)
			{
				if (numero[j] > Max)
				{
					Max = numero[j];
					iMax = j;
				}
			}

			total--;
			numero[iMax]--;

			fprintf(Out, "%c", iMax + 65);

			if (total == 0)
				break;

		}

		fprintf(Out, "\n");
	}


	fclose(In);
	fclose(Out);

    return 0;
}
