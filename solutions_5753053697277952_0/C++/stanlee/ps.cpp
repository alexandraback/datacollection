#include <cstdio>

FILE *in,*out;

int n,a[30];
int main ()
{
	int T,t;

	in = fopen("input.txt","r");stdin;
	out = fopen ("output.txt","w");

	fscanf (in,"%d",&T);
	for (t=1;t<=T;t++)
	{
		int i,j,s,m,c=0;

		fscanf (in,"%d",&n);
		for (i=0;i<n;i++)
			fscanf (in,"%d",a+i);
		for (i=s=0;i<n;i++)
			s+=a[i];
		fprintf (out,"Case #%d: ",t);
		while (s)
		{
			s--;
			m=-1,j=0;
			for (i=0;i<n;i++)
				if (a[i]>m)
					j=i,m=a[i];
			a[j]--;
			fprintf (out,"%c",j+65);

			for (i=0;i<n;i++)
				if (a[i]>s/2)
					c=1;
			if (c)
			{
				s--;
				m=-1,j=0;
				for (i=0;i<n;i++)
					if (a[i]>m)
						j=i,m=a[i];
				a[j]--;
				fprintf (out,"%c",j+65);
			}
			fprintf (out," ");
		}
		fprintf (out,"\n");
	}

	return 0;
}