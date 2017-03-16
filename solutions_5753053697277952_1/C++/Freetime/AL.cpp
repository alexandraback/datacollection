#include <stdio.h>

int main()
{
	FILE *fpw, *fpr;
	fpw = fopen("AL_output.txt", "w");
	fpr = fopen("A-large.in", "r");

	int ii, test, i, j, sum, max, list[27], n;
	int ans1, ans2;

	fscanf(fpr, "%d", &test);
	for (ii = 1;ii <= test;ii++)
	{
		sum = 0;
		fprintf(fpw, "Case #%d:", ii);
		fscanf(fpr, "%d", &n);
		for (i = 0;i < n;i++)
		{
			fscanf(fpr, "%d", &list[i]);
			sum += list[i];
		}
		while (sum > 0)
		{
			for (i = 0, max = 0;i < n;i++)
				if (list[i]>list[max])
					max = i;
			list[max]--;
			sum--;
			ans1 = 'A' + max;
			fprintf(fpw, " %c", ans1);

			for (i = 0, max = 0;i < n;i++)
				if (list[i]>list[max])
					max = i;
			list[max]--;
			sum--;
			for (i = 0;i < n;i++)
				if (((double)list[i] / sum)>0.5)
					break;
			if (i == n)
			{
				ans2 = 'A' + max;
				fprintf(fpw, "%c", ans2);
			}
			else
			{
				list[max]++;
				sum++;
			}
		}
		fprintf(fpw, "\n");
	}


	fclose(fpw);
	fclose(fpr);
	return 0;
}