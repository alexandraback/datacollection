#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int n = 4;
int t, a, b;
int m1[4][4], m2[4][4];
int i, j, k;
int result;
bool h[17];
string PROG = "A-small-attempt4";
FILE *fin, *fout;

int main()
{
	fin = fopen((PROG + ".in").c_str(), "r");
	fout = fopen((PROG + ".out").c_str(), "w");
	
	fscanf(fin, "%d", &t);
	for (k = 1; k <= t; k++)
	{
		fscanf(fin, "%d", &a);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				fscanf(fin, "%d", &m1[i][j]);
			}
		fscanf(fin, "%d", &b);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				fscanf(fin, "%d", &m2[i][j]);
			}
		
		for (i = 1; i <= n * n; i++)
			h[i] = 0;
		for (i = 0; i < n; i++)
			h[m1[a - 1][i]] = 1;
		result = 0;
		j = 0;
		for (i = 0; i < n; i++)
		{
			if (h[m2[b - 1][i]] == 1)
			{
				result++;
				j = m2[b - 1][i];
			}
		}
		
		fprintf(fout, "Case #%d: ", k);
		if (result == 1)
		{
			fprintf(fout, "%d\n", j);
		}
		else if (result == 0)
		{
			fprintf(fout, "Volunteer cheated!\n");
		}
		else
		{
			fprintf(fout, "Bad magician!\n");
		}
	}
	return 0;
}