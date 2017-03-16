#include <stdio.h>
#include <istream>
#include <string.h>

#define abs(a,b) a>b? a-b : b-a
int main()
{
	FILE *fs,*fp;
	fs=fopen("input.in","rt");
	fp=fopen("output.out","wt");

	int m,n,j,t;

	fscanf(fs,"%d\n",&m);

	for(int i=0;i<m;i++)
	{
		int al=0,cnt,totalsum=0;
		int Brr[100][100]={0,};
		char Check[100][100]={0,};
		char Arr[100][100]={0,},pre=0;
		fscanf(fs,"%d\n",&n);

		for(j=0;j<n;j++)
		{
			fscanf(fs,"%s",Arr[j]);
			cnt=-1;
			al=strlen(Arr[j]);
			pre=0;
			for(t=0;t<al;t++)
			{
				if(pre!=Arr[j][t])
				{
					pre=Arr[j][t];
					Brr[j][++cnt]++;
					Check[j][cnt]=Arr[j][t];
				}
				else
				{
					Brr[j][cnt]++;
				}
			}
		}
		for(j=0;j<n;j++)
		{
			for(t=j+1;t<n;t++)
			{
				if(strcmp(Check[j],Check[t])!=0)
					break;
			}
			if(t<n)
				break;
		}
		if(j<n)
		{
			fprintf(fp,"Case #%d: Fegla Won\n",i+1);
			continue;
		}

		int sum;
		int max,num;
		for(j=0;j<=cnt;j++)
		{
			sum=0;
			max=10000;
			for(num=1;num<=100;num++)
			{
				for(t=0;t<n;t++)
					sum+=abs(Brr[t][j],num);
				if(sum<max)
					max=sum;
				sum=0;
			}
			totalsum+=max;
		}
		fprintf(fp,"Case #%d: %d\n",i+1,totalsum);
	}

	fclose(fs);
	fclose(fp);
	return 0;
}