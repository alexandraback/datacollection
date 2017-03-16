#include "stdio.h"
#include "iostream"


int main()
{
	FILE * finp;
	FILE * foutp;

	int t,n;
	int an,temp,ab;
	char a[101];
	char b[101];
	int pa,pb;
	int ta,tb;
	char ct;
	finp=fopen("A-small-attempt0.in","r");
	foutp=fopen("1.out","w");

	fscanf(finp,"%d",&t);

	for(int i=0;i<t;i++)
	{
		an=0;pa=0;pb=0;ta=0;tb=0;ab=1;
		fscanf(finp,"%d",&n);
		fscanf(finp,"%s",a);
		fscanf(finp,"%s",b);
		while(ct=a[pa])
		{
			while(a[pa]==ct)pa++;
			if (b[pb]!=ct){ab=0;break;}
			while(b[pb]==ct)pb++;
			temp=(pb-tb)-(pa-ta);
			an+=(temp>0?temp:(-temp));
			ta=pa;tb=pb;
		}
		if (b[pb]!=0)ab=0;
		if(ab) fprintf(foutp,"Case #%d: %d\n",i+1,an);
		else fprintf(foutp,"Case #%d: Fegla Won\n",i+1);
	}

	fclose(finp);
	fclose(foutp);

	return 0;
}
