#include <stdio.h>


#define MAXB 1100

long a[MAXB], c[MAXB], p[MAXB];
int main()
{
	FILE *infile, *outfile;
	
	infile = fopen("B-small-attempt2.in", "r");
	outfile = fopen("output", "w");
	
	int tt;
	fscanf(infile, "%d\n", &tt);
	for (int ca = 1; ca <= tt; ++ca)
	{
		fprintf(outfile, "Case #%d: ", ca);
		int b;
		long long n, maxb = 0;
		fscanf(infile, "%d %lld\n", &b, &n);
		for (int i = 0; i < b; ++i)
		{
			fscanf(infile, "%ld", &a[i]);
			if (a[i] > maxb) maxb = a[i];
		}
		long long min = 1, max = maxb*n;
		while (min <= max)
		{
			long long mid = (min + max) / 2;
			long long tmp = 0;
			for (int i = 0; i < b; ++i)
			{
				tmp += mid / a[i];
				if (mid % a[i] != 0) ++tmp;
			}
			if (tmp < n - 1) min = mid + 1;
			else if (tmp > n - 1) max = mid - 1;
			else
			{
				max = mid;
				break;
			}
		}
		long long num = 0;
		for (int i = 0; i < b; ++i)
		{
			num += max / a[i];
			if (max % a[i] != 0) ++num;
		}
		for (int i = 0; i < b; ++i) 
		{
			c[i] = (a[i] - max % a[i]) % a[i];
			if (max == 0) c[i] = a[i];
			p[i] = i;
		}
		for (int i = 0; i < b-1; ++i)
		  for (int j = i+1; j < b; ++j)
		    if (c[i] > c[j] || (c[i] == c[j] && p[i] > p[j]))
		    {
		    	long tmp = c[i];c[i] = c[j];c[j] = tmp;
		    	tmp = p[i];p[i] = p[j];p[j] = tmp;
		    }
		    
		fprintf(outfile, "%ld\n", p[n-1-num]+1);
	}
}