#include <stdio.h>
#include <string.h>

#define MAXN 1100

long a[MAXN];

int main()
{
	FILE *infile, *outfile;
	infile = fopen("A-large.in", "r");
	outfile = fopen("output", "w");
	
	int tt;
	fscanf(infile, "%d\n", &tt);
	for (int ca = 1; ca <= tt; ++ca)
	{
		fprintf(outfile, "Case #%d: ", ca);
		int n;
		fscanf(infile, "%d\n", &n);
		memset(a, '\0', sizeof(a));
		long ans1 = 0, ans2 = 0, rate = 0;
		for (int i = 0; i < n; ++i)
		{
		  fscanf(infile, "%ld", &a[i]);
		  if (i > 0 && a[i-1] - a[i] > 0)
		  {
		     ans1 += a[i-1] - a[i];
		     if (a[i-1] - a[i] > rate) rate = a[i-1] - a[i];
		  }
		}
		for (int i = 0; i < n - 1; ++i)
		  if (a[i] < rate) ans2 += a[i];
		  else ans2 += rate;
		
		fprintf(outfile, "%ld %ld\n", ans1, ans2);
	}
}