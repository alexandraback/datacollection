/* 2014.5.3 Celicath  */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

char line[200][200];
char standard[200];
int nums[200][200];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;

		fscanf(fin, "%d", &N);

		for (int i = 0; i < 200; i++)
		{
			standard[i] = ' ';
			for (int j = 0; j < 200; j++)
				nums[i][j] = 0;
		}

		double pr = 1;
		for (int i = 0; i < N; i++)
			fscanf(fin, "%s", line + i);

		for (int i = 0; i < N; i++)
		{
			char prev = ' ';
			int pos = 0;
			int count = 0;
			for (int j = 0; line[i][j]; j++)
			{
				if (pos != 0)
					nums[i][pos - 1] = count;
				if (line[i][j] != prev)
				{
					if (i == 0)
						standard[pos++] = line[i][j];
					else
					{
						if (standard[pos++] != line[i][j])
							goto hell;
					}
					count = 1;
				}
				else count++;
				prev = line[i][j];
			}
			if (pos != 0)
				nums[i][pos - 1] = count;
			nums[i][pos] = -1;
			if (nums[0][pos] != -1)
				goto hell;
		}
		int result = 0;
		for (int j = 0; nums[0][j] > -1; j++)
		{
			int temp[200];
			for (int k = 1; k <= 100; k++)
				temp[k] = 0;
			for (int i = 0; i < N; i++)
			{
				for (int k = 1; k <= 100; k++)
					temp[k] += std::abs(nums[i][j] - k);
			}
			int min = 2147483647;
			for (int j = 1; j <= 100; j++)
			if (min > temp[j]) min = temp[j];

			result += min;
		}

		fprintf(fout, "Case #%d: %d\n", c_n, result);
		printf("Case #%d: %d\n", c_n, result);
		continue;

		hell:
			fprintf(fout, "Case #%d: Fegla Won\n", c_n, 0);
			printf("Case #%d: Fegla Won\n", c_n, 0);
	}

	return -0;
}
