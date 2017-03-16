/*
 * Trees.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: jonathan
 *
 *      Solves the Trees problem
 *
 */

#include <stdio.h>

typedef long long int ll;

int main()
{
	FILE* file,*out;
	file = fopen("C-small-attempt1.in","r");
	out = fopen("OutputCsmall.txt","w");
	ll num,i,j,k,ans,q1,q2,l,r,v1,v2,w1,w2;
	ll n,avx,avy;
	char temp;
	ll* treesx, *treesy;
	fscanf(file,"%lld",&num);
	for (i=0;i<num;i++)
	{
		fscanf(file,"%lld",&j);
		treesx = new ll[j];
		treesy = new ll[j];
		for (k=0;k<j;k++)
		{
			fscanf(file,"%lld",&treesx[k]);
			fscanf(file,"%lld",&treesy[k]);
		}
		if (j > 1)
		{
		fprintf(out,"Case #%lld: \n",i+1);
		for (k=0;k<j;k++)
		{
			w1 = treesx[k];
			w2 = treesy[k];
			for (l=0;l<j;l++)
			{
				treesx[l] -= w1;
				treesy[l] -= w2;
			}
			ans = j;
			for (l=0;l<j;l++)
			{
				if (l != k)
				{
					q1 = 0;
					q2 = 0;
					v1 = -treesy[l];
					v2 = treesx[l];
					for (r=0;r<j;r++)
					{
						if (treesx[r]*v1 + treesy[r]*v2 > 0)
						{
							q1++;
						}
						if (treesx[r]*v1 + treesy[r]*v2 < 0)
						{
							q2++;
						}
					}
					if (q1 < ans)
					{
						ans = q1;
					}
					if (q2 < ans)
					{
						ans = q2;
					}
				}
			}
			fprintf(out,"%lld \n",ans);
			for (l=0;l<j;l++)
			{
				treesx[l] += w1;
				treesy[l] += w2;
			}
		}
		delete[] treesx;
		delete[] treesy;
		}
		else
		{
			fprintf(out,"Case #%lld: \n%d \n",i+1,0);
		}
	}
}
