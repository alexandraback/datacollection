#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <math.h>

using namespace std;
long long **cells;
long long T,N,R,C;

long long count()
{
	long long cnt;
	long long i,j;
	cnt = 0;
	for (i=0;i<R;i++)
		for (j=0;j<C;j++)
			if (cells[i][j]==1)
			{
				if (i+1<R && cells[i+1][j]==1) cnt++;
				if (j+1<C && cells[i][j+1]==1) cnt++;
			}

	return cnt;
			
}
long long permToCells(long long p)
{
	long long i,j;
	long long k = 1;
	long long cnt = 0;
	int q,r;

	for (i=0;i<R;i++)
		for (j=0;j<C;j++)
		{
			cells[i][j] = (p & k)?1:0;
			if (cells[i][j]==1) cnt++;
			k <<= 1; 
		}
/*		printf("P=%d\n",p);
		for (q=0;q<R;q++)
		{
			for (r=0;r<C;r++)
				printf("%d ",cells[q][r]);
			printf("\n");
		}
*/
	return cnt;
}

int main()
{
    long long i,j,x;
    long long cnt,min;
    long long numPerm;
	int q,r;

    cin >> T;
    
    for (x=0;x<T;x++)
    {

	cin >> R;
	cin >> C;
	cin >> N;

	cells = (long long **)malloc(sizeof(long long*)*R);

	for (i=0;i<R;i++)
		cells[i] = (long long *)malloc(sizeof(long long)*C);

	numPerm = pow(2,R*C);
	min = 10000;
	for (i=0;i<numPerm;i++)
	{
		j=permToCells(i);	
		if (j!=N) continue;
/*
		for (int q=0;q<R;q++)
		{
			for (r=0;r<C;r++)
				printf("%d ",cells[q][r]);
			printf("\n");
		}
*/
		cnt = count();
		if (cnt<min) min=cnt;
	}

	if (min==10000) min = 0;

	printf("Case #%lld: %lld\n",x+1,min);
	for (i=0;i<R;i++)
		free(cells[i]);
	free(cells);
		
    }
}
