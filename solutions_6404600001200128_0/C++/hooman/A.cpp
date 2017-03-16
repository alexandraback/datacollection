#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

int N, m[1000];

int solve1()
{
	int n, sum = 0;
	for(n=1;n<N;n++)
	{
		if(m[n-1]>m[n])
		{
			sum += m[n-1]-m[n];
		}
	}
	return sum;
}

int solve2()
{
	int n, sum = 0, max = 0;
	for(n=1;n<N;n++)
	{
		if(max < m[n-1]-m[n])
		{
			max = m[n-1]-m[n];
		}
	}
	for(n=1;n<N;n++)
	{
		if(max > m[n-1])
		{
			sum += m[n-1];
		}
		else
		{
			sum += max;
		}
	}
	return sum;
}

int main()
{
	FILE *in,*out;
	char line[1000];
	int T, t;
	int i, j;
	in = fopen("A.in","r");
	out = fopen("A.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
		fscanf(in,"%d ",&N);
//		fgets(line,999,in);//empty line
		for(i=0; i<N; i++)
		{
			fscanf(in,"%d ",&m[i]);
		}
		cout <<t<<' '<<solve1()<<' '<<solve2()<<endl;
		fprintf(out, "Case #%d: %d %d\n",t, solve1(), solve2());
	}
	fclose(in);
	fclose(out);
}
