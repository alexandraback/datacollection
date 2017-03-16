#include<stdio.h>

int a[300][300];

void fun(int i,int j,int n,int r,int c)
{
	a[i][j]=1;
	if(i+2<c && (n-1))
		fun(i+2,j,n-1,r,c);
	else if(j+1<r && (n-1))
	{
		if(i%2==0)
		{
			if(c!=1)
			fun(1,j+1,n-1,r,c);
			else if(j+2<r)
				fun(0,j+2,n-1,r,c);
			else if(c!=1)
				fun(1,0,n-1,r,c);
			else
				fun(0,1,n-1,r,c);
		}
		else
			fun(0,j+1,n-1,r,c);
	}
	else if(n-1)
	{
		if(a[0][0]==1)
		{
		if(c!=1)
		fun(1,0,n-1,r,c);
		else
		fun(0,1,n-1,r,c);
		}
		else
		fun(0,0,n-1,r,c);
	}
}

int main()
{
	FILE *fp,*fp1;
	
	
	fp=freopen("B-small-attempt3.in","r",stdin);
	fp1=freopen("bf.text","w+",stdout);
	
	int t,count=0,r,c,i,j,n,k;
	
	scanf("%d",&t);
	
	for(k=0;k<t;k++)
	{
		count=0;
		for(i=0;i<260;i++)
			for(j=0;j<260;j++)
				a[i][j]=0;
				
		scanf("%d%d%d",&r,&c,&n);
		if(n)
		{
			if(c%2!=0)
			{
				if(r%2!=0)
					fun(0,0,n,r,c);
				else
					fun(0,1,n,r,c);
			}
			else
			{
				if(r%2!=0)
					fun(1,0,n,r,c);
				else
					fun(1,1,n,r,c);
	 		}
		}
		
		for(i=1;i<c;i++)
			for(j=1;j<r;j++)
			{
				if(a[i][j]==1)
				if(a[i-1][j]!=0)
					count++;
				if(a[i][j]==1)
				if(a[i][j-1]!=0)
					count++;
			}
			
			for(j=1;j<r;j++)
				if(a[0][j]==1)
				if(a[0][j-1]!=0)
					count++;
					
			for(i=1;i<c;i++)
				if(a[i][0]==1)
				if(a[i-1][0]!=0)
					count++;
			
		printf("Case #%d: %ld\n",k+1,count);
	}
	
	fclose(fp);
	fclose(fp1);
}
