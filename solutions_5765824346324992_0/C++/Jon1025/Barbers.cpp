/*
 * Barbers.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: jonathan
 *
 *      Solves the Barbers problem.
 *
 */

#include <stdio.h>

typedef long long int ll;

ll numhelped(ll minute, ll* barbers, ll j)
{
	ll ans = 0;
	ll i;
	for (i=0;i<j;i++)
	{
		ans += (minute/barbers[i])+1;
	}
	return ans;
}

int main()
{
	FILE* file,*out;
	file = fopen("B-small-attempt0.in","r");
	out = fopen("OutputBsmall.txt","w");
	ll num,i,j,k,ans,q,l,r,n;
	char temp;
	ll* barbers;
	fscanf(file,"%lld",&num);
	for (i=0;i<num;i++)
	{
		fscanf(file,"%lld",&j);
		fscanf(file,"%lld",&n);
		barbers = new ll[j];
		for (k=0;k<j;k++)
		{
			fscanf(file,"%lld",&barbers[k]);
		}
		q = 1;
		while (numhelped(q,barbers,j) < n)
		{
			q = q*10;
		}
		l = 0;
		r = 0;
		while (q > 0)
		{
			if (r%2 == 0)
			{
				while (numhelped(l,barbers,j) < n)
				{
					l += q;
				}
				q = q/10;
			}
			if (r%2 == 1)
			{
				while (numhelped(l,barbers,j) >= n)
				{
					l -= q;
				}
				q = q/10;
			}
			r++;
		}
		if (numhelped(l,barbers,j) < n)
		{
			l++;
		}
		for (k=j-1;k>=0;k--)
		{
			if (l%barbers[k] == 0)
			{
				if (numhelped(l,barbers,j) == n)
				{
					ans = k;
				}
				n++;
			}
		}
		fprintf(out,"Case #%lld: %lld\n",i+1,ans+1);
		delete[] barbers;
	}
}


