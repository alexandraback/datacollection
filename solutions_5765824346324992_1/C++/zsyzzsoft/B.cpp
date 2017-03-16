#include <stdio.h>
int t, n, m, a[1000], b[1000];
int main()
{
	FILE *fin = fopen("B.in", "r"), *fout = fopen("B.out", "w");
	fscanf(fin, "%d", &t);
	for(int t_id = 1; t_id <= t; t_id++)
	{
		fscanf(fin, "%d%d", &n, &m), m--;
		for(int i = 0; i < n; i++)
			fscanf(fin, "%d", &a[i]);
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			int l = 0, r = m;
			while(l < r)
			{
				int mid = (l + r + 1) / 2;
				long long sum = mid;
				for(int j = i + 1; j < n; j++)
					sum += ((long long)(mid - 1) * a[i] + a[j] - 1) / a[j];
				if(m >= sum)
					l = mid;
				else
					r = mid - 1;
			}
			m -= b[i] = l;
		}
		for(int i = 1; i < n; i++)
		{
			if((long long)b[i] * a[i] < (long long)b[ans] * a[ans])
				ans = i;
		}
		fprintf(fout, "Case #%d: %d\n", t_id, ans + 1);
	}
	fclose(fin), fclose(fout);
	return 0;
}
