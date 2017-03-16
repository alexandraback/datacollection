#include "stdio.h"

#undef SKC

#if 1

#define IN_FILE	"IO/CJ-1.in"

#define P 		printf

int main(void)
{
	int t,tst;

	FILE* fin = stdin;
#ifdef SKC
	fin = fopen(IN_FILE,"r");
	if(fin == NULL)
	{
		printf("Cannot Open file %s\n", IN_FILE);
		return 0;
	}
#endif

	fscanf(fin, "%d", &tst);
	for(t=1 ; t<=tst ; ++t)
	{
		int i,j,res=0;
		int a[4][4], b[4][4],aa,bb;

		fscanf(fin,"%d", &aa);
		for(i=0 ; i<4 ; ++i)
		{
			for(j=0 ; j<4 ; ++j)
				fscanf(fin,"%d", &a[i][j]);
		}

		fscanf(fin,"%d", &bb);
		for(i=0 ; i<4 ; ++i)
		{
			for(j=0 ; j<4 ; ++j)
				fscanf(fin,"%d", &b[i][j]);
		}

		int *pa = a[aa-1];
		int *pb = b[bb-1];
		int c=0;

		for(i=0 ; i<4 ; ++i)
		{
			for(j=0 ; j<4 ; ++j)
			{
				if(pa[i] == pb[j])
				{
					res = pa[i];
					c++;
				}
			}
		}

		P("Case #%d: ", t);
		if(c==0)
			P("Volunteer cheated!\n");
		else if(c>1)
			P("Bad magician!\n");
		else
			P("%d\n",res);
	}

#ifdef SKC
	fclose(fin);
#endif

	return 0;
}

#endif
