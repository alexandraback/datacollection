#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LN_LEN 1024

int getselrow(FILE *f)
{
	int row = 0;
	char line[MAX_LN_LEN];
	if (!fgets(line, MAX_LN_LEN - 1, f))
		return -2;
	int ans = atoi(line);
	if ((ans < 1) || (ans > 4))
		return -2;
	int i, j;
	char *p;
	char *e;
	for (i = 1; i <= 4; i++)
	{
		if (!fgets(line, MAX_LN_LEN - 1, f))
			return -2;
		if (i == ans)
		{
			p = line;
			
			for (j = 0; j < 4; j++)
			{
				while (isspace(*p))
					p++;
				int card = strtol(p, &e, 10);
				if ((card < 1) || (card > 16))
					return -2;
				row |= 1 << (card - 1);
				p = e + 1;
			}		
		}
	}
	return row;
}

int solve(FILE *f)
{
	int first = getselrow(f);
	if (first < 1)
		return -2;
	int second = getselrow(f);
	if (second < 1)
		return -2;
	int result = 0;
	int i, b;
	for (i = 1, b = 1; i <= 16; i++, b <<= 1)
	{
		if ((first & b) && (second & b))
		{
			if (result > 0)
				return -1;
			result = i;
		}
	}
	return result;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Invalid number of arguments\n");
		return 1;
	}
	FILE *f = fopen(argv[1], "rt");
	if (f == NULL)
	{
		fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
		return 2;
	}
	FILE *out = stdout;
	if (argc > 2)
	{
		if ((out = fopen(argv[2], "wt")) == NULL)
		{
			fprintf(stderr, "Cannot open output file: %s\n", argv[2]);
			return 3;
		}
	}
	char line[MAX_LN_LEN];
	if (!fgets(line, MAX_LN_LEN - 1, f))
	{
		fprintf(stderr, "Empty input file: %s\n", argv[1]);
		return 4;
	}
	int n = atoi(line);
	if (n < 1)
	{
		fprintf(stderr, "Invalid input file: %s\n", argv[1]);
		return 5;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		int result = solve(f);
		switch (result)
		{
			case -2:
				fprintf(stderr, "Invalid input file: %s\n", argv[1]);
				return 6;
			case -1:
				fprintf(out, "Case #%d: Bad magician!\n", i + 1);
				break;
			case 0:
				fprintf(out, "Case #%d: Volunteer cheated!\n", i + 1);
				break;
			default:
				fprintf(out, "Case #%d: %d\n", i + 1, result);
				break;
		}
			
	}
	fclose(f);
	if (out != stdout)
		fclose(out);
	return 0;
}
