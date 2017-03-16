#include<stdio.h>
#include<algorithm>
int a[1005],m,n;
struct data
{
	int num,c;
}b[1005];
int find()
{
	int i,j,x=b[0].c,y,z,memx,memy;
	for(i=0;i<m-1;i++)
	{
		y=b[i+1].c;
		memx=x;
		memy=y;
		while(1)
		{
			z=y;
			if(x%y!=0)
				y=x%y;
			else
				break;
			x=z;
		}
		x=memx*memy/y;
	}
	return x;
}
int main()
{
	FILE* fp=freopen("input.txt","r",stdin);
	FILE* fp2=freopen("output.txt","w",stdout);
	int t,i,j,k,mem,sum=0,count=0,check=0,min,memm;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		min=1000000000;
		scanf("%d %d",&m,&n);
		for(j=0;j<m;j++)
		{
			a[j]=0;
			scanf("%d",&b[j].c);
			if(b[j].c<=min)
			{
				min=b[j].c;
				memm=j+1;
			}
			b[j].num=j+1;
		}
		if(n<=m)
			printf("Case #%d: %d\n",i+1,n);
		else
		{
			sum=0;
			mem=find();
			for(j=0;j<m;j++)
				sum+=mem/b[j].c;
			if(n>=sum)
				n%=sum;
			if(n==0)
				printf("Case #%d: %d\n",i+1,memm);
			for(j=0;j<n;)
			{
				for(k=0,check=0;k<m;k++)
					if(a[k]==0)
					{
						check=1;
						a[k]=b[k].c;
						j++;
						if(j==n)
							printf("Case #%d: %d\n",i+1,k+1);
						break;
					}
				for(k=0;k<m&&check==0;k++)
					if(a[k]!=0)
						a[k]--;
			}
		}
	}
	scanf(" ");
}

