#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

char red[10000000];

int main()

{
	FILE *fi,*fo;
	

	
	int c[300];
	char ci;
	
	int i,j,t,tt;
	
	long long n,tot,ttot,zaredom,maks,total,count;
	
	bool seen[10],all;
	
	fi=fopen("A.in","r");
	fo=fopen("A.out","w");
	
	fscanf(fi,"%d\n",&t);
	
	
	for (tt=0;tt<t;tt++)
	{	
		
		fscanf(fi,"%lld",&n);
		tot=0;
		for (i=0;i<n;i++) fscanf(fi,"%d",&c[i]);
		fprintf(fo,"Case #%d:",tt+1);
		while (1)
		{	
			
			int sum=0;
			
			for (i=0;i<n;i++) sum+=c[i];
			for (i=0;i<n;i++)
			{
				if (c[i]*2>sum) printf("%c with %d has abs majority from %d\n",i+'A',c[i],sum);
			}
			
			int max=0,cnt=0;
			for (i=0;i<n;i++) if (max<c[i]) max=c[i];
			for (i=0;i<n;i++) if (max==c[i]) cnt++;
			if (max==0) break;
			fprintf(fo," ");
			if (cnt==2)
			{
				for (i=0;i<n;i++) if (max==c[i])
				{
					fprintf(fo,"%c",i+'A');
					c[i]--;
				}
				
			}
			else
			{
				for (i=0;i<n;i++) if (max==c[i])
				{
					fprintf(fo,"%c", i+'A');
					c[i]--;
					break;
				}	
			}
		}
		fprintf(fo,"\n");
		//if (count>10000) fprintf(fo,"Case #%d: INSOMNIA\n",tt+1);
		//else fprintf(fo,"Case #%d: %lld\n",tt+1,tot);
	}
	
	fclose(fi);
	fclose(fo);

	return 0;
}
