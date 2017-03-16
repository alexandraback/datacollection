#if 0==0

#include<stdio.h>
#include<vector>
#include<algorithm>

using std::vector;

int best;

int r, c, n, t, u;

int map[20][20];

void search(int k)
{
	if (k == r * c)
	{
		int s = 0;
		for (int i = 1 ; i <= r ; i++)
			for (int j = 1 ; j <= c ; j++)
			{
				if (map[i][j] && map[i][j+1]) s++;
				if (map[i][j] && map[i+1][j]) s++;
			}
		if (s < best) best = s;
	} else
	{
		map[k / c + 1][k % c + 1] = 0;

		if (t - k - 1 >= n - u)
			search(k + 1);

		map[k / c + 1][k % c + 1] = 1;
		u++;
		if (u <= n)
			search(k + 1);
		u--;
	}
}

int main()
{
	vector<int> p;
	FILE *i_fileOut;
	fopen_s(&i_fileOut, "R1B_B.out", "w");
	int i_numCases;
	scanf("%d", &i_numCases);
	for (int i_case = 1 ; i_case <= i_numCases ; i_case++)
	{		

		scanf("%d%d%d", &r, &c, &n);

		best = r * c * 10;

		for (int i = 0 ; i <= r + 1 ; i++)
			for (int j = 0 ; j <= c + 1 ; j++)
				map[i][j] = 0;

		t = r * c;
		u = 0;

		search(0);

		printf("Case #%d: ", i_case);
		fprintf(i_fileOut, "Case #%d: ", i_case);

		printf("%d\n", best);
		fprintf(i_fileOut, "%d\n", best);
	}

	fclose(i_fileOut);
	return 0;
}

#endif