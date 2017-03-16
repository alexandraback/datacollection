#include <stdio.h>
int check(int a[], int n)
{
	int i, sum=0;
	for(i=0; i<n; i++)
		sum=sum+a[i];
	for(i=0; i<n; i++)
	{
		if(a[i]>sum/2)
			return 0;
	}
	return 1;			
}

int main()
{
	FILE *ifp, *ofp;
	ofp = fopen("/home/dead/Desktop/senateRun1.out","w");
	ifp = fopen("/home/dead/Desktop/A-small-attempt0.in", "r");	
	int t, n, i, k, j=0;
	int sum=0;
	int ans[2]={-1};
	int a[26]={0};
	fscanf(ifp,"%d", &t);
	int q, evac=0;
	for(q=0; q<t; q++)
	{
		fscanf(ifp,"%d", &n);
		for(i=0; i<n; i++)
		{
			fscanf(ifp,"%d", &a[i]);
			sum=sum+a[i];
		}
		fprintf(ofp,"Case #%d: ", q+1);
		while(evac<sum)
		{
			for(i=0; i<n; i++)
			{
				if(a[i]>0)
				{
					a[i]=a[i]-1;
					for(k=i+1; k<n; k++)
					{
						if(a[k]>0)
						{						
							a[k]=a[k]-1;								
							if(check(a, n))
							{	
								ans[0] = i;
								ans[1] = k;
								evac+=2;
								j=1;	break;
							}
							else
								a[k]++;
						}
					}
					if(j==1)	break;
					if(check(a, n))	
					{
						ans[0]=i;
						evac++;
						break;
					}
				}
			}
			fprintf(ofp,"%c", 'A'+ans[0]);
			if(ans[1]>-1)	fprintf(ofp,"%c", 'A'+ans[1]);
			fprintf(ofp," ");
			ans[0]=-1; ans[1]=-1; j=0; 
		}
		fprintf(ofp,"\n");
		evac=0; sum=0;
	}
	fclose(ofp);
	fclose(ifp);
	return 0;
}
