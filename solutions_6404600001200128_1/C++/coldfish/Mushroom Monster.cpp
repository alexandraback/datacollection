#include <iostream>
#include <algorithm>


#define max(a,b) (a>b) ? a:b

using namespace std;
void main()
{
	FILE *fs = fopen("input.txt", "r");
	FILE *fp = fopen("output.txt", "w");

	int testcase;
	fscanf(fs, "%d", &testcase);

	for (int t = 0; t < testcase; t++)
	{
		int n;
		long long int first = 0, second = 0;
		int mush[1000] = { 0, };
		int smush[1000];
		int rate;
		fscanf(fs, "%d", &n);
		for (int i = 0; i < n; i++)
		{
			fscanf(fs, "%d", &mush[i]);
			smush[i] = mush[i];
		}
		for (int i = 0; i < n-1; i++)
		{
			if (mush[i]>mush[i + 1])
				first += mush[i] - mush[i + 1];
		}
		for (int i = n - 1; i > 0; i--)
		{
			smush[i] =mush[i-1]- mush[i];
		}
		std::sort(smush+1, smush + n);
		std::reverse(smush+1, smush + n);
		rate = max(smush[1] ,0);
		for (int i = 0; i < n-1; i++)
		{
			if (rate>mush[i])
				second += mush[i];
			else
				second += rate;
		}
		fprintf(fp, "Case #%d: %lld %lld\n", t + 1,first,second);
	}
	fclose(fs);
	fclose(fp);
}