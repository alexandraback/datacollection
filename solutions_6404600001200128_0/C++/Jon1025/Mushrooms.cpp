/*
 * Mushrooms.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: jonathan
 *
 *      Solves the mushrooms problem.
 *
 */

#include <stdio.h>

typedef long long int ll;

int main()
{
	FILE* file,*out;
	file = fopen("A-small-attempt0.in","r");
	out = fopen("OutputAsmall.txt","w");
	ll num,i,j,k,ans1,ans2,q,l,r,n;
	char temp;
	ll* mushnums;
	fscanf(file,"%lld",&num);
	for (i=0;i<num;i++)
	{
		fscanf(file,"%lld",&j);
		mushnums = new ll[j];
		for (k=0;k<j;k++)
		{
			fscanf(file,"%lld",&mushnums[k]);
		}
		ans1 = 0;
		q = 0;
		for (k=0;k<j-1;k++)
		{
			if (mushnums[k] > mushnums[k+1])
			{
				ans1 += mushnums[k] - mushnums[k+1];
				if (mushnums[k] - mushnums[k+1] > q)
				{
					q = mushnums[k] - mushnums[k+1];
				}
			}
		}
		ans2 = 0;
		for (k=0;k<j-1;k++)
		{
			if (mushnums[k] > q)
			{
				ans2 += q;
			}
			else
			{
				ans2 += mushnums[k];
			}
		}
		fprintf(out,"Case #%lld: %lld %lld\n",i+1,ans1,ans2);
		delete[] mushnums;
	}
}


