#include "stdio.h"
#include "iostream"

int t,n;
int an,temp,ab;
char a[100][101];
int pa[100],ta[100],d[100];
char ct;

int pai(int n)
{
	int pos;
	int min,temp;
	for(int i=0;i<n;i++)
	{
		pos=i;min=d[i];
		for(int j=i;j<n;j++)
		{
			if (d[j]<min){pos=j;min=d[j];}
		}
		if(pos!=i){temp=d[i];d[i]=d[pos];d[pos]=temp;}
	}
	return 0;
}

int main()
{
	FILE * finp;
	FILE * foutp;


	finp=fopen("A-large.in","r");
	foutp=fopen("1.out","w");

	fscanf(finp,"%d",&t);

	for(int i=0;i<t;i++)
	{
		an=0;ab=1;
		fscanf(finp,"%d",&n);
		for(int j=0;j<n;j++){fscanf(finp,"%s",a[j]);pa[j]=0;ta[j]=0;}
		while(ct=a[0][pa[0]])
		{
			for(int j=0;j<n;j++)
			{
				if(a[j][pa[j]]!=ct) {ab=0;break;}
				while(a[j][pa[j]]==ct) pa[j]++;
				d[j]=pa[j]-ta[j];
				ta[j]=pa[j];
			}
			pai(n);
			for(int j=0;j<n;j++)
			{
				temp=n/2;
				if(j<temp)an+=d[temp]-d[j];
				else an+=d[j]-d[temp];
			}
		}
		for(int j=0;j<n;j++)
			{
				if(a[j][pa[j]]!=0)
				{ab=0;break;}
			}

		if(ab) fprintf(foutp,"Case #%d: %d\n",i+1,an);
		else fprintf(foutp,"Case #%d: Fegla Won\n",i+1);
	}

	fclose(finp);
	fclose(foutp);

	return 0;
}
