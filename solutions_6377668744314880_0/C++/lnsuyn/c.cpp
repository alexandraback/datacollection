#include <stdio.h>

long long xx[3010] ,yy[3010] ,x[6010] ,y[6010];
long long x0 ,y0;
long long tempa[3010] ,tempb[3010];
void mergesort(long long *a ,long long *b ,int n1 ,int n2);
int main(void)
{
	int tt ,ii;
	int n ,i ,nn ,j ,j2;
	int ans;
	int p1 ,p2 ,p3;
	int nnnnnn;
	int z;
	
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		scanf("%d" ,&nn);
		n=nn-1;
		for (i=1 ; i<=nn ; i++)	
		{
			scanf("%I64d %I64d" ,&xx[i] ,&yy[i]);
		}
		printf("Case #%d:\n" ,ii);
		for (i=1 ; i<=nn ; i++)
		{
			for (j=1 , j2=1 ; j<i ; j++ , j2++)
			{
				x[j2]=xx[j];
				y[j2]=yy[j];
			}
			for (j=i+1 , j2=j2 ; j<=nn ; j++ , j2++)
			{
				x[j2]=xx[j];
				y[j2]=yy[j];
			}		
			x0=xx[i];
			y0=yy[i];
			mergesort(x,y,1,n);
			for (j=1 ; j<=n ; j++)
			{
				x[j+n]=x[j];
				y[j+n]=y[j];
			}
			ans=1000000000;
			p1=1;
			for (p2=p1+1 ; p2<=n ; p2++)
			{
				z=0;
				if  ((x[p1]-x0)*(y[p2]-y0)!=(y[p1]-y0)*(x[p2]-x0))				
				{
					z=1;	
				}
				else if ((x[p1]-x0)*(x[p2]-x0)<0)
				{
					z=1;
				}
				else if ((y[p1]-y0)*(y[p2]-y0)<0)
				{
					z=1;	
				}
				if (z)
				{
					break;	
				}
			}
			for (p3=p2 ; p3<=n ; p3++)
			{
				z=0;
				if  ((x[p1]-x0)*(y[p3]-y0)>=(y[p1]-y0)*(x[p3]-x0))				
				{
					z=1;	
				}
				if (z)
				{
					break;	
				}				
			}
			if (p3-p2<ans)
			{
				ans=p3-p2;
			}
			nnnnnn=n;
			nnnnnn+=(p2-p1);		
			for (p1=p2 ; p1<=n ; p1=p2)
			{
				for (p2=p1+1 ; p2<=nnnnnn ; p2++)
				{
					z=0;
					if  ((x[p1]-x0)*(y[p2]-y0)!=(y[p1]-y0)*(x[p2]-x0))				
					{
						z=1;	
					}
					else if ((x[p1]-x0)*(x[p2]-x0)<0)
					{
						z=1;
					}
					else if ((y[p1]-y0)*(y[p2]-y0)<0)
					{
						z=1;	
					}
					if (z)
					{
						break;	
					}
				}
				if (p2>p3)
				{
					p3=p2;	
				}
				for (; p3<=nnnnnn ; p3++)
				{
					z=0;
					if  ((x[p1]-x0)*(y[p3]-y0)>=(y[p1]-y0)*(x[p3]-x0))				
					{
						z=1;	
					}
					if (z)
					{
						break;	
					}				
				}
				if (p3-p2<ans)
				{
					ans=p3-p2;
				}
				nnnnnn+=(p2-p1);								
			}
			printf("%d\n" ,ans);
		}
	}
	
	return 0;
}

void mergesort(long long *a ,long long *b ,int n1 ,int n2)
{
	int a1 ,a2 ,n12;
	int i ,j;
	int z;
	
	if (n1<n2)
	{	
		n12=(n1+n2)/2;
		mergesort(a,b,n1,n12);
		mergesort(a,b,n12+1,n2);
		for (i=n1 ; i<=n2 ; i++)
		{
			tempa[i]=a[i];	
			tempb[i]=b[i];
		}
		a1=n1;
		a2=n12+1;
		for (i=n1 ; (a1<=n12 && a2<=n2) ;i++)
		{
			if (tempa[a1]==x0&&tempb[a1]>y0)
			{
				z=1;
			}
			else if (tempa[a2]==x0&&tempb[a2]>y0)
			{
				z=2;
			}			
			else if (tempa[a1]>x0)
			{
				if (tempa[a2]>x0)
				{
					if  ((tempa[a1]-x0)*(tempb[a2]-y0)<=(tempb[a1]-y0)*(tempa[a2]-x0))
					{
						z=1;
					}
					else
					{
						z=2;
					}
				}
				else
				{
					z=1;
				}
			}
			else if (tempa[a1]==x0)
			{
				if (tempa[a2]>x0)
				{
					z=2;
				}
				else
				{
					z=1;
				}				
			}
			else
			{
				if (tempa[a2]>=x0)
				{
					z=2;
				}
				else
				{
					if  ((tempa[a1]-x0)*(tempb[a2]-y0)<=(tempb[a1]-y0)*(tempa[a2]-x0))
					{
						z=1;
					}
					else
					{
						z=2;
					}					
				}				
			}
			if (z==1)
			{
				a[i]=tempa[a1];
				b[i]=tempb[a1];
				a1++;
			}
			else
			{
				a[i]=tempa[a2];
				b[i]=tempb[a2];
				a2++;				
			}
		}
		if (a1>n12)
		{
			for (j=a2 ; j<=n2 ; j++ , i++)
			{
				a[i]=tempa[j];
				b[i]=tempb[j];
			}
		}
		else
		{
			for (j=a1 ; j<=n12 ; j++ , i++)
			{
				a[i]=tempa[j];
				b[i]=tempb[j];
			}			
		}
	}
}
