#include<stdio.h>
void scan(int t,FILE *fo,FILE *fi);
int main()
{
	int t,i;
	FILE *fi,*fo;
	fi=fopen("A-small-practice.in","r");
	fo=fopen("A-small-practice.out","a");
	fscanf(fi,"%d",&t);
	for(i=1;i<t+1;i++)
		scan(i,fo,fi);
	return 0;
}

void scan(int t,FILE *fo,FILE *fi)
{
	int i,j,k,a1,a[4],a2,b[4],gar;
	
	fscanf(fi,"%d",&a1);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(i==a1-1)
				fscanf(fi,"%d",&a[j]);
			else
				fscanf(fi,"%d",&gar);
	
	fscanf(fi,"%d",&a2);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(i==a2-1)
				fscanf(fi,"%d",&b[j]);
			else
				fscanf(fi,"%d",&gar);

	gar=0;
	
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(a[i]==b[j])
			{
				gar++;
				k=a[i];
			}
	if(gar==0)
		fprintf(fo,"Case #%d: Volunteer Cheated!\n",t);
	else if(gar==1)
		fprintf(fo,"Case #%d: %d\n",t,k);
	else
		fprintf(fo,"Case #%d: Bad Magician!\n",t);
}