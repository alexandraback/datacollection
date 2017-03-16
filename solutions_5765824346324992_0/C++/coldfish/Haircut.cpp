#include <iostream>
#include <algorithm>


#define max(a,b) (a>b) ? a:b

using namespace std;
int func(int num1, int num2)
{
	if (num2 == 0)
		return num1;

	return func(num2, num1%num2);
}
void main()
{
	FILE *fs = fopen("input.txt", "r");
	FILE *fp = fopen("output.txt", "w");

	int testcase;
	fscanf(fs, "%d", &testcase);

	for (int t = 0; t < testcase; t++)
	{
		int nb, nc,min,idx;
		int gcd,maxc=0,gg;
		int barr[100] = { 0 };
		int time[100] = { 0, };
		fscanf(fs, "%d %d", &nb, &nc);
		for (int i = 0; i < nb; i++)
			fscanf(fs, "%d", &barr[i]);
		if (barr[0]>barr[1])
			gcd = func(barr[0], barr[1]);
		else gcd = func(barr[1], barr[0]);
		gg = barr[0] * barr[1] / gcd;
		for (int i = 2; i < nb; i++)
		{
			if (gcd>barr[i])
				gcd = func(gg, barr[i]);
			else
				gcd = func(barr[i], gg);
			gg = gg*barr[i] / gcd;
		}


		for (int i = 0; i < nb; i++)
		{
			maxc += gg / barr[i];
		}
		if (nc > maxc)
		{
			if (nc%maxc > 0)
				nc %= maxc;
			else
				nc = maxc;
		}
		for (int i = 0; i < nc; i++)
		{
			min = time[0];
			idx = 0;
			for (int j = 1; j < nb; j++)
			{
				if (time[j] < min)
				{
					min = time[j];
					idx = j;
				}
			}
			time[idx]+= barr[idx];
		}
		fprintf(fp, "Case #%d: %d\n", t + 1, idx+1);
	}
	fclose(fs);
	fclose(fp);
}