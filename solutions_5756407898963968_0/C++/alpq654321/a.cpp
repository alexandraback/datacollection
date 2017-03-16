#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int v[20],A,B,ans,X,T,Time,i,j;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&A);
		for (i=1; i<=16; i++) v[i]=0;
		for (i=1; i<=4; i++)
		  for (j=1; j<=4; j++)
		  {
				scanf("%d",&B);
				if (i==A) v[B]++;
		  }
		scanf("%d",&A);
		for (i=1; i<=4; i++)
		  for (j=1; j<=4; j++)
		  {
				scanf("%d",&B);
				if (i==A) v[B]++;
		  }
		ans=0; X=0;
		for (i=1; i<=16; i++)
		{
			if (v[i]==2) {ans++; X=i;} 
		}
		Time++;
		if (ans==0) printf("Case #%d: Volunteer cheated!\n",Time); else
		  if (ans>=2) printf("Case #%d: Bad magician!\n",Time); else
		    printf("Case #%d: %d\n",Time,X);
	}
	return 0;
} 
