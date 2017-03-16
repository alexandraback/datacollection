#include<stdio.h>
int main()
{
	freopen("B-small-attempt17.in","r",stdin);
	freopen("B-small-attempt17.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		int n,m,k,out=0;
		scanf("%d%d%d",&n,&m,&k);
		if(n>m)
		{
			int x=n;
			n=m;
			m=x;
		}
		//n<=m already
		if(n==1)
		{
			if(k>(m+1)/2 && k<=m)
				out=2*(k-(m+1)/2);
			else if(k>(m+1)/2 && k>m)
				out=m;
		}
		else if(n==2)
		{
			if(m==2)
			{
				if(k==3)
					out=2;
				else if(k>=4)
					out=4;
			}
			else if(m==3 && k>3)
			{
				if(k==4)
					out=2;
				else if(k==5)
					out=4;
				else if(k>=6)
					out=7;
			}
			else if(m>3 && k>m)
			{
				if(k-m<=2)
					out=2*(k-m);
				else
					out=3*(k-m-2)+4;
			}
		}
		else if(n==3)
		{
			if(m==3 && k>5)
			{
				if(k==6)
					out=3;
				else if(k<9)
					out=2*(k-4);
				else
					out=12;
			}
			else if(m==4 && k>6)
			{
				if(k==7)
					out=2;
				else if(k==8)
					out=4;
				else if(k==9)
					out=8;
				else if(k==10)
					out=10;
				else if(k==11)
					out=13;
				else if(k>=12)
					out=17;
			}
			else if(m==5 && k>8)
			{
				if(k==9)
					out=3;
				else if(k==10)
					out=6;
				else if(k==11)
					out=9;
				else if(k==12)
					out=12;
				else if(k==13)
					out=14;
				else if(k==14)
					out=18;
				else if(k>=15)
					out=22;
			}
		}
		else if(n==4 && k>8)
		{
			if(k==9)
				out=2;
			else if(k==10)
				out=4;
			else if(k==11)
				out=7;
			else if(k==12)
				out=10;
			else if(k==13)
				out=13;
			else if(k==14)
				out=16;
			else if(k==15)
				out=20;
			else if(k==16)
				out=24;
		}
		printf("Case #%d: %d\n",a,out);
	}
}
