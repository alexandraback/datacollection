#include <stdio.h>
#include <algorithm>
using namespace std;
int t, n, a[1000];
int main()
{
	FILE *fin = fopen("A.in", "r"), *fout = fopen("A.out", "w");
	fscanf(fin, "%d", &t);
	for(int t_id = 1; t_id <= t; t_id++)
	{
		fscanf(fin, "%d", &n);
		for(int i = 0; i < n; i++)
			fscanf(fin, "%d", &a[i]);
		int sum = 0, maxd = 0, ans = 0;
		for(int i = 1; i < n; i++)
			sum += max(a[i - 1] - a[i], 0);
		for(int i = 1; i < n; i++)
			maxd = max(maxd, a[i - 1] - a[i]);
		for(int i = 0; i + 1 < n; i++)
			ans += min(maxd, a[i]);
		fprintf(fout, "Case #%d: %d %d\n", t_id, sum, ans);
	}
	fclose(fin), fclose(fout);
	return 0;
}
